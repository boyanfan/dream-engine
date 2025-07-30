# BarView

A UI component that displays a progress bar with optional 
trailing animation and title support.

```c++
class BarView : public View;
```

**Fields:**
- `float maxProgress`: The maximum progress value this bar can represent.
- `float currentProgress`: The current progress value to be rendered.
- `float trailingSpeed`: The speed at which the trailing bar catches up to the current progress.
- `float trailingDelay`: The delay (in seconds) before the trailing effect begins.
- `bool isTrailingEnabled`: A flag indicating whether the trailing animation is active.
- `Color foregroundColor`: The [Color](Color.md) used for the filled (foreground) portion of the bar.
- `Color backgroundColor`: The [Color](Color.md) used for the unfilled (background) portion of the bar.
- `Color outlineColor`: The [Color](Color.md) of the outline around the bar.
- `Color trailingColor`: The [Color](Color.md) of the trailing progress indicator.
- `float outlineWidth`: The width of the outline stroke.
- `std::string titleContent`: The text content displayed as a title on the bar.
- `std::string titleFont`: The font family used for the title text.
- `float titleFontSize`: The base font size for the title text.
- `float titleScaleFactor`: A scaling factor applied to the title font size.
- `Color titleColor`: The color of the title text.
- `Alignment titleAlignment`: [Alignment](Alignment.md) of the title within the bar (e.g., center, leading).
- `EdgeInsets titlePaddings`: Padding [EdgeInsects](EdgeInsets.md) values around the title for layout spacing.

---

## Methods

Below is a list and explanation of all public methods
provided by the [BarView](BarView.md) class.

### Constructor

```c++
explicit BarView(float maxProgress);
```

Initializes the bar with specified maximum progress.

**Parameters:**
- `maxProgress`: The maximum progress this bar can represent.

### onUpdate()

```c++
void onUpdate(float interval);
```

Updates animation and internal values based on time delta.

**Parameters:**
- `interval`: Time elapsed since the last update.

### onRender()

```c++
void onRender(const Camera& camera) const;
```

Renders the progress bar to the screen using the provided camera.

**Parameters:**
- `camera`: [Camera](../core/Camera.md) reference for coordinate transformation.

---

## Relationships
Below is the position of [View](View.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Confirms To
[View](View.md) <br>
[Updatable](../core/Updatable.md) <br>
[Renderable](../core/Renderable.md)

### See Also
[Color](Color.md) <br>
[Alignment](Alignment.md) <br>
[EdgeInsets](EdgeInsets.md) <br>
[Camera](../core/Camera.md)