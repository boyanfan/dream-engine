# WindowConfiguration

The [WindowConfiguration](WindowConfiguration.md) class 
holds the basic window properties and the target frame rate 
for a DreamEngine application. It is used to configure 
the application window and control the main loop timing 
when creating an instance of [Application](Application.md).

```c++
class WindowConfiguration;
```

It also supports loading configuration from an external 
file, allowing easy customization of window settings.

---

## Members

Below is a list and explanation of all public members
provided by the [WindowConfiguration](WindowConfiguration.md) class.

- `std::string title`: The title of the application window.

- `int width`: The width of the window in pixels. Defaults to `1280`.

- `int height`: The height of the window in pixels. Defaults to `720`.

- `int frameRate`: The desired target frame rate in frames per second. Defaults to `60`.

---

## Methods

Below is a list and explanation of all public methods
provided by the [WindowConfiguration](WindowConfiguration.md) class.

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
- filepath: The file path to the configuration file.

**Returns:**
true if the file was successfully loaded and all values were parsed.

---

## Reflection

The [WindowConfiguration](WindowConfiguration.md) class provides basic
reflection by storing its own class name, which can be
accessed via `WindowConfiguration::self`. This feature is commonly
used by other classes such as [Logger](Logger.md).

```c++
static inline std::string self;
```

---

## Relationships
Below is the position of [WindowConfiguration](WindowConfiguration.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[Application](Application.md)