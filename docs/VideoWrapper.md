# VideoWrapper

The [VideoWrapper](VideoWrapper.md) class provides a 
lightweight mechanism to defer video decoding until 
rendering time. It is managed by the 
[ResourceManager](ResourceManager.md).

```c++
struct VideoWrapper;
```

It stores the path to a video file and only constructs 
a [VideoDecoder](VideoDecoder.md) when `getVideoDecoder()` is called, 
allowing the caller to supply the current rendering 
window size at that moment.

---

## Methods

Below is a list and explanation of all public methods
provided by the [VideoWrapper](VideoWrapper.md) class.

### Constructor

```c++
explicit VideoWrapper(std::string filepath);
```
Constructs a [VideoWrapper](VideoWrapper.md) with the given video file path.

**Parameters:**
- `filepath`: Path to the video file (e.g., `.mp4` format).


### Destructor

```c++
~VideoWrapper();
```
Cleans up the internally allocated [VideoDecoder](VideoDecoder.md) if it was created.

### getVideoDecoder()

```c++
VideoDecoder* getVideoDecoder(GeometryProxy geometry);
```
Returns the internal [VideoDecoder](VideoDecoder.md) instance, creating it on the first call using the provided geometry (window size).

**Parameters:**
- `geometry`: A [GeometryProxy](GeometryProxy.md) object representing the window size to scale the video appropriately.

**Returns:**
- A pointer to the lazily initialized [VideoDecoder](VideoDecoder.md).

---

### Associated Type

[VideoDecoder](VideoDecoder.md) is the raw representation of video 
playback resources, providing direct rendering API like 
`onRender()`. Using its wrapper class [VideoWrapper](VideoWrapper.md)
and managed by the [ResourceManager](ResourceManager.md)
is preferred.

## Relationships
Below is the position of [VideoWrapper](VideoWrapper.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[VideoDecoder](VideoDecoder.md) <br>
[GeometryProxy](GeometryProxy.md) <br>
[ResourceManager](ResourceManager.md)