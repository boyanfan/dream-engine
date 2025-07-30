# Camera
A 2D camera that supports virtual resolution rendering, 
parallax effects, and optional target following
with inertia smoothing.

```c++
class Camera : public Observer<Transform>, public Updatable;
```

The camera only follows an `Observable<Transform>` object,
see [Observable\<T\>](Observable.md) documentation,
and be registered as an [Observer](Observer.md).
The target must call `notify()` whenever its 
[Transform](Transform.md) changes.

**Fields:**
- `bool isVirtualResolution`: Whether virtual resolution rendering is enabled.
- `Vector2 virtualResolution`: The resolution to use when virtual rendering is enabled.
- `Transform transform`: The current [Transform](Transform.md) of the camera.

---

## Methods

Below is a list and explanation of all public methods
provided by the [Camera](Camera.md) class.

### Constructor

```c++
Camera(SDL_Renderer* renderer);
```
Constructs a Camera using the given SDL renderer.

**Parameters:**
- `renderer`: The `SDL_Renderer` to use for rendering.

### Destructor 

```c++
~Camera() override;
```

Default destructor.

### renderTexture()

```c++
void renderTexture(SDL_Texture* texture, const SDL_FRect* source, const SDL_FRect* destination, float parallex) const;
```

Renders a texture using camera's position and optional parallax effect.

**Parameters:**
- `texture`: The SDL_Texture to render.
- `source`: The source rectangle from the texture.
- `destination`: The destination rectangle on screen.
- `parallex`: The parallax scrolling factor. Larger than 1.0f if the object moves faster than the camera, smaller if the object moves slower than the camera.

### getRenderer()

```c++
SDL_Renderer* getRenderer() const;
```

Note that if any content is directly drawn on the screen 
via the renderer instead of the camera, call
`convertCoordinateFromWorldToScreen()` to convert the 
coordinate from the world space to the screen space.

**return:** A pointer to the `SDL_Renderer` used by the camera.

### convertCoordinateFromWorldToScreen()

```c++
SDL_FRect convertCoordinateFromWorldToScreen(const SDL_FRect* destination, float parallex) const;
```

Converts from the world space coordinate to the screen space 
coordinate. Call this method if the content is directly
drawn on the screen via the `SDL_Renderer` instead of the camera,
which requires the proper coordinate conversion.

**Parameters:**

- `destination`: The destination rectangle on screen.
- `parallex`: The parallax scrolling factor. Larger than 1.0f if the object moves faster than the camera, smaller if the object moves slower than the camera.

**Returns:** The screen space rectangle to render to.

### enableVirtualResolution()

```c++
void enableVirtualResolution(const Vector2& resolution);
```

Enables virtual resolution rendering for pixel-perfect 
rendering or scaling.

**Parameters:**
- `resolution`: A [Vector2](Vector2.md) represents virtual resolution to render within.

### disableVirtualResolution()

```c++
void disableVirtualResolution();
```

Disables virtual resolution rendering and restores native 
resolution.

### enableTargetFollowing()

```c++
void enableTargetFollowing(const Transform& target, float inertia);
```

Enables following a target with optional inertia smoothing.

**Parameters:**
- `target`: The target's [Transform](Transform.md) to follow.
- `inertia`: The smoothing inertia for movement.

### onUpdate()

```c++
void onUpdate(float interval) override;
```

Updates the camera logic, including following movement if enabled.

**Parameters:**
- `interval`: The time passed since the last update in seconds.

---

## Relationships
Below is the position of [Camera](Camera.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Observer\<T\>](Observer.md) <br>
[Updatable](Updatable.md)

### See Also
[Observable\<T\>](Observable.md) <br>
[Transform](Transform.md) <br>
[GeometryProxy](GeometryProxy.md) <br>
[Vector2](Vector2.md)