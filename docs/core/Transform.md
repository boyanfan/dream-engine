# Transform

A 2D transformation component used for positioning 
and orienting entities in the world or local space.

```c++
struct Transform;
```

**Fields:**

- `Vector2 position`: The current position of the object.
- `Vector2 size`: The size of the object in the world or local space.
- `Vector2 scale`: The scaling factor on each axis.
- `float rotation`: The rotation angle of the object.
- `Vector2 anchor`: The anchor point used for pivoting transformations.
- `Direction direction`: Indicates the logical or visual direction the object is facing or moving, in `Left`, `Right`, `Up`, `Down`, `Inward`, `Outward`, and `None`.

---

## Methods
Below is a list and explanation of all public methods
provided by the [Transform](Transform.md) type.

### Constructors

```c++
Transform();
```

Constructs a default Transform with identity values.

```c++
Transform(const Vector2& position, const Vector2& size, const Vector2& scale, float rotation, const Vector2& anchor);
```
Constructs a Transform with the specified position, scale, rotation, and anchor.

**Parameters:**
- `position`: The initial position of the transform.
- `size`: The initial size of the transform.
- `scale`: The initial scale factors for X and Y.
- `rotation`: The initial rotation angle.
- `anchor`: The anchor point for transformations.

### Destructor

```c++
~Transform();
```

The default destructor.

---

## Operators

Below is a list and explanation of all operators 
supported by the [Transform](Transform.md) struct.

### Addition
```c++
Transform operator +(const Transform& other) const
``` 

Adds two transforms component-wise (position, scale, rotation, anchor) and returns a new result. 
Note that the direction is not considered during this operation.

### Subtraction
```c++
Transform operator -(const Transform& other) const
``` 

Subtracts another transform component-wise and returns a new result.
Note that the direction is not considered during this operation.

### Scalar Multiplication
```c++
Transform operator *(float value) const
```

Multiplies all numerical components (position, scale, rotation, anchor) by a scalar and returns a new transform.
Note that the direction is not considered during this operation.

### Addition Assignment
```c++
void operator +=(const Transform& other)
```

Adds another transform to this one in-place, component-wise.
Note that the direction is not considered during this operation.

### Subtraction Assignment
```c++
void operator -=(const Transform& other)
```

Subtracts another transform from this one in-place, component-wise.
Note that the direction is not considered during this operation.

### Scalar Multiplication Assignment
```c++
void operator *=(float value)
```

Scales this transform's numerical components in-place by a scalar.
Note that the direction is not considered during this operation.