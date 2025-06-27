# TextureSequence

A class that manages a sequence of rectangular regions 
from a single texture sheet. 

```c++
struct TextureSequence;
```

Each region corresponds to a segment of the texture, 
such as an element in a sequence or a layer.

---

## Methods
Below is a list and explanation of all public methods
provided by the [TextureSequence](TextureSequence.md) class.

### Constructor

```c++
TextureSequence(SDL_Texture* textureSheet, float textureWidth, float textureHeight);
```

Constructs a `TextureSequence` from a texture sheet and dimensions of each region.

- `textureSheet`: The shared SDL texture containing multiple regions.
- `textureWidth`: The width of each region in the texture.
- `textureHeight`: The height of each region in the texture.

### Destructor 

```c++
~TextureSequence();
```

Destruct the data structure by clearing all internal collections.

### getTexture()

```c++
TextureRepresentable getTexture(int index) const;
```

Retrieves a [TextureRepresentable](TextureRepresentable.md) 
for the specified region index.

- `index`: The index of the region to retrieve.

**Returns**: 
A [TextureRepresentable](TextureRepresentable.md) 
containing the shared texture and its region.

### getSize()

```c++
size_t getSize() const;
```

**Returns**: The size of the source collection.

---

## Relationships
Below is the position of [TextureSequence](TextureSequence.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[TextureRepresentable](TextureRepresentable.md)