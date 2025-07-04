# GameObject

It defines the base abstraction for all entities that exist 
in the game world with a [Transform](Transform.md) component, can respond to input, 
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
- `Transform transform`: A 2D [Transform](Transform.md) component used for positioning and orienting entities in the world or local space.

---

## Relationships
Below is the position of [GameObject](GameObject.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Confirms To
[Interactable](Interactable.md) <br>
[Updatable](Updatable.md) <br>
[Renderable](Renderable.md)

### Conforming Types
[Scene](Scene.md)

### See Also
[Transform](Transform.md)