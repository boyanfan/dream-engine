# Renderable
The standard interface for objects that can be rendered
through a [Camera](Camera.md).

```c++
class Renderable;
```

Classes that conform to this interface must implement the
`onRender()` method to define how they should be drawn
on screen through a given camera view.

## Requirements
Below is a list of methods that must be implemented to
conform to the [Renderable](Renderable.md) interface.

### onRender()

```c++
virtual void onRender(const Camera& camera) const;
```

Defines how the object should be rendered through the
given camera instance.

**Parameters:**
- `camera`: The [Camera](Camera.md) that handles coordinate translation, parallax, and other visual effects.

---

## Relationships
Below is the position of [Renderable](Renderable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[GameObject](GameObject.md) <br>
[Scene](Scene.md) <br>
[VideoDecoder](VideoDecoder.md)

### See Also 
[Camera](Camera.md)
