# Timer
A utility designed to handle 
timed events in a game. It implements the
[Updatable](Updatable.md) interface and is meant to be
updated every frame.

```c++
class Timer : public Updatable;
```

It supports executing a callback function after a specified
 duration and includes control over pausing, resuming, 
repeating, and restarting the timer.

**Fields:**
- `float duration`: The duration of the timer waits, in seconds.
- `bool isRepeating`: Whether the timer is in repeating mode or one-shot mode.

---

## Methods

Below is a list and explanation of all public methods
provided by the [Timer](Timer.md) class.

### Constructor

```c++
Timer();
```

The default constructor for the Timer class.

### Destructor

```c++
~Timer();
```

The default destructor for the Timer class.

### restart()

```c++
void restart();
```

Resets the timer with the same duration, repeat mode, 
and callback. Sets the duration the timer will wait before firing the timeout event.

**Parameters:**
- `duration`: Time in seconds to wait before triggering.


### setOnTimeout()

```c++
void setOnTimeout(const std::function<void()>& callback);
```

Sets the function to be called when the timer times out.

**Parameters:**
- `callback`: A function with no arguments and no return value.

### pause()

```c++
void pause();
```

Pauses the timer. While paused, `onUpdate()` will have no effect.

### resume()

```c++
void resume();
```

Resumes the timer from its paused state.

### onUpdate()

```c++
void onUpdate(float interval) override;
```

Advances the timer and checks if the timeout should be triggered.

**Parameters:**
- `interval`: Time (in seconds) since the last update.

---

## Relationships
Below is the position of [Timer](Timer.md)
within the type hierarchy, including which classes inherit
from it and which base classes it derives from.

### Conforms To
[Updatable](Updatable.md)