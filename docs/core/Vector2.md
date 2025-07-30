# Vector2
A simple 2D vector type for representing and manipulating
2D vectors.

```c++
struct Vector2;
```
It supports mathematical operations for 2D vectors, such as 
addition, subtraction, scalar division, dot product, 
magnitude and normalization.

**Fields:**
- `float x`: Horizontal component of the 2D vector.
- `float y`: Vertical component of the 2D vector.
 
---

## Methods
Below is a list and explanation of all public methods
provided by the [Vector2](Vector2.md) type.

### Constructors

```c++
Vector2();
```

Default constructor. Initializes the vector to (0, 0).

```c++
Vector2(float x, float y);
```

Constructs a 2D vector with the given components.  

**Parameters**:
- `x`: The horizontal component.
- `y`: The vertical component.

### Destructor

```c++
~Vector2();
```
Default destructor.

### magnitude()

```c++
float magnitude() const;
```

Computes the magnitude of the vector.  
**Returns**: The length as a float.

### normalize()

```c++
Vector2 normalize() const;
```

Compute a normalized version of this vector.  
**Returns**: A new vector with the same direction but magnitude of 1.

### isZero()

```c++
bool isZero() const;
```

**Returns:** `true` if the vector is zero, `false` otherwise.

---

## Operators

Below is a list and explanation of all operators
supported by the [Vector2](Vector2.md) class.

### Addition
```c++
Vector2 operator +(const Vector2& other) const
``` 

Adds two vectors and returns a new result.

### Substruction

```c++
Vector2 operator -(const Vector2& other) const 
```

Subtracts another vector and returns a new result.

### Cross Multiplication

```c++
float operator *(const Vector2& other) 
``` 

Computes the dot product between this vector and `other`.

### Dot Multiplication

```c++
Vector2 operator *(float value) const
```

Multiplies the vector by a scalar and returns a new result.

### Division

```c++
Vector2 operator /(float value) const
```

Divides the vector by a scalar and returns a new result.

### Addition Assignment

```c++
void operator +=(const Vector2& other)
```

Adds another vector to this one in-place.

### Subtraction Assignment

```c++
void operator -=(const Vector2& other)
```

Subtracts another vector from this one in-place.

### Multiplication Assignment

```c++
void operator *=(const Vector2& other)
```

Performs component-wise multiplication with another vector in-place.

### Dot Multiplication Assignment

```c++
public: void operator *=(float value);
```

Performs dot multiplication with a float in-place.

### Division Assignment

```c++
void operator /=(float value)
```

Divides this vector by a scalar in-place.

---

## Relationships
Below is the position of [Vector2](Vector2.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.