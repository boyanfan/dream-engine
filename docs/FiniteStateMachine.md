# FiniteStateMachine

It manages transitions between multiple [State](State.md) 
instances. Each state is uniquely identified by 
confirming [Identifiable\<ID\>](Identifiable.md) interface. 

```c++
class FiniteStateMachine final : public Updatable;
```

The FSM handles state registration, transitions, and 
delegates per-frame updates to the active state.

---

## Methods

Below is a list and explanation of all public methods
provided by the [FiniteStateMachine](FiniteStateMachine.md) class.

### Constructor

```c++
FiniteStateMachine();
```

Constructs an empty finite state machine.

### Destructor

```c++
~FiniteStateMachine();
```
Destructor override to ensure proper cleanup.

### switchCurrentState()

```c++
void switchCurrentState(State* state):
```
Transitions the FSM to the provided [State](State.md).

**Parameters:**
- `state`: A pointer to the [State](State.md) to switch to.

### onUpdate()

```c++
void onUpdate(float interval);
```

Updates the currently active state. Should be called once per frame.

**Parameters:**
- `interval`: The elapsed time since the last update, in seconds.

---

## Relationships
Below is the position of [FiniteStateMachine](FiniteStateMachine.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Updatable](Updatable.md)

### See Also
[State](State.md)