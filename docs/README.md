# Dream Engine Documentation

Welcome to the documentation for Dream Engine. This section serves as a comprehensive
guide for developers aiming to understand, extend, and build with the engine. Whether 
you're integrating Dream Engine into a new game project or exploring its internal 
architecture, the documentation provides structured insights into how the engine works 
and how to use it effectively.

---

## A Dream Engine Tour

At the heart of every DreamEngine game is the 
[Application](Application.md) class — a virtual base 
class that serves as the program’s entry point. 
It encapsulates all the core runtime behaviors,
so developers can focus purely on implementing game logic. 
By inheriting from Application and overriding key methods, 
you can build your entire game without worrying about 
the underlying system setup.

The [ResourceManager](ResourceManager.md) class is a 
global singleton designed to simplify asset management
across your game. It handles automatic loading, caching, 
and unloading of various kinds of resources.

---

## Core API Reference
This section provides a complete index of all core 
classes and interfaces available in Dream Engine. 
These components form the foundation of the engine, 
offering essential functionality for game development.

### Interfaces

- [Copyable](Copyable.md)
- [Renderable](Renderable.md)
- [Updatable](Updatable.md)
- [Singleton\<T\>](Singleton.md)
- [Application](Application.md)

### Classes

- [ResourceManager](ResourceManager.md)
- [Camera](Camera.md)
- [Logger](Logger.md)
- [Timer](Timer.md)
- [VideoDecoder](VideoDecoder.md)

### Data Structures
- [WindowConfiguration](WindowConfiguration.md)
- [GeometryProxy](GeometryProxy.md)
- [FontRepresentable](FontRepresentable.md)
- [VideoRepresentable](VideoRepresentable.md)
- [TextureRepresentable](TextureRepresentable.md)
- [TextureSequence](TextureSequence.md)
- [Vector2](Vector2.md)