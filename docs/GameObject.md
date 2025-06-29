# GameObject

The standard interface for any interactive entity within the game world 
that can be updated, rendered, and respond to events.

```c++
class GameObject : public Updatable, public Renderable, public Identifiable<std::string>;
```

Conforming to the [GameObject](GameObject.md) interface 
also requires implementing the [Renderable](Renderable.md), 
[Updatable](Updatable.md), and [Identifiable\<ID\>](Identifiable.md) interfaces, which define 
rendering and game logic update behavior.

---

## Requirements
Below is a list of methods that must be implemented to
conform to the [GameObject](GameObject.md) interface.

### onEvent()

```c++
virtual void onEvent(const SDL_Event& event);
```

Handles SDL events, such as keyboard input, mouse actions, or window interactions.

**Parameters:**
- `event`: The SDL event object to be handled by the scene.

---

## Relationships
Below is the position of [GameObject](GameObject.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Updatable](Updatable.md) <br>
[Renderable](Renderable.md) <br>
[Identifiable\<ID\>](Identifiable.md)

### Conforming Types
[Scene](Scene.md)