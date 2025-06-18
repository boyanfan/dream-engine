# Updatable
The [Updatable](Updatable.md) interface defines a standard
lifecycle hook for all game objects that require per-frame logic updates.
This includes dynamic entities like players, enemies, timers, and UI components.

```c++
class Updatable;
```

Implementing classes must define the `onUpdate()` method,
which is automatically called once per frame by the game engine,
providing a consistent and centralized way to update game logic over time.

---

## Methods
Below is a list of methods that must be implemented to
conform to the [Updatable](Updatable.md) interface.

### onUpdate()

```c++
void onUpdate(float interval);
```

Called once per frame to update the object’s internal logic.
This is the primary method for time-based logic such as movement,
AI decisions, countdown timers, or animations.

**Parameters:**

- interval: Time, in seconds, elapsed since the last frame.

**Notes:**
All classes that inherit from Updatable must implement `onUpdate()`.
This interface is especially useful when:
- You want a consistent update mechanism across different object types.
- You want to decouple logic updates from rendering or input handling.
- You aim to group and iterate all updatable objects in a scene or system.

---

## Relationships
Below is the position of [Updatable](Updatable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[Timer](Timer.md)