# WindowConfiguration

The [WindowConfiguration](WindowConfiguration.md) type 
holds the basic window properties
for a Dream Engine [Application](Application.md) 
when initializing it.

```c++
struct WindowConfiguration;
```

It also supports loading configuration from an external 
file, allowing easy customization of window settings.

**Fields:**

- `std::string title`: The title of the application window.

- `Vector2 size`: The width and height of the window in pixels, represented by a [Vector2](Vector2.md).

- `int frameRate`: The desired target frame rate in frames per second.

---

## Methods

Below is a list and explanation of all public methods
provided by the [WindowConfiguration](WindowConfiguration.md) type.

### Constructor

```c++
WindowConfiguration();
```

Default constructor. Initializes all fields with default values.

### Destructor

```c++
~WindowConfiguration();
```

Default destructor. Performs no special cleanup.

### configurateFromFile()

```c++
bool configurateFromFile(const std::string& filepath);
```

Loads configuration values from a plain text file 
containing key-value pairs. This allows customizing 
the application window without modifying the source code 
in the expected format:

```config
title=MyGame
width=1280
height=720
frameRate=60
```

**Parameters:**
- `filepath`: The file path to the configuration file.

**Returns:**
true if the file was successfully loaded and all values were parsed.

---

## Relationships
Below is the position of [WindowConfiguration](WindowConfiguration.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[Vector2](Vector2.md)