# Renderable
The standard interface for objects that can be rendered 
with an SDL renderer.

```c++
class Renderable;
```

Classes that confirm to it must implement the 
`onRender()` method to define how they should be drawn 
on screen.

## Methods
Below is a list of methods that must be implemented to
conform to the [Renderable](Renderable.md) interface.

### onRender()

```c++
virtual void onRender(SDL_Renderer* renderer);
```

Defines how the object should be rendered using the 
given SDL renderer.

**Parameters:**
- `renderer`: The SDL renderer used to draw the object.

**Notes:**
- This is a pure virtual function and must be implemented by all derived classes.
- Typically called once per frame during the rendering phase.

---

## Relationships
Below is the position of [Renderable](Renderable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[VideoDecoder](VideoDecoder.md)