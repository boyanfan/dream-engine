# FontRepresentable
A wrapper type for SDL `TTF_Font` type, 
it provides a convenient and efficient way to load and reuse 
font resources with multiple sizes.

```c++
struct FontRepresentable;
```

It supports lazy loading of fonts — fonts of a 
given size are only loaded when first requested. 
Once loaded, they are stored in an internal cache to avoid 
redundant file access and improve runtime performance.

---

## Methods
Below is a list and explanation of all public methods
provided by the [FontRepresentable](FontRepresentable.md) type.

### Constructor

```c++
explicit FontRepresentable(std::string filepath);
```

Constructs a Font object from the given font file path. The 
actual font data is not loaded until `getSizedFont()` is called, 
enabling lazy loading.

**Parameters:**
- `path`: Path to the font file, with an extension of `.ttf`.

### Destructor
```c++
~FontRepresentable();
```
Releases all loaded font resources. It iterates through 
the font size catching and calls `TTF_CloseFont()` for 
each cached font to prevent memory leaks.

### getSizedFont()

```c++
TTF_Font* getSizedFont(float fontSize);
```

Returns a pointer to a font of the specified size.

**Parameters:**
- `fontSize`: The desired float font size in points.

**Returns:** 
A `TTF_Font*` for rendering text at the specified size. 
Returns nullptr if loading fails.

---

## Relationships
Below is the position of [FontRepresentable](FontRepresentable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[ResourceManager](ResourceManager.md)