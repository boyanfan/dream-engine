# GeometryProxy

The [GeometryProxy](GeometryProxy.md) struct is a 
utility class that provides access to the geometry 
of an `SDL_Window`, including its position and size. 

```c++
struct GeometryProxy;
```

This class serves as a proxy after window creation, 
making it easier to retrieve or work with the window layout.

---

## Methods
Below is a list and explanation of all public methods
provided by the [GeometryProxy](GeometryProxy.md) class.

### Constructors

```c++
GeometryProxy();
```
Default constructor. Constructs an unbound geometry proxy.

```c++
explicit GeometryProxy(SDL_Window* window);
```
Constructs a geometry proxy and immediately binds it to the provided SDL window.

**Parameter:**
- `window`: The window to capture its geometry.

### Destructor

```c++
~GeometryProxy();
```
Default destructor.

### bind()

```c++
void bind(SDL_Window* window);
```
Binds the proxy to an existing SDL window and updates the geometry cache.

**Parameter:**
- `window`: The window to capture its geometry.


### getWindowPosition()

```c++
Vector2 getWindowPosition() const;
```
Returns the current position of the window on the screen.

**Returns:** A [Vector2](Vector2.md) containing the X and Y coordinates of the top-left corner of the window.


### getWindowSize()
```c++
Vector2 getWindowSize() const;
```
Returns the current size of the window.

**Returns:** A [Vector2](Vector2.md) containing the width and height of the window in pixels.


### getWindowCenter()
```c++
Vector2 getWindowCenter() const;
```
Returns the center point of the window.

**Returns:** A [Vector2](Vector2.md) representing the center coordinates of the window.

## Reflection

The [GeometryProxy](GeometryProxy.md) class provides basic
reflection by storing its own class name, which can be
accessed via `GeometryProxy::self`.

## Relationships
Below is the position of [GeometryProxy](GeometryProxy.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[Vector2](Vector2.md)