# View

The standard interface for a UI component that occupies a 
rectangular space and supports rendering and updating behavior.

```c++
class View : public Updatable, public Renderable;
```

Confirming to the [View](View.md) interface also requires 
implementing [Updatable](../core/Updatable.md) and
[Renderable](../core/Renderable.md) interfaces to
participate in the update loop and enable drawing to the screen.

**Fields:**
- `SDL_FRect frame`: The rectangular area of the view, using floating-point coordinates.
- `bool isVisible`: A flag indicating whether the view is visible.

---

## Relationships
Below is the position of [View](View.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[BarView](BarView.md)

### Confirms To
[Updatable](../core/Updatable.md) <br>
[Renderable](../core/Renderable.md)
