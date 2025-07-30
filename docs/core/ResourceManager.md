# ResourceManager

A utility class that confirms to the
[Singleton\<T\>](Singleton.md) interface and provides 
centralized loading and access to texture, audio, video and font 
assets.

```c++
class ResourceManager : public Singleton<ResourceManager>;
```

It is designed to simplify asset management by loading 
different files from a specified directory
and storing them in memory for later access.

---

## Methods
Below is a list and explanation of all public methods
provided by the [ResourceManager](ResourceManager.md) class.

### getInstance()

```c++
static ResourceManager* getInstance();
```

**Returns:**
A pointer to the single, global [ResourceManager](ResourceManager.md) instance.

### loadFromDirectory()

```c++
void loadFromDirectory(SDL_Renderer* renderer, const std::string& directory);
```

Scans the specified directory and attempts to load each 
file using a registered loader based on its file 
extension. Keys used in resource maps are the base filenames, without extensions.

**Parameters**
- `renderer`: Pointer to SDL_Renderer, required for texture creation.
- `directory`: Path to the folder containing asset files.

### getTexture()

```c++
SDL_Texture* getTexture(const std::string& textureName) const;
```
Retrieve a loaded texture from the texture pool.

**Parameters**
- `textureName`: The base filename of the texture, without the extension.

**Returns:**
Pointer to `SDL_Texture` if found, or nullptr.

### getAudio()

```c++
Mix_Chunk* getAudio(const std::string& audioName) const;
```

Retrieve a loaded audio chunk from the audio pool.

**Parameters**
- `audioName`: The base filename of the audio, without the extension.

**Returns:**
Pointer to `Mix_Chunk` if found, or nullptr.

### getFont()

```c++
FontRepresentable* getFont(const std::string& fontName) const;
```

Retrieve a loaded font from the font pool.

**Parameters**
- `fontName`: The base filename of the font, without the extension.

**Returns:**
Pointer to [FontRepresentable](FontRepresentable.md) if found, or nullptr.


### getVideo()

```c++
VideoRepresentable* getVideo(const std::string& videoName) const;
```

Retrieve a loaded video from the video pool.

**Parameters:**

- `videoName`: The base filename of the video, without the extension.

**Returns:**
Pointer to [VideoRepresentable](VideoRepresentable.md) if found, or nullptr.

---

## Relationships
Below is the position of [ResourceManager](ResourceManager.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Singleton\<T\>](Singleton.md)

### See Also
[FontRepresentable](FontRepresentable.md) <br>
[VideoRepresentable](VideoRepresentable.md)