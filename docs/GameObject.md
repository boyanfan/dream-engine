# GameObject

It defines the base abstraction for all entities that exist 
in the game world with a position, can respond to input, 
be updated every frame, and be rendered on screen.

```c++
class GameObject : public Interactable, public Updatable, public Renderable;
```

Conforming to the [GameObject](GameObject.md) interface
also requires implementing the [Interactable](Interactable.md),
[Updatable](Updatable.md), and [Renderable](Renderable.md) interfaces to
respond to SDL events, support per-frame logic updates, and
provide a way to be drawn onto the screen.

**Fields:**
- `Vector2 position`: The position of the game object in world space coordinate.

---

## Relationships
Below is the position of [GameObject](GameObject.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[Scene](Scene.md)