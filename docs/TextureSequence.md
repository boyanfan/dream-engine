# TextureSequence
[TextureSequence](TextureSequence.md) is a utility class for managing a 
sequence of `SDL_Texture*` objects, typically used for 
loading and displaying animated image sequences in 
SDL-based applications.

```c++
class TextureSequence;
```

All textures used in [TextureSequence](TextureSequence.md) should be loaded 
from the [ResourceManager](ResourceManager.md). The sequence does not 
own any of the textures in the sequence. It only 
clears internal references, avoiding double-free 
errors and ensures consistent centralized resource 
management.

---

## Methods
Below is a list and explanation of all public methods 
provided by the [TextureSequence](TextureSequence.md) class.

### Constructors

```c++
TextureSequence();
```

Default constructor. Initializes an empty sequence 
with no memory reserved. 

**Usage:**  
Use this when the number of textures to be loaded 
is not known in advance. However, this may result 
in performance overhead due to repeated vector 
re-allocations.

```c++
TextureSequence(size_t size);
```

Constructor that pre-allocates memory for a specified 
number of textures using `std::vector::reserve`.

**Parameters:**
- `size`: The number of textures you plan to store.

**Usage:**  
Preferred for performance when you know the number of 
textures beforehand. Reduces heap re-allocations.

<br>

### Destructors

```c++
~TextureSequence();
```
Clears the texture sequence vector. This does not
destroy the `SDL_Texture*` objects. The
[ResourceManager](ResourceManager.md) is responsible for managing the 
lifetime of these textures.

<br>

### loadSequenceFromPool()
```c++
void loadSequenceFromPool(const char* nameTemplate, size_t size);
```

Safely loads textures by name from the
[ResourceManager](ResourceManager.md)’s texture pool. 
This is the recommended and safe method because the 
textures are centrally managed and not duplicated.


**Parameters:**
- `pathTemplate`: A C-style formatted string with formatting placeholders for file paths like `frame_%`, where `%d` is replaced by the index.
- `size`: The number of textures to load.

**Note:**
Textures that fail to load are logged with `SDL_Log`
but skipped.

<br>

### loadSequenceFromPath()

```c++
void loadSequenceFromPath(SDL_Renderer* renderer, const char* pathTemplate, size_t size);
```

Loads textures directly from file paths. 
This bypasses the [ResourceManager](ResourceManager.md), 
and the resulting textures are not tracked or 
automatically cleaned up. Using this method is 
unsafe and may lead to resource leaks or duplicate 
textures in memory. Avoid this unless you have a 
clear reason and manage the textures manually, and
call `destroyTextureByIndex()` to manually destroy
them.


**Parameters:**
- `renderer`: The SDL renderer used to create the textures.
- `pathTemplate`: A C-style formatted string with formatting placeholders for file paths like `frame_%`, where `%d` is replaced by the index.
- `size`: The number of textures to load.

**Note:**
Textures that fail to load are logged with `SDL_Log`
but skipped.

<br>

### clearSequence()

```c++
void clearSequence();
```

Clears the texture sequence vector. This does not
destroy the `SDL_Texture*` objects. The
[ResourceManager](ResourceManager.md) is responsible for managing the
lifetime of these textures.

<br>

### destroyTextureByIndex()
```c++
void destroyTextureByIndex(int index);
```
Destroy the texture at the given index and removes it 
from the sequence. This should only be used if the 
texture was manually created or loaded outside the
[ResourceManager](ResourceManager.md) 
and thus is not managed by it.

**Parameters:**
- Index of the texture to destroy.

<br>

### getSequenceSize()

```c++
size_t getSequenceSize();
```

Returns the number of textures currently stored in 
the sequence.

**Returns:**  
Number of elements in the internal vector.

<br>

### getTextureByIndex()

```c++
SDL_Texture* getTextureByIndex(int index);
```

Fetches a texture pointer by index.

**Parameters:**
- `index`: The position in the sequence to retrieve from.

**Returns:**  
Pointer to the texture at `index`, or `nullptr` if 
out of bounds.

**Usage:**  
Safe access method for rendering or processing 
specific frames, alternative to `operator[]` access.

<br>

### addTexture()

```c++
void addTexture(SDL_Texture* texture);
```

Adds an externally created texture to the sequence.

**Parameters:**
- `texture`: Pointer to an existing `SDL_Texture` to store.

**Note:** 
if the texture was manually created or loaded 
outside the [ResourceManager](ResourceManager.md)
and thus is not managed by it, you must call `destroyTextureByIndex()` 
to manually destroy it.

<br>

### Operators

```c++
SDL_Texture*& operator [](size_t index);
const SDL_Texture* operator [](size_t index) const;
```

Overloaded subscript operator for convenient direct 
access to textures by index.

**Parameters:**
- `index`: The position in the sequence.

**Returns:**  
Reference (non-const or const) to the texture pointer 
at the given index.

**Warning:**  
- This method does not perform bounds checking. If you need safe access, prefer `getTextureByIndex()` instead.

---

## Example Usage

```cpp
// Create with pre-allocated space for 10 textures
TextureSequence sequence(10);

// Load textures named "frame_1.png", ..., "frame_10.png"
sequence.loadSequenceFromPool("frame_%d.png", 10);

// Render the 3rd texture
SDL_Texture* texture = sequence.getTextureByIndex(2);

if (texture) {
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

// Cleanup happens automatically in destructor
```