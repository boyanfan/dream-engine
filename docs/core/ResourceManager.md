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

### generateResourceManifest()

```c++
static bool generateResourceManifest(const std::filesystem::path& directory, const std::filesystem::path& path);
```

Generates an integrity manifest for all regular files under a resource directory.
This function recursively scans the specified resource directory, computes a cryptographic SHA-256 hash
and file size for each asset and writes the results to a manifest file. The manifest can later be used
to verify asset integrity at runtime and detect corruption, partial writes or unauthorized modification.

**Parameters:**
- `directory`: Root directory containing resource files.
- `path`: Output path of the generated manifest file.

**Returns:**
True if the manifest was successfully generated; false otherwise.

### verifyResourceManifest()

```c++
static bool verifyResourceManifest(const std::filesystem::path& directory, const std::filesystem::path& path);
```

Verifies the integrity of all resource files in a directory against a manifest file.
This function loads the specified resource manifest and validates every regular file under the given
directory by comparing its relative path, file size and cryptographic hash against the manifest entries.
The manifest file itself is excluded from verification.

**Parameters:**
- `directory`: Root directory containing resource files.
- `path`: Output path of the generated manifest file.

**Returns:**
True if all resources match the manifest; false if any file is missing, corrupted or fails verification.

### signResourceManifest()

```c++
static bool signResourceManifest(
    const std::filesystem::path& manifestPath, const std::filesystem::path& signaturePath,
    const std::array<unsigned char, 64>& secretKey
);
```

Signs a resource manifest file using an Ed25519 detached digital signature.
This function reads the raw binary contents of the manifest file located and produces a detached Ed25519
signature over those exact bytes using the provided secret key. The manifest file must be written
deterministically (stable ordering, formatting and line endings) prior to signing; any modification to the
manifest after signing will cause signature verification to fail.

**Parameters:**

- `manifestPath`: Path to the manifest file to be signed.
- `signaturePath`: Output path for the detached signature file.
- `secretKey`: 64-byte Ed25519 secret key used to generate the signature.

**Returns:**
True if the manifest was successfully signed and the signature written, false otherwise.

### verifyResourceManifestSignature()
```c++
static bool verifyResourceManifestSignature(
    const std::filesystem::path& manifestPath, const std::filesystem::path& signaturePath,
    const std::array<unsigned char, 32>& publicKey
);
```

Verifies the detached digital signature of a resource manifest file.
This function loads the raw contents of the manifest file and verifies its detached Ed25519 signature
using the provided public key. Verification succeeds only if the manifest has not been modified since
signing and the signature was produced by the holder of the corresponding secret key.

- `manifestPath`: Path to the manifest file whose signature is to be verified.
- `signaturePath`: Path to the detached signature file.
- `publicKey`: 32-byte Ed25519 public key used for verification.

**Returns:**
True if the signature is valid; false if verification fails or files cannot be read.

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