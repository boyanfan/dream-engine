# Mathematics\<T\>

A utility type that provides mathematical operations 
and interpolation methods for a generic type `T`, 
where T supports arithmetic operations such as addition, 
subtraction, and scalar multiplication.

```c++
template<typename T> struct Mathematics;
```

The data type `T` for which interpolation is performed. 
This type must support basic arithmetic operations.

---

## Methods
Below is a list and explanation of all public methods
provided by the [Mathematics](Mathematics.md) type.

### lerp()

```c++
static T lerp(const T& start, const T& end, const float interval, const Curve& curve);
```

Performs linear interpolation between two values start 
and end based on the given interval, modified by the 
provided curve.

**Parameters:**
- `start`: The starting value.
- `end`: The ending value.
- `interval`: A float indicating interpolation progress.
- `curve`: A function that transforms the interval value for custom easing behavior, where `Curve` a type aliases for

```c++
using Curve = std::function<float(float)>;
```

**Returns:** The interpolated result of type `T`.

### linear()

```c++
static float linear(float time);
```

Returns the input value directly. This represents a linear curve with no easing.

**Parameters:**
- `time`: A float progress value.

**Returns:** The same time value.

### easeIn()

```c++
static float easeIn(float time);
```

Returns a value using an **ease-in** quadratic curve. It starts slowly and speeds up toward the end.

**Parameters:**
- `time`: A float progress value.

**Returns:** The eased-in value.

### easeOut()

```c++
static float easeOut(float time);
```

Returns a value using an **ease-out** quadratic curve. It starts quickly and decelerates toward the end.

**Parameters:**
- `time`: A float progress value.

**Returns:** The eased-out value.

### easeInOut()

```c++
static float easeInOut(float time);
```

Returns a value using a **smooth ease-in-out** curve. It starts slowly, speeds up in the middle, and then slows down at the end.

**Parameters:**
- `time`: A float progress value.

**Returns:** The eased-in-out value.
