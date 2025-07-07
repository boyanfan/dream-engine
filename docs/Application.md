# Application
The core entry point 
for any game or interactive program built with Dream Engine. 
It handles game initialization, creates the main window 
and renderer, and manages the main loop, including event 
polling, update logic, rendering, and frame rate control.

```c++
class Application;
```

Dream Engine uses a scene-based architecture. 
Developers define game behavior by implementing classes that confirm 
[Scene](Scene.md) interface, then schedule those scenes 
with the [SceneManager](SceneManager.md). The user-input handling, 
per-frame updates, and rendering logic are automatically
delegated to the current active scene.

**Fields:**
- `SDL_Renderer* renderer`: Pointer to the SDL renderer used for rendering.
- `Camera* camera`: Pointer to the [Camera](Camera.md) used for rendering the current view.

---

## Methods

Below is a list and explanation of all public methods
provided by the [Application](Application.md) class.

### Constructor

```c++
explicit Application(const WindowConfiguration& configuration);
```

Initializes the application, creates the window and renderer using the provided configuration.

**Parameters:**
- `configuration`: A [WindowConfiguration](WindowConfiguration.md) object specifying window title, dimensions, and target frame rate.

### Destructor

```c++
virtual ~Application();
```

Cleans up SDL resources by destroying the window and renderer.

### execute()

```c++
void execute();
```

Starts the main loop. It polls SDL events and passes 
them to the active `onEvent()` method, 
calls the `onUpdate()` to update game logic, 
and the `onRender()` with the [Camera](Camera.md) to display the frame.
Methods above are delegated to the [Scene](Scene.md) interface implementation.

---

## Relationships
Below is the position of [Application](Application.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[WindowConfiguration](WindowConfiguration.md) <br>
[GeometryProxy](GeometryProxy.md) <br>
[Scene](Scene.md) <br>
[SceneManager](SceneManager.md) <br>
[Camera](Camera.md)