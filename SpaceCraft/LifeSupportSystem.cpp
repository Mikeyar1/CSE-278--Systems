// Ensures the habitability of the spacecraft by controlling the environment and life support systems.
class LifeSupportSystem : public SpacecraftComponent {
    // Implementation similar to the above components.
    // This system would manage air quality, temperature, water recycling, etc.
};

// Represents the spacecraft itself, containing all subsystems and managing their operations.
class Spacecraft {
private:
    PropulsionSystem propulsion;
    NavigationSystem navigation;
    CommunicationSystem communication;
    LifeSupportSystem lifeSupport;
    // Other systems and components as needed.

public:
    // Activates all systems of the spacecraft for launch.
    void launch() {
        propulsion.activate();
        navigation.activate();
        communication.activate();
        lifeSupport.activate();
        // Activate other systems.
    }

    // Deactivates all systems upon landing or when needed.
    void land() {
        propulsion.deactivate();
        navigation.deactivate();
        communication.deactivate();
        lifeSupport.deactivate();
        // Deactivate other systems.
    }

    // Generates a comprehensive status report for the spacecraft.
    void statusReport() const {
        propulsion.statusReport();
        navigation.statusReport();
        communication.statusReport();
        lifeSupport.statusReport();
        // Report status of other systems.
    }
};
