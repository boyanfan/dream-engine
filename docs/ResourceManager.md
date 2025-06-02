# ResourceManager

`ResourceManager` is a singleton utility class in C++ 
that inherits from the generic 
`Singleton<ResourceManager>` base class and provides 
centralized loading and access to texture and audio 
assets.

```c++
class ResourceManager final : public Singleton<ResourceManager>;
```

It is designed to simplify asset management by loading 
all `.png` and `.mp3` files from a specified directory
and storing them in memory for later access.

---

## Methods
Below is a list and explanation of all public methods
provided by the `ResourceManager` class.

### loadFromDirectory()

```c++
void loadFromDirectory(SDL_Renderer* renderer, const std::string& directory);
```

Loads all .png and .mp3 files from the specified 
directory into memory, where `.png` files are loaded 
using `IMG_LoadTexture`, and `.mp3` files are loaded 
using Mix_LoadWAV.

Keys used in resource maps are the base filenames (without extensions).

**Parameters**
- renderer: Pointer to SDL_Renderer, required for texture creation.
- directory: Path to the folder containing asset files.

<br>

### getTexture()

```c++
SDL_Texture* getTexture(const std::string& textureName);
```
Retrieves a loaded texture from the texture pool.

**Parameters**
- textureName: The base filename of the texture (e.g., "player" for player.png).

**Returns:**
Pointer to SDL_Texture if found, or nullptr.

<br>

### getAudio()

```c++
Mix_Chunk* getAudio(const std::string& audioName);
```

Retrieves a loaded audio chunk from the audio pool.

**Parameters**
- audioName: The base filename of the audio (e.g., "jump" for jump.mp3).

**Returns:**
Pointer to Mix_Chunk if found, or nullptr.

---

## Example Usage

```c++
// Get singleton instance
ResourceManager* manager = ResourceManager::getInstance();

// Load assets
manager->loadFromDirectory(renderer, "resources/");

// Get and use resources
SDL_Texture* playerTexture = manager->getTexture("player");
Mix_Chunk* jumpSound =manager->getAudio("jump");
```