# Identifiable\<ID\>

The standard interface for objects that can be uniquely 
identified by an arbitrary identifier type.

```c++
template<typename ID> class Identifiable;
```

The template parameter `ID` is the type used to uniquely 
identify an object, it could be an integer, a string, or
even arbitrary custom identifier type. Dream Engine normally 
uses a `std::string` as the identifier.

---

## Requirements
Below is a list of methods that must be implemented to
conform to the [Identifiable\<ID\>](Identifiable.md) interface.

### getIdentifier()

```c++
ID getIdentifier() const;
```

**Returns:** The unique identifier of the object. 

---

## Relationships
Below is the position of [Identifiable\<ID\>](Identifiable.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforming Types
[GameObject](GameObject.md) <br>
[Scene](Scene.md)