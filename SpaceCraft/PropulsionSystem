// Manages the propulsion system of the spacecraft, including engines and fuel.
class PropulsionSystem : public SpacecraftComponent {
private:
    double fuelLevel; // Current fuel level as a percentage.
    bool isActive; // Indicates whether the propulsion system is active.

public:
    PropulsionSystem() : fuelLevel(100.0), isActive(false) {}

    void activate() override {
        isActive = true;
        // Additional logic to start propulsion system.
    }

    void deactivate() override {
        isActive = false;
        // Additional logic to stop propulsion system.
    }

    void statusReport() const override {
        std::cout << "Propulsion System - Fuel Level: " << fuelLevel << "%, Active: " << isActive << std::endl;
    }

    // Refuels the propulsion system.
    void refuel(double amount) {
        fuelLevel = std::min(100.0, fuelLevel + amount);
    }
};

// Handles navigation for the spacecraft, including tracking and course adjustments.
class NavigationSystem : public SpacecraftComponent {
private:
    double currentLatitude; // Current latitude of the spacecraft.
    double currentLongitude; // Current longitude of the spacecraft.

public:
    NavigationSystem() : currentLatitude(0.0), currentLongitude(0.0) {}

    void activate() override {
        // Logic to activate navigation.
    }

    void deactivate() override {
        // Logic to deactivate navigation.
    }

    void statusReport() const override {
        std::cout << "Navigation System - Current Location: " << currentLatitude << ", " << currentLongitude << std::endl;
    }

    // Updates the spacecraft's position.
    void updatePosition(double latitude, double longitude) {
        currentLatitude = latitude;
        currentLongitude = longitude;
    }
};
