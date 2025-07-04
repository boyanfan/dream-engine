# Observable\<T\>

The standard interface for objects that emit change 
notifications to registered [Observer\<T\>](Observer.md),
where the template parameters `T` is the type of data being observed.

```c++
template<typename T> class Observable;
```

---

## Methods
Below is a list and explanation of all public methods
provided by the [Observable\<T\>](Observable.md) interface.

### addObserver()

```c++
registerObserver(Observer<T>* observer);
```

Registers a new observer to be notified when the observable changes.

**Parameters:**
- `observer`: A pointer to the [Observer\<T\>](Observer.md) instance to add.

### removeObserver()

```c++
removeObserver(Observer<T>* observer);
```

Unregisters a previously added observer.

**Parameters:**
- `observer`: A pointer to the [Observer\<T\>](Observer.md) instance to remove.

### notify()

```c++
void notify(const T& newValue) const;
```

Notifies all currently registered observers with a new value.

**Parameters:**
- `newValue`: The updated value to be propagated to observers.

---

## Relationships
Below is the position of [Observable\<T\>](Observable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### See Also
[Observer\<T\>](Observer.md)