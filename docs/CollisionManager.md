# CollisionManager

A utility class that confirms to the
[Singleton\<T\>](Singleton.md) interface. It manages all active 
[CollisionBox](CollisionBox.md) instances and handles 
collision detection logic using ABBA axis-aligned
collision detection algorithm.

```c++
 class CollisionManager final : public Singleton<CollisionManager>, public Renderable;
```

It also confirms to the [Renderable](Renderable.md) interface
to support debug rendering. All active collision boxes will
be rendered if the build type of the program is `Debug`.

---

## Methods
Below is a list and explanation of all public methods
provided by the [CollisionManager](CollisionManager.md) class.

### getInstance()

```c++
static ResourceManager* getInstance();
```

**Returns:**
A pointer to the single, global [CollisionManager](CollisionManager.md) instance.

### createCollisionBox()

```c++
CollisionBox* createCollisionBox(const Vector2& offset);
```

Creates a new collision box with an optional offset and registers it.

**Parameters:**
- `offset`: A [Vector2](Vector2.md) as the local offset for the collision box.

**Returns:**
A pointer to the newly created [CollisionBox](CollisionBox.md).

### destroyCollisionBox()

```c++
void destroyCollisionBox(CollisionBox* collisionBox);
```

Destroys and deregisters a collision box.

**Parameters:**
- `collisionBox`: The pointer to the collision box to be destroyed.

### processCollision()

```c++
void processCollision() const;
```

Processes collision detection for all active collision boxes. It
invokes the assigned `onCollision` callbacks when collisions occur.

It uses ABBA axis-aligned collision detection algorithm,
which checks whether two rectangles overlap by assuming:
boxes are not rotated, only aligned with the X and Y axes, and
each object’s position and size are represented by a rectangle.

---

## Relationships
Below is the position of [CollisionManager](CollisionManager.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Singleton\<T\>](Singleton.md) <br>
[Renderable](Renderable.md)

### See Also
[CollisionBox](CollisionBox.md) <br>
[Vector2](Vector2.md)