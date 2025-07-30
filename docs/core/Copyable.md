# Copyable
The standard interface for creating deep or customized copies of 
engine objects. It allows runtime-polymorphic cloning without knowing the 
exact type.

```c++
class Copyable;
```

Implementing classes must define the `copy()` method, 
allowing precise control over which should or should not 
be duplicated. This is commonly used to avoid copying 
transient or runtime-only data such as animation states,
input buffers, or network handles.

---

## Requirements
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

---

## Relationships
Below is the position of [Copyable](Copyable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.