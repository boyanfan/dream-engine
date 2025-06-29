# Scene

The standard interface for a complete game scene,
with rendering, updating, and event handling capabilities.
Scene transition control is delegated to the [SceneManager](SceneManager.md).

```c++
class Scene : public GameObject;
```

Conforming to the [Scene](Scene.md) interface
also requires implementing the [GameObject](GameObject.md) interfaces, which define
rendering and game logic update behavior.

---

## Requirements
Below is a list of methods that must be implemented to
conform to the [Scene](Scene.md) interface.

### onEntry()

```c++
virtual void onEntry();
```

Called when the scene is entered. Override this 
method to perform initialization, resource loading, 
or transition effects.

### onExit

```c++
virtual void onExit();
```
Called when the scene is exited. Override this method 
to perform cleanup or save state.

---

## Methods
Below is a list and explanation of all public methods
provided by the [Scene](Scene.md) interface.

### isAllowingSceneTransition()

```c++
bool isAllowingSceneTransition() const;
```

Checks whether the scene is currently allowing transitions.

**Returns:**  `true` if transitions are allowed, `false` otherwise.

### lockSceneTransition()

```c++
void lockSceneTransition();
```

Prevents the scene from transitioning. Useful when a scene is not yet ready to exit.

### unlockSceneTransition()

```c++
void unlockSceneTransition();
```

Allows the scene to transition away when requested. This should be called once the scene is ready to
exit cleanly.

---

## Relationships
Below is the position of [Scene](Scene.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[GameObject](GameObject.md) <br>
[Updatable](Updatable.md) <br>
[Renderable](Renderable.md)  <br>
[Identifiable\<ID\>](Identifiable.md)
