# VideoDecoder
The [VideoDecoder](VideoDecoder.md) class is responsible for 
decoding and rendering a video file frame-by-frame using 
`Fmpeg` and `SDL`. 

```c++
class VideoDecoder : public Renderable;
```

This class implements from [Renderable](Renderable.md) interface 
and provides the `onRender()` method to handle video frame presentation.
The video is scaled to match the rendering window size.

---

## Methods

Below is a list and explanation of all public methods
provided by the [VideoDecoder](VideoDecoder.md) class.

### Constructor

```c++
VideoDecoder(const std::string& filepath, int windowWidth, int windowHeight);
```

Constructs a [VideoDecoder](VideoDecoder.md) object by 
loading and preparing the video file for decoding.

**Parameters:**
- `filepath`: Path to the video file to decode.
- `windowWidth`: Width of the rendering window.
- `windowHeight`: Height of the rendering window.

### Destructor

```c++
~VideoDecoder();
```

Cleans up all associated FFmpeg and SDL resources, including textures, frames, and codec contexts.

### onRender()

```c++
void onRender(const Camera& camera) const override;
```

Renders the next frame of the video using the provided camera.

**Parameters:**
`camera`: The [Camera](Camera.md) used to display the video, handling coordinate transforms and rendering context.

This function should be called once per frame.
It automatically decodes and synchronizes one video frame based on presentation timestamps (PTS), ensuring accurate playback timing.
All rendering is performed through the camera to support effects like scaling, parallax, and screen fitting.

---

## Reflection

The [VideoDecoder](VideoDecoder.md) class provides basic
reflection by storing its own class name, which can be
accessed via `Application::self`.

---

## Associated Type

[VideoWrapper](VideoWrapper.md) is a lightweight
container that defers the creation of a [VideoDecoder](VideoDecoder.md)
until rendering begins, allowing dynamic resolution
setup based on the current window geometry.

---

## Relationships
Below is the position of [VideoDecoder](VideoDecoder.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Renderable](Renderable.md)

### See Also
[VideoWrapper](VideoWrapper.md) <br>
[Camera](Camera.md)