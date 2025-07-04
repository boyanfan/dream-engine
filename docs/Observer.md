# Observer\<T\>

The standard interface for objects that observe changes 
in an [Observable\<T\>](Observable.md) object, where 
the template parameters `T` is the type of data being observed.

```c++
template<typename T> class Observer;
```

Implementing classes must define the `onNotified()` method,
providing specific behavior when the observed data changes.

---

## Requirements
Below is a list of methods that must be implemented to
confirm the [Observer\<T\>](Observer.md) interface.

### onNotified()

```c++
void onNotified(const T& newValue);
```

Called when the observable object changes.

**Parameters:**
- `newValue`: The updated value emitted by the [Observable\<T\>](Observable.md) object.

---

## Relationships
Below is the position of [Observer\<T\>](Observer.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[Camera](Camera.md)

### See Also
[Observable\<T\>](Observable.md)
