# TextureRepresentable

A type representing a texture region that can be rendered. 

```c++
struct TextureRepresentable;
```

It encapsulates both the texture sheet and its 
corresponding source rectangle, primarily used by 
[TextureSequence](TextureSequence.md) to represent
individual texture regions.

**Fields:**
- `SDL_Texture* texture`: Pointer to the shared original SDL texture resource.
- `SDL_FRect source`: The source rectangle within the texture sheet to render.

---

## Methods
Below is a list and explanation of all public methods
provided by the [TextureRepresentable](TextureRepresentable.md) type.

### Constructor

```c++
TextureRepresentable(SDL_Texture* texture, const SDL_FRect source);
```

Constructs a `TextureRepresentable` using the given texture and source rectangle.

- `texture`: A pointer to the SDL texture sheet.
- `source`: The portion of the texture to represent.

### Destructor

```c++
~TextureRepresentable() = default;
```

Default destructor.

---

## Relationships
Below is the position of [TextureRepresentable](TextureRepresentable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[TextureSequence](TextureSequence.md)