# Logger
A singleton class used to output styled and scoped log 
messages to the console. Supports info, warning, and 
error levels.

```c++
class Logger final : public Singleton<Logger>
```

[Logger](Logger.md) class also offers utility methods to 
format common status messages related to initialization and 
file operations.

---

## Members

Below is a list and explanation of all public members
provided by the [Logger](Logger.md) class.
- `logScope`: A public field that defines the minimum severity level of log messages to be shown. Messages with lower severity will be ignored.

```c++
enum class LogScope { Info, Warning, Error };
```

---

## Methods

Below is a list and explanation of all public methods
provided by the [Logger](Logger.md) class.

### getInstance()

```c++
static Logger* getInstance();
```

Returns the singleton instance of [Logger](Logger.md).
This method is defined and inherited from the
[Singleton\<T\>](Singleton.md) base class.

**Returns:**
A pointer to the single, global [Logger](Logger.md) instance.

### log()

```c++
void log(LogScope logScope, const std::string& message) const;
```

Log a message to the console if it meets the current logging level threshold.

**Parameters:**
- `logScope`: Severity level of the message.
- `message`: The text to be logged.

### onDataAccess()

```c++
static std::string onDataAccess(const std::string& module, const std::string& data, bool state);
```

Constructs a message describing the access status of a specific data resource by a given module.

**Parameters:**
- `module`: The name of the module attempting to access the data.
- `data`: The name or path of the data resource being accessed.
- `state`: `LOG_SUCCESS` if the access was successful; `LOG_FAILURE` otherwise.

**Returns:**
A formatted string containing the resulting message about the data access operation.

### onInitialize()

```c++
static std::string onInitialize(const std::string& module, const std::string& target, bool state);
```

Creates a formatted message indicating the success or failure of a module’s initialization.

**Parameters:**
- `module`: The name of the module performing the initialization.
- `target`: The target being initialized.
- `state`: `LOG_SUCCESS` if initialization succeeded; `LOG_FAILURE` otherwise.

**Returns:**
A formatted string describing the initialization result.

### onDeinitialize()

```c++
static std::string onDeinitialize(const std::string& module, const std::string& target);
```

Creates a message indicating that a module has deinitialized a component.

**Parameters:**

- `module`: The name of the module performing the deinitialization.
- `target`: The target being deinitialized.

**Returns:**
A formatted string describing the deinitialization event.

### onFileLoad()

```c++
static std::string onFileLoad(const std::string& module, const std::string& filepath, bool state);
```

Creates a message indicating the success or failure of a file load operation.

**Parameters:**

- `module`: The name of the module performing the load.
- `filepath`: The path to the file being loaded.
- `state`: `LOG_SUCCESS` if the file was loaded successfully; `LOG_FAILURE` otherwise.

**Returns:**
A formatted string describing the file loading result.

### onFileUnload()

```c++
static std::string onFileUnload(const std::string& module, const std::string& filepath);
```

Creates a message indicating that a file has been closed or unloaded.

**Parameters:**

- `module`: The name of the module performing the unloading.
- `filepath`: The path to the file being closed.

**Returns:**
A formatted string describing the file unload event.


### getFilepath()

```c++
static std::string getFilepath(const std::string& filepath);
```

Formats and stylizes the given file path for logging purposes.

**Parameters:**
- `filepath`: The file path to be stylized and included in log messages.

**Returns:**
A formatted string containing the stylized file path.

### getMessageModule()

```c++
static std::string getMessageModule(const std::string& module);
```

Returns a stylized string representation of the given module name.

**Parameters:**
- `module`: The name of the module.

**Returns:**
A formatted string containing the stylized module.

---

## Macros

To simplify logging and enforce consistent style, 
macros are preferred over direct use of the `log()` method:


- `LOG_SUCCESS`: A flag for a successful action.
- `LOG_FAILURE`: A flag for an unsuccessful action.
- `LOG_INFO(message)`: Log an information level message.
- `LOG_WARNING(message)`: Log a warning level message.
- `LOG_ERROR(message)`: Log an error level message.

---

## Example Usage

```c++
const std::string message = Logger::onInitialize(SomeClass::self, AnotherClass::self, LOG_FAILURE);
LOG_ERROR(message)
```

---

## Reflection

The [Logger](Logger.md) class provides basic
reflection by storing its own class name, which can be
accessed via `Logger::self`.

---

## Relationships
Below is the position of [Logger](Logger.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Singleton\<T\>](Singleton.md)

### See Also
[Application](Application.md) <br>
[WindowConfiguration](WindowConfiguration.md)