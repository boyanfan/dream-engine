# Dream Engine Documentation

Welcome to the documentation for Dream Engine. This section serves as a comprehensive
guide for developers aiming to understand, extend, and build with the engine. Whether 
you're integrating Dream Engine into a new game project or exploring its internal 
architecture, the documentation provides structured insights into how the engine works 
and how to use it effectively.

---

## A Dream Engine Tour

Updating, available sooner...

---

## Core API Reference
This section provides a complete index of all 
classes, data types, and interfaces available in the Dream Engine
Core Library. These components form the foundation of the engine, 
offering essential functionality for game development.
All the components listed below are included 
in the `engine/core.h` header file.

### Interfaces

- [Copyable](core/Copyable.md)
- [Identifiable\<ID\>](core/Identifiable.md)
- [Renderable](core/Renderable.md)
- [Updatable](core/Updatable.md)
- [Interactable](core/Interactable.md)
- [Singleton\<T\>](core/Singleton.md)
- [Scene](core/Scene.md)
- [Observable\<T\>](core/Observable.md)
- [Observer\<T\>](core/Observer.md)
- [State](core/State.md)
- [GameObject](core/Interactable.md)

### Classes

- [Application](core/Application.md)
- [ResourceManager](core/ResourceManager.md)
- [SceneManager](core/SceneManager.md)
- [CollisionManager](core/CollisionManager.md)
- [FiniteStateMachine](core/FiniteStateMachine.md)
- [Camera](core/Camera.md)
- [Animation](core/Animation.md)
- [Logger](core/Logger.md)
- [Timer](core/Timer.md)
- [TextureSequence](core/TextureSequence.md)
- [VideoDecoder](core/VideoDecoder.md)

### Data Types
- [WindowConfiguration](core/WindowConfiguration.md)
- [GeometryProxy](core/GeometryProxy.md)
- [Transform](core/Transform.md)
- [CollisionBox](core/CollisionBox.md)
- [Mathematics\<T\>](core/Mathematics.md)
- [FontRepresentable](core/FontRepresentable.md)
- [VideoRepresentable](core/VideoRepresentable.md)
- [TextureRepresentable](core/TextureRepresentable.md)
- [Vector2](core/Vector2.md)

---

## UI API Reference
This section provides a complete index of all
classes, data types, and interfaces available in the Dream Engine
UI Library. Whether you're implementing simple buttons or
complex view hierarchies, this reference serves as your
go-to resource. All the components listed below are included
in the `engine/ui.h` header file.

### Interfaces
- [View](ui/View.md)

### Classes
- [BarView](ui/BarView.md)

### Data Types
- [Color](ui/Color.md)
- [Alignment](ui/Alignment.md)
- [EdgeInsets](ui/EdgeInsets.md)