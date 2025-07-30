# EdgeInsets
A data type that represents the inset distances for the 
sides of a rectangle, defined by its four edges.

```c++
struct EdgeInsets;
```

**Fields:**

- `float leading`: The distance from the leading edge.
- `float top`: The distance from the top edge.
- `float trailing`: The distance from the trailing edge.
- `float bottom`: The distance from the bottom edge.

---

## Methods
Below is a list and explanation of all public methods
provided by the [EdgeInsets](EdgeInsets.md) type.

### Constructors

```c++
EdgeInsets(float leading, float top, float trailing, float bottom);
```

Constructs an EdgeInsets with individually specified values for each edge.

**Parameters:**
- `left`: The distance from the leading edge.
- `top`: The distance from the top edge.
- `right`: The distance from the trailing edge.
- `bottom`: The distance from the bottom edge.

```c++
EdgeInsets(float all);
```

Constructs an EdgeInsets where all edges share the same value.

**Parameters:**
- all: The uniform distance applied to all edges.

### all()

```c++
static EdgeInsets all(float all);
```

Creates an EdgeInsets instance with the same value applied to all edges.

**Parameters:**
- `all`: The uniform distance to apply.

**Returns:**
An EdgeInsets with the same value on all sides.