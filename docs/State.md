# State

The standard interface represents a generic state in the 
game or application, typically managed by a 
[FiniteStateMachine](FiniteStateMachine.md) (FSM). 
Each state must define its behavior when it 
becomes active or inactive.

```c++
class State : public Updatable;
```

Conforming to the [State](State.md) interface
also requires implementing the [Updatable](Updatable.md)
and [Identifiable\<ID\>](Identifiable.md) interfaces,
 providing per-frame update logic.

---

## Requirements
Below is a list of methods that must be implemented to
conform to the [State](State.md) interface.

### onEntry()

```c++
virtual void onEntry();
```

Called when the state becomes active or is entered.

### onExit

```c++
virtual void onExit();
```
Called when the state is no longer active or is exited.

---

## Relationships
Below is the position of [State](State.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Updatable](Updatable.md)

### See Also
[FiniteStateMachine](FiniteStateMachine.md)