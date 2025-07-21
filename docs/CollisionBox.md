# CollisionBox
A type that represents an axis-aligned rectangular collision 
box attached to a game object and participates in collision 
detection via the [CollisionManager](CollisionManager.md).

```c++
struct CollisionBox;
```

**Fields:**
- `bool isEnabled`: Whether the collision box is active and should be processed.
- `std::string sourceLayer`: Logical source layer used for selective collision filtering when processing collisions.
- `std::string destinationLayer`: Logical destination layer used for selective collision filtering when processing collisions.

---

## Methods

Below is a list and explanation of all public methods
provided by the [CollisionBox](CollisionBox.md) type.

### setTransform()

```c++
void setTransform(const Transform& transform);
```

Sets the world-space transform for the collision box.

**Parameters:**
- `transform`: The new [Transform](Transform.md) to associate with this collision box.

### setOffset()

```c++
void setOffset(const Vector2& offset);
```

Sets the local offset from the transform position.

**Parameters:**
- `offset`: A [Vector2](Vector2.md) as the new offset value.

### setOnCollision()

```c++
void setOnCollision(const std::function<void()>& callback);
```

Assigns a callback function to be executed when a collision occurs.

**Parameters:**
- `callback`: The collision response callback.

---

## Relationships
Below is the position of [CollisionBox](CollisionBox.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[CollisionManager](CollisionManager.md) <br>
[Transform](Transform.md) <br>
[Vector2](Vector2.md)
