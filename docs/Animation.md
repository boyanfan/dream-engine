# Animation

It represents a texture-sequence-based animation, 
supports time-based frame switching, rendering
with parallax and flipping.

```c++
class Animation final : public Renderable, public Updatable;
```

It implements [Updatable](Updatable.md) and [Renderable](Renderable.md) interfaces
to support per-frame logic updates and
provide a way to be drawn onto the screen.

**Fields:**
- `Transform transform`: A 2D [Transform](Transform.md) component used for positioning and orienting entities in the world or local space..
- `bool isRepeating`: Whether the animation should loop once it reaches the end.
- `int frameRate`: The number of frames to display per second.
- `bool isFlippedRendering`: Whether the animation should be rendered with horizontal flipping.
- `float parallexEffect`: The parallax effect strength applied during rendering.
- `bool hasFinished`:  A flag determines whether the animation has finished.

---

Below is a list and explanation of all public methods
provided by the [Animation](Animation.md) class.

### Constructor

```c++
Animation(SDL_Texture* textureSheet, float textureWidth, float textureHeight, int frameRate, float flipOffset = 0.0f);
```

Constructs an Animation object using a texture sheet and frame layout.

**Parameters:**
- `textureSheet`: The SDL texture containing all animation frames.
- `textureWidth`: The width of a single frame.
- `textureHeight`: The height of a single frame.
- `frameRate`: The number of frames to play per second.
- `flipOffset`: The offset for flipping when the texture content is not centered.

### Destructor

```c++
~Animation() override;
```

Default virtual destructor for proper cleanup.

### onUpdate()

```c++
void onUpdate(float interval) override;
```

Updates the animation timer and advances the frame if needed.

**Parameters:**
- `interval`: Time elapsed since the last update, in seconds.

### onRender()

```c++
void onRender(const Camera &camera) const override;
```

Renders the current frame of the animation using the provided camera.

**Parameters:**
- `camera`: The camera to apply for rendering in world space.

### setOnFinished()

```c++
void setOnFinished(const std::function<void()>& callback);
```

Sets the function to be called when the animation finishes.

### reset()

```c++
void reset();
```

Resets the animation back to its initial state.

---

## Relationships
Below is the position of [Animation](Animation.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Confirms To
[Updatable](Updatable.md) <br>
[Renderable](Renderable.md)

### See Also
[Camera](Camera.md) <br>
[TextureSequence](TextureSequence.md) <br>
[TextureRepresentable](TextureRepresentable.md) <br>
[Transform](Transform.md) <br>
[Timer](Timer.md) <br>
[Vector2](Vector2.md)