# GeometryProxy

A proxy type that provides access to the geometry 
of an `SDL_Window`, including its position, size, and center point. 

```c++
struct GeometryProxy;
```

It serves as a proxy after window creation, 
making it easier to retrieve or work with the window layout.

---

## Methods
Below is a list and explanation of all public methods
provided by the [GeometryProxy](GeometryProxy.md) type.

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

**Returns:** T
The current position of the window on the screen as a 
[Vector2](Vector2.md) that contains the coordinates of 
the top-left corner.


### getWindowSize()

```c++
Vector2 getWindowSize() const;
```

**Returns:** 
The current size of the window as a [Vector2](Vector2.md) 
that contains the width and height of the window in pixels.


### getWindowCenter()

```c++
Vector2 getWindowCenter() const;
```

**Returns:** 
The center point of the window as a [Vector2](Vector2.md).

---

## Relationships
Below is the position of [GeometryProxy](GeometryProxy.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[Vector2](Vector2.md)