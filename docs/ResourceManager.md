# ResourceManager

`ResourceManager` is a singleton utility class in C++ 
that provides centralized loading and access to 
texture and audio assets in an SDL-based game or 
multimedia application. 

```c++
class ResourceManager;
```

It is designed to simplify asset management by loading 
all `.png` and `.mp3` files from a specified directory
and storing them in memory for later access.

---

## Methods
Below is a list and explanation of all public methods
provided by the `ResourceManager` class.

### getInstance()

```c++
static ResourceManager* getInstance();
```

Returns the singleton instance of `ResourceManager`.

<br>

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
// Load assets
ResourceManager::getInstance()->loadFromDirectory(renderer, "resources/");

// Get and use resources
SDL_Texture* playerTexture = ResourceManager::getInstance()->getTexture("player");
Mix_Chunk* jumpSound = ResourceManager::getInstance()->getAudio("jump");
```

---

## Deleted Methods
To ensure that `ResourceManager` remains a singleton, 
all copy and move operations are explicitly deleted. 
This prevents accidental duplication or reassignment 
of the singleton instance, which could lead to 
multiple resource pools and undefined behavior.

```c++
ResourceManager(const ResourceManager&) = delete;
ResourceManager(ResourceManager&&) = delete;
ResourceManager& operator=(const ResourceManager&) = delete;
ResourceManager& operator=(ResourceManager&&) = delete;
```

In the singleton pattern, it is critical that only one
instance of the class exists throughout the program's
lifetime. By deleting:

- Copy constructor: prevents creating a new instance by copying.
- Move constructor: prevents moving the instance into a new object.
- Copy assignment operator: prevents assigning one ResourceManager to another.
- Move assignment operator: prevents moving one ResourceManager into another.

This guarantees that the singleton instance created 
via getInstance() remains unique and immutable in 
identity.

### Example Misuses Prevented

```c++
// These would be compile-time errors:
ResourceManager a = *ResourceManager::getInstance();
ResourceManager b = std::move(*ResourceManager::getInstance());
a = *ResourceManager::getInstance();
b = std::move(*ResourceManager::getInstance());
```