# FontRepresentable
[FontRepresentable](FontRepresentable.md) is a wrapper class for SDL `TTF_Font` struct, 
it provides a convenient and efficient way to load and reuse 
font resources with multiple sizes.

```c++
struct FontRepresentable;
```

This class supports lazy loading of fonts — fonts of a 
given size are only loaded when first requested. 
Once loaded, they are stored in an internal cache to avoid 
redundant file access and improve runtime performance.

---

## Methods
Below is a list and explanation of all public methods
provided by the [FontRepresentable](FontRepresentable.md) class.

### Constructor

```c++
explicit FontRepresentable(std::string filepath);
```

Constructs a Font object from the given font file path. The 
actual font data is not loaded until `getSizedFont()` is called, 
enabling lazy loading.

**Parameters:**
- path: Path to the font file, with an extension of `.ttf`.

### Destructor
```c++
~FontRepresentable();
```
Releases all loaded font resources. It iterates through 
the font size catching and calls `TTF_CloseFont()` for 
each cached font to prevent memory leaks.

### getSizedFont()

```c++
TTF_Font* getSizedFont(int fontSize);
```

Returns a pointer to a font of the specified size.

**Parameters:**
- fontSize: The desired integer font size in points.

**Returns:** 
A `TTF_Font*` for rendering text at the specified size. 
Returns nullptr if loading fails.

**Notes:**
Fonts are not loaded until they are needed. If a font of 
the requested size already exists in the internal cache, 
it is returned immediately. Otherwise, it is loaded from 
disk using `TTF_OpenFont()`, cached, and then returned.

---

## Example Usage

```c++
// Get font from resource manager
ResourceManager* manager = ResourceManager::getInstance();
FontRepresentable font = manager->getFont("font");

TTF_Font* title = font.getSizedFont(52);
TTF_Font* body = font.getSizedFont(16);
```

---

## Relationships
Below is the position of [FontRepresentable](FontRepresentable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[ResourceManager](ResourceManager.md)