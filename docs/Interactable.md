# Interactable

The standard interface for all objects that can 
respond to SDL events, such as user input from the keyboard, 
mouse, or game controller.

```c++
class Interactable;
```

This interface is designed to be inherited by any object 
that needs to handle user interactions. It ensures that 
all interactable components implement a consistent event 
handling method.

---

## Requirements
Below is a list of methods that must be implemented to
conform to the [Interactable](Interactable.md) interface.

### onEvent()

```c++
virtual void onEvent(const SDL_Event& event);
```

Handles SDL events, such as keyboard input, mouse actions, or window interactions.

**Parameters:**
- `event`: The SDL event object to be handled by the scene.

---

## Relationships
Below is the position of [Interactable](Interactable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[GameObject](GameObject.md) <br>
[Scene](Scene.md)