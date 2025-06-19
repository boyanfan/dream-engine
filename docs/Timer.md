# Timer
The [Timer](Timer.md) class is a utility designed to handle 
timed events in a game. 

```c++
class Timer : public Updatable;
```

It supports executing a callback function after a specified
 duration and includes control over pausing, resuming, 
repeating, and restarting the timer. It implements the 
[Updatable](Updatable.md) interface and is meant to be 
updated every frame.

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
and callback.


### setDuration()

```c++
void setDuration(float duration);
```

Sets the duration the timer will wait before firing the timeout event.

**Parameters:**
- `duration`: Time in seconds to wait before triggering.


### setOnTimeout()

```c++
void setOnTimeout(const std::function<void()>& callback);
```

Sets the function to be called when the timer times out.

**Parameters:**
- `callback`: A function with no arguments and no return value.


### setRepeating()

```c++
void setRepeating(bool flag);
```

Controls whether the timer repeats after firing.

**Parameters:**
- `flag`: `true` for repeating mode; `false` for one-shot behavior.

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

---

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