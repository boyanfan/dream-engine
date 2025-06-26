# Scene

The standard interface for a complete game scene,
with rendering, updating, and event handling capabilities.

```c++
class Scene : public GameObject;
```

Conforming to the [Scene](Scene.md) interface
also requires implementing the [GameObject](GameObject.md) interfaces, which define
rendering and game logic update behavior.

**Fields:**

- `bool sceneWillTransition`: Indicates whether the scene is ready to transition away.

---


## Methods
Below is a list of methods that must be implemented to
conform to the [Scene](Scene.md) interface.

### onEntry()

```c++
virtual void onEntry() = 0;
```

Called when the scene is entered. Override this 
method to perform initialization, resource loading, 
or transition effects.

### onExit

```c++
virtual void onExit() = 0;
```
Called when the scene is exited. Override this method 
to perform cleanup or save state.

---

## Relationships
Below is the position of [Scene](Scene.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[GameObject](GameObject.md) <br>
[Updatable](Updatable.md) <br>
[Renderable](Renderable.md) 
