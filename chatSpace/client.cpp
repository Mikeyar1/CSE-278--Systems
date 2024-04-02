#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <array>
#include <csignal>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

constexpr int MaxLen = 200;
constexpr int NumColors = 6;
const std::array<std::string, NumColors> Colors = {{"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m"}};
const std::string DefaultColor = "\033[0m";

std::unique_ptr<std::thread> threadSend, threadReceive;
int clientSocket;
volatile bool exitFlag = false;

void handleCtrlC(int signal);
std::string getColor(int code);
void eraseText(int count);
void sendMessage();
void receiveMessage();
void setupConnection();

int main() {
    setupConnection();

    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    send(clientSocket, name.c_str(), name.size(), 0);

    std::cout << Colors.back() << "\n\t  ====== Welcome to the chat-room ======   " << std::endl << DefaultColor;

    threadSend = std::make_unique<std::thread>(sendMessage);
    threadReceive = std::make_unique<std::thread>(receiveMessage);

    threadSend->join();
    threadReceive->join();

    return 0;
}

void setupConnection() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("socket");
        exit(-1);
    }

    sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(10000); // Server's port number
    client.sin_addr.s_addr = INADDR_ANY;
    std::memset(&client.sin_zero, 0, sizeof(client.sin_zero));

    if (connect(clientSocket, (struct sockaddr*)&client, sizeof(client)) == -1) {
        perror("connect");
        exit(-1);
    }

    std::signal(SIGINT, handleCtrlC);
}

void handleCtrlC(int signal) {
    const char* str = "#exit";
    send(clientSocket, str, strlen(str), 0);
    exitFlag = true;
    if (threadSend) threadSend->detach();
    if (threadReceive) threadReceive->detach();
    close(clientSocket);
    exit(signal);
}

std::string getColor(int code) {
    return Colors[code % NumColors];
}

void eraseText(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << '\b';
    }
}

void sendMessage() {
    while (!exitFlag) {
        std::cout << Colors[1] << "You: " << DefaultColor;
        std::string str;
        std::getline(std::cin, str);
        send(clientSocket, str.c_str(), str.size(), 0);
        if (str == "#exit") {
            exitFlag = true;
            if (threadReceive) threadReceive->detach();
            close(clientSocket);
            return;
        }
    }
}

void receiveMessage() {
    while (!exitFlag) {
        char name[MaxLen], str[MaxLen];
        int colorCode;
        int bytesReceived = recv(clientSocket, name, sizeof(name), 0);
        if (bytesReceived <= 0) continue;
        recv(clientSocket, &colorCode, sizeof(colorCode), 0);
        recv(clientSocket, str, sizeof(str), 0);
        eraseText(6);
        if (strcmp(name, "#NULL") != 0)
            std::cout << getColor(colorCode) << name << ": " << DefaultColor << str << std::endl;
        else
            std::cout << getColor(colorCode) << str << std::endl;
        std::cout << Colors[1] << "You: " << DefaultColor;
        std::fflush(stdout);
    }
}
