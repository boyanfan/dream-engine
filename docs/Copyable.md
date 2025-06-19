# Copyable
The [Copyable](Copyable.md) interface defines a standard 
interface for creating deep or customized copies of engine
objects.

```c++
class Copyable;
```

Implementing classes must define the `copy()` method, 
allowing precise control over which should or should not 
be duplicated. This is commonly used to avoid copying 
transient or runtime-only data such as animation states,
input buffers, or network handles.

---

## Methods
Below is a list of methods that must be implemented to 
confirm the [Copyable](Copyable.md) interface.

### copy()
```c++
virtual Copyable* copy() const;
```
Creates a copy of the object. The exact behavior is 
defined by the implementing class. 

**Returns:**
A new dynamically allocated instance with copied data.

**Notes:**
All classes that inherit from Copyable must implement 
`copy()`. This interface is especially useful when:
- You want polymorphic cloning without knowing the exact type.
- You need to exclude volatile or runtime-only state from copies.
- You want to avoid relying on default or shallow copy constructors.
