class CommunicationSystem : public SpacecraftComponent {
private:
    bool isActive; // Indicates whether the communication system is active.

public:
    CommunicationSystem() : isActive(false) {}

    void activate() override {
        isActive = true;
        // Logic to start communication.
    }

    void deactivate() override {
        isActive = false;
        // Logic to stop communication.
    }

    void statusReport() const override {
        std::cout << "Communication System - Active: " << isActive << std::endl;
    }

    // Sends a message from the spacecraft.
    void sendMessage(const std::string& message) {
        if (isActive) {
            std::cout << "Sending message: " << message << std::endl;
        } else {
            std::cout << "Communication system is not active." << std::endl;
        }
    }
};
