# Singleton\<T\>

[Singleton\<T\>](Singleton.md) is a generic interface for enforcing 
the singleton pattern in C++ applications. It provides 
a centralized, reusable, and type-safe implementation 
that ensures only one instance of a derived class can exist at runtime.

```c++
template<typename T> class Singleton;
```

It enforces the singleton pattern, prevents copying 
and moving of the singleton instance, and supports 
inheritance and virtual destruction for cleanup.

---

## Methods

Below is a list and explanation of all public methods
provided by the [Singleton\<T\>](Singleton.md) class.

### getInstance()
```c++
static T* getInstance();
```
Returns a pointer to the singleton instance of type T. 
If it has not been created yet, it will be constructed 
using the default constructor.

---

## Example Usage

To make a class a singleton, inherit from 
`Singleton<T>` and declare `friend class Singleton<T>`.

```c++
class SomeManager : public Singleton<SomeManager> { friend class Singleton<SomeManager>;
    ...
}

// Then access the instance with
SomeManager* manager = SomeManager::getInstance();
```

---

## Deleted Operations
To ensure that [Singleton\<T\>](Singleton.md) remains a singleton,
all copy and move operations are explicitly deleted.
This prevents accidental duplication or reassignment
of the singleton instance, which could lead to
multiple resource pools and undefined behavior.

```c++
Singleton(const Singleton&) = delete;
Singleton(Singleton&&) = delete;
Singleton& operator =(const Singleton&) = delete;
Singleton& operator =(Singleton&&) = delete;
```

In the singleton pattern, it is critical that only one
instance of the class exists throughout the program's
lifetime. By deleting:

- Copy constructor: prevents creating a new instance by copying.
- Move constructor: prevents moving the instance into a new object.
- Copy assignment operator: prevents assigning one ResourceManager to another.
- Move assignment operator: prevents moving one ResourceManager into another.

This guarantees that the singleton instance created
via `getInstance()` remains unique and immutable in
identity.

### Misuses Prevented

```c++
class SomeManager : public Singleton<SomeManager>;

// These would be compile-time errors:
SomeManager a = *SomeManager::getInstance();
SomeManager b = std::move(*SomeManager::getInstance());
a = *SomeManager::getInstance();
b = std::move(*SomeManager::getInstance());
```

---

## Relationships 
Below is the position of [Singleton\<T\>](Singleton.md) 
within the type hierarchy, including which classes inherit 
from it and which base classes it derives from.

### Conforming Types
[ResourceManager](ResourceManager.md) <br>
[Logger](Logger.md)