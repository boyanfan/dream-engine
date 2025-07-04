# Transform

A 2D transformation component used for positioning 
and orienting entities in the world or local space.

```c++
struct Transform;
```

**Fields:**

- `Vector2 position`: The current position of the object.
- `Vector2 scale`: The scaling factor on each axis.
- `float rotation`: The rotation angle of the object.
- `Vector2 anchor`: The anchor point used for pivoting transformations.
- `Direction direction`: Indicates the logical or visual direction the object is facing or moving.

---

## Note

Enumeration class `Direction` represents cardinal or 
conceptual directions for 2D transformations or 
orientation logic, where

| Value     | Description                                   |
|-----------|-----------------------------------------------|
| `Left`    | Indicates a leftward direction.               |
| `Right`   | Indicates a rightward direction.              |
| `Up`      | Indicates an upward direction.                |
| `Down`    | Indicates a downward direction.               |
| `Inward`  | Typically used to represent inward movement.  |
| `Outward` | Typically used to represent outward movement. |
| `None`    | No specific direction is set.                 |
