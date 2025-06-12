# Vector2
A simple 2D vector class for representing and manipulating
2D vectors.

```c++
class Vector2;
```
[Vector2](Vector2.md) supports mathematical operations for 2D vectors, such as 
addition, subtraction, scalar division, dot product, 
magnitude and normalization.

- `float x`: Horizontal component of the 2D vector.

- `float y`: Vertical component of the 2D vector.
 
---

## Methods
Below is a list and explanation of all public methods
provided by the [Vector2](Vector2.md) class.

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

## Operators

Below is a list and explanation of all operators
supported by the [Vector2](Vector2.md) class.

```c++
Vector2 operator +(const Vector2& other) const
``` 

Adds two vectors and returns a new result.

<br>

```c++
Vector2 operator -(const Vector2& other) const 
```

Subtracts another vector and returns a new result.

<br>

```c++
float operator *(const Vector2& other) 
``` 

Computes the dot product between this vector and `other`.

<br>

```c++
Vector2 operator *(float value) const
```

Multiplies the vector by a scalar and returns a new result.

<br>

```c++
Vector2 operator /(float value) const
```

Divides the vector by a scalar and returns a new result.

<br>

```c++
void operator +=(const Vector2& other)
```

Adds another vector to this one in-place.

<br>

```c++
void operator -=(const Vector2& other)
```

Subtracts another vector from this one in-place.

<br>

```c++
void operator *=(const Vector2& other)
```

Performs component-wise multiplication with another vector in-place.

<br>

```c++
void operator /=(float value)
```

Divides this vector by a scalar in-place.