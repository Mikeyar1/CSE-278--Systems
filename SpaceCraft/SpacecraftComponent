// Base class for all spacecraft components. Defines a common interface for activation, deactivation, and status reporting.
class SpacecraftComponent {
public:
    virtual void activate() = 0; // Activates the component.
    virtual void deactivate() = 0; // Deactivates the component.
    virtual void statusReport() const = 0; // Prints a status report of the component.
    virtual ~SpacecraftComponent() {} // Virtual destructor to ensure proper cleanup of derived classes.
};
