# SceneManager

A singleton
utility class that inherits from the generic
[Singleton\<T\>](Singleton.md) base class, responsible for
managing scene transitions in a game. 

```c++
class SceneManager final : public Singleton<SceneManager>;
```

It keeps track of the currently active scene and provides an interface to switch to a different one.

---

## Methods
Below is a list and explanation of all public methods
provided by the [SceneManager](SceneManager.md) class.

### getInstance()

```c++
static SceneManager* getInstance();
```

**Returns:**
A pointer to the single, global instance.

### getCurrentScene()

```c++
Scene* getCurrentScene() const;
```

**Returns:** Pointer to the current [Scene](Scene.md).

### switchCurrentScene()

```c++
void switchCurrentScene(Scene* nextScene);
```

Schedules a scene to become the next active scene.

**Parameters:**
- `nextScene`: Pointer to the new [Scene](Scene.md) to activate.

---

## Reflection

The [SceneManager](SceneManager.md) class provides basic
reflection by storing its own class name, which can be
accessed via `SceneManager::self`.

```c++
static inline std::string self;
```

---

## Relationships
Below is the position of [ResourceManager](ResourceManager.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Singleton\<T\>](Singleton.md)

### See Also
[Scene](Scene.md)