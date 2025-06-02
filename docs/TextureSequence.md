# TextureSequence
`TextureSequence` is a utility class for managing a 
sequence of `SDL_Texture*` objects, typically used for 
loading and displaying animated image sequences in 
SDL-based applications.

```c++
class TextureSequence;
```

It supports dynamic loading, retrieval, and cleanup of 
textures and provides basic access functions for 
sequence manipulation.

---

## Methods
Below is a list and explanation of all public methods 
provided by the `TextureSequence` class.

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
Destructor. Iterates over the texture sequence and 
destroys each `SDL_Texture*` using 
`SDL_DestroyTexture()`.

**Usage:**  
Automatically called when the object goes out of scope.
Ensures no texture memory leaks.

<br>

### loadSequenceFromPath()

```c++
void loadSequenceFromPath(SDL_Renderer* renderer, const char* pathTemplate, size_t size);
```

Loads a sequence of textures using a printf-style 
file path template.

**Parameters:**
- `renderer`: The SDL renderer used to create the textures.
- `pathTemplate`: A C-style formatted string with formatting placeholders for file paths like `frame_%`, where %d is replaced by the index.
- `size`: The number of textures to load.

**Usage:**  
For each index from 1 to `size`, generates the 
filename, loads the texture, and adds it to the 
sequence.

**Note:**  
Textures that fail to load are logged with `SDL_Log` 
but skipped.

<br>

### loadSequenceFromPool()
```c++
void loadSequenceFromPool(const char* nameTemplate, size_t size);
```

Loads a sequence of textures from the 
`ResourceManager`'s texture pool using a formatted key 
name template. This function is useful when your 
textures are preloaded into `ResourceManager`.

**Parameters:**
- `pathTemplate`: A C-style formatted string with formatting placeholders for file paths like `frame_%`, where %d is replaced by the index.
- `size`: The number of textures to load.

**Usage:**  
For each index from 1 to `size`, retrieves each 
texture from the texture pool, and adds the texture to 
the sequence if found.

**Note:**  
Textures that fail to load are logged with `SDL_Log`
but skipped.

<br>

### clearSequence()

```c++
void clearSequence();
```

Clears the `textureSequence` vector. This does not 
destroy the `SDL_Texture*` objects.

**Usage:**  
Use this only if you manage texture lifetimes manually 
and want to reuse the object without deleting textures.

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
- `index`: The position in the sequence to retrieve 
- from.

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
- `texture`: Pointer to an existing `SDL_Texture` 
- to store.

**Usage:**  
Useful when textures are loaded manually or generated
from other sources.

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

## Performance Considerations

Using `std::vector::push_back()` repeatedly 
without pre-allocation can lead to repeated memory 
re-allocations and internal copying. 
Even though `SDL_Texture*` is a pointer 
(so copying is cheap), these re-allocations can 
become a performance bottleneck if the sequence 
is large.

Reserving capacity before loading textures is 
recommended, either call 
`textureSequence.reserve(size)` manually or 
use the constructor** `TextureSequence(size_t)` 
to pre-allocate.

---

## Example Usage

```cpp
SDL_Renderer* renderer = /* initialized renderer */;

// Create with pre-allocated space for 10 textures
TextureSequence sequence(10);

// Load textures named "frame_1.png", ..., "frame_10.png"
sequence.loadSequenceFromPath(renderer, "resources/frame_%d.png", 10);

// Render the 3rd texture
SDL_Texture* texture = sequence.getTextureByIndex(2);
if (texture) {
    SDL_RenderCopy(renderer, tex, nullptr, &destRect);
}

// Cleanup happens automatically in destructor
```