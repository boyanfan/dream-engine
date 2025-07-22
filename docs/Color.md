# Color
A type that represents a color using red, green, blue, 
and alpha components.

```c++
struct Color;
```

**Fields:**
- `uint8_t red`: The red value of a color.
- `uint8_t green`: The green value of a color.
- `uint8_t blue`: The blue value of a color.
- `uint8_t alpha`: The alpha value of a color.

---

## Methods
Below is a list and explanation of all public methods
provided by the [Color](Color.md) type.

### Constructor

```c++
Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
```

Construct a color with the provided RGBA values.

**Parameters:**
- `red`: The red value of a color.
- `green`: The green value of a color.
- `blue`: The blue value of a color.
- `alpha`: The alpha value of a color.

```c++
Color(const std::string& hexRepresentation);
```

Constructs a Color from a hexadecimal string representation.

**Parameters:**
- `hexRepresentation` A string starting with `#` followed by six or eight hex digits.

---

## Macros

To allow convenient usage of `Color` objects with APIs 
that require separate red, green, blue, and alpha parameters,
the macro

- `COLOR_TO_ARGS(color)`

Expands a Color object into its individual RGBA components as arguments.

**Example:**

```c++
SDL_SetRenderDrawColor(renderer, COLOR_TO_ARGS(Color::Black));   // Will be explanded to
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
```

---

## Relationships
Below is the position of [Color](Color.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.