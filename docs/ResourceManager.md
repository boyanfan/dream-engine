# ResourceManager

[ResourceManager](ResourceManager.md) is a singleton 
utility class in C++ that inherits from the generic
[Singleton\<T\>](Singleton.md) base class and provides 
centralized loading and access to texture and audio 
assets.

```c++
class ResourceManager final : public Singleton<ResourceManager>;
```

It is designed to simplify asset management by loading 
different files, both build-in supported or user-defined
arbitrary resource types, from a specified directory
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

### registerLoader()
```c++
void registerLoader(const std::string& extension, const ResourceManager::Loader& loader);
```

Registers a custom resource loader for a specific file 
extension. This enables developers to extend
[ResourceManager](ResourceManager.md) with support for 
additional resource types beyond the built-in types.

**Parameters:**
- extension: File extension, including dot.
- loader: A function that loads a file given its path and stores the resource into one of the internal pools, defined by

```c++
using Loader = std::function<void(SDL_Renderer* renderer, const std::filesystem::path& path)>;
```

This means that the registered function must accept 
an `SDL_Renderer*` and a file path, and perform the 
logic needed to load and store the resource. 
If you are adding new resource types, they should be
considered SDL-renderable or at least SDL-context-aware.
Even if your custom loader doesn't use the `SDL_Renderer*`,
the function signature must accept it.

Custom resource types that are not built into
[ResourceManager](ResourceManager.md) and should be 
stored in the `genericPool` using:

```c++
std::unordered_map<std::string, ResourceManager::AnyRenderable> genericPool;
```

Where `AnyRenderable` is defined by

```c++
using AnyRenderable = std::shared_ptr<void>
```

This means that to ensure type safety and shared ownership, 
all custom resource objects must be wrapped in 
`std::shared_ptr<T>`, where `T` is your custom type, 
using `std::make_shared<T>()` function.

**Notes:**
- Call `registerLoader()` before calling `loadFromDirectory()` only if you have custom resource type.
- Use `getGeneric<T>(name)` to retrieve user-defined resource types.
- For any custom resource stored in `genericPool`, developers are responsible for managing memory and cleanup themselves.

**Example Usage:**

```c++
// Get singleton instance
ResourceManager* manager = ResourceManager::getInstance();

// Register loader
manager->registerLoader(".atlas", [&](SDL_Renderer*, const std::filesystem::path& path) {
    ...
    auto atlas = std::make_shared<...>();
    manager->genericPool[path.stem().u8string()] = atlas;
}
```

<br>

### loadFromDirectory()

```c++
void loadFromDirectory(SDL_Renderer* renderer, const std::string& directory);
```

Scans the specified directory and attempts to load each 
file using a registered loader based on its file 
extension. Keys used in resource maps are the base filenames, without extensions.

Built-in support is typically provided 
for `.png` (textures) and `.mp3` (audio), but developers 
can extend support to custom file types by registering 
additional loaders via `registerLoader()`.

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
- textureName: The base filename of the texture.

**Returns:**
Pointer to SDL_Texture if found, or nullptr.

<br>

### getAudio()

```c++
Mix_Chunk* getAudio(const std::string& audioName) const;
```

Retrieves a loaded audio chunk from the audio pool.

**Parameters**
- audioName: The base filename of the audio.

**Returns:**
Pointer to Mix_Chunk if found, or nullptr.

<br>

### getGeneric\<T\>()

```c++
template<typename T> std::shared_ptr<T> getGeneric(const std::string& name) const;
```

Retrieves a custom resource stored in the `genericPool`, 
cast to the expected type `T`. 

This method is intended for accessing user-defined 
resources that were loaded via `registerLoader()` 
and stored as `AnyRenderable` in the generic 
resource pool. It performs a `static_pointer_cast<T>` 
internally. 

**Template Parameters:**
- T: The expected resource type.

**Parameters:**
- name: The base name of the resource, the filename without extension. This must match the stem used during loading.

**Returns:** A `std::shared_ptr<T>` to the requested 
resource if found and castable. 

**Notes:**
- Returns nullptr if the resource name does not exist in the pool, or the stored pointer is nullptr, or the cast fails.
- Only resources stored in `genericPool` via `registerLoader()` are accessible through this method.
- It is the developer’s responsibility to ensure that the stored type matches the expected type `T`.
- It is not enforced at runtime — make sure the cast is safe.

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