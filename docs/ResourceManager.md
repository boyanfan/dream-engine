# ResourceManager

[ResourceManager](ResourceManager.md) is a singleton 
utility class in C++ that inherits from the generic
[Singleton\<T\>](Singleton.md) base class and provides 
centralized loading and access to texture and audio 
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

Returns the singleton instance of `ResourceManager`. 
This method is defined and inherited from the
[Singleton\<T\>](Singleton.md) base class.

**Returns:**
A pointer to the single, global `ResourceManager` 
instance.

<br>

### loadFromDirectory()

```c++
void loadFromDirectory(SDL_Renderer* renderer, const std::string& directory);
```

Scans the specified directory and attempts to load each 
file using a registered loader based on its file 
extension. Keys used in resource maps are the base filenames, without extensions.

**Parameters**
- renderer: Pointer to SDL_Renderer, required for texture creation.
- directory: Path to the folder containing asset files.

<br>

### getTexture()

```c++
SDL_Texture* getTexture(const std::string& textureName) const;
```
Retrieves a loaded texture from the texture pool.

**Parameters**
- textureName: The base filename of the texture, without the extension.

**Returns:**
Pointer to `SDL_Texture` if found, or nullptr.

<br>

### getAudio()

```c++
Mix_Chunk* getAudio(const std::string& audioName) const;
```

Retrieves a loaded audio chunk from the audio pool.

**Parameters**
- audioName: The base filename of the audio, without the extension.

**Returns:**
Pointer to `Mix_Chunk` if found, or nullptr.

<br>

### getFont()

```c++
Font* getFont(const std::string& fontName) const;
```

Retrieves a loaded font from the font pool.

**Parameters**
- fontName: The base filename of the font, without the extension.

**Returns:**
Pointer to [Font](Font.md) if found, or nullptr.

<br>

---

## Example Usage

```c++
// Get singleton instance
ResourceManager* manager = ResourceManager::getInstance();

// Load assets
manager->loadFromDirectory(renderer, "resources/");

// Get and use resources
SDL_Texture* playerTexture = manager->getTexture("player");
Mix_Chunk* jumpSound = manager->getAudio("jump");
```

---

## Relationships
Below is the position of [ResourceManager](ResourceManager.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Singleton\<T\>](Singleton.md)

### See Also
[Font](Font.md)