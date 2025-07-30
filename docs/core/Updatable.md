# Updatable
The interface that defines a standard
lifecycle hook for all game objects that require per-frame logic updates.

```c++
class Updatable;
```

Implementing classes must define the `onUpdate()` method,
which is automatically called once per frame by the game engine,
providing a consistent and centralized way to update game logic over time.

---

## Requirements
Below is a list of methods that must be implemented to
conform to the [Updatable](Updatable.md) interface.

### onUpdate()

```c++
virtual void onUpdate(float interval);
```

Called once per frame to update the object’s internal logic.
This is the primary method for time-based logic such as movement,
AI decisions, countdown timers, or animations.

**Parameters:**

- interval: Time, in seconds, elapsed since the last frame.

---

## Relationships
Below is the position of [Updatable](Updatable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[GameObject](Interactable.md) <br>
[Scene](Scene.md) <br>
[Animation](Animation.md) <br>
[State](State.md) <br>
[FiniteStateMachine](FiniteStateMachine.md) <br>
[View](../ui/View.md) <br>
[Timer](Timer.md)