# Application
The [Application](Application.md) class serves as the core entry point 
for any game or interactive program built with DreamEngine. 
It handles game initialization, creates the main window 
and renderer, and manages the main loop, including event 
polling, update logic, rendering, and frame rate control.

```c++
class Application;
```

Dream Engine uses a Scene-based architecture. 
Developers implement game behavior by confirming 
[Scene](Scene.md) interface, then schedule those scenes 
with the [SceneManager](SceneManager.md). The [Application](Application.md) 
class automatically delegates per-frame updates and 
rendering to the active scene.

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
and the `onRender()` with the main camera to draw the frame.
Methods above are delegated to the [Scene](Scene.md) interface implementation.

---

## Reflection

The [Application](Application.md) class provides basic 
reflection by storing its own class name, which can be 
accessed via `Application::self`. 

```c++
static inline std::string self;
```

---

## Relationships
Below is the position of [Application](Application.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[WindowConfiguration](WindowConfiguration.md) <br>
[Scene](Scene.md) <br>
[SceneManager](SceneManager.md)