# Application
The [Application](Application.md) class serves as the core entry point 
for any game or interactive program built with DreamEngine. 
It handles SDL initialization, creates the main window 
and renderer, and manages the main loop, including event 
polling, update logic, rendering, and frame rate control.

```c++
class Application;
```

Games should inherit from [Application](Application.md) 
and override the `onUpdate()`, `onRender()`, and `onEvent()` 
methods to implement their specific game behavior.

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

It starts the main loop. This loop polls SDL events and 
dispatches them to `onEvent()`, calculates `interval` 
between frames and calls `onUpdate()` to 
update game logic, calls onRender() to render the frame,
and caps the frame rate.

### onEvent()

```c++
virtual void onEvent(const SDL_Event& event) = 0;
```
Override this method to handle user input or other SDL events.

**Parameters:**
- `event`: The SDL_Event to handle, including input, window, and system events.

### onUpdate()

```c++
virtual void onUpdate(float interval) = 0;
```

Override this method to define game logic. 
It is called once per frame.

**Parameters:**
- `interval`: Time interval since the last frame in seconds. Use this to make your update frame-rate independent.

### onRender()

```c++
virtual void onRender(SDL_Renderer* renderer) = 0;
```

Override this method to render your game frame using 
the provided SDL renderer.

**Parameters:**
- `renderer`: The SDL_Renderer instance to draw with.

---

## Reflection

The [Application](Application.md) class provides basic 
reflection by storing its own class name, which can be 
accessed via `Application::self`. This feature is commonly 
used by other classes such as [Logger](Logger.md).

```c++
static inline std::string self;
```

---

## Summary

To build your own game using the [Application](Application.md) class:

- Construct a [WindowConfiguration](WindowConfiguration.md) to define your game's title, resolution, and target frame rate.
- Create your game class that inherits from [Application](Application.md).
- Override `onEvent()` to handle input such as key presses, mouse movement, and SDL window events.
- Override `onUpdate()` to update your game logic using delta time. This is where you move objects, check collisions, and apply game rules.
- Override `onRender()` to draw your game visuals every frame.
- Call `execute()` on your game class to start the game loop.

---

## Relationships
Below is the position of [Application](Application.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[WindowConfiguration](WindowConfiguration.md) <br>
[Logger](Logger.md)