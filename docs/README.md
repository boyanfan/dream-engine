# Dream Engine Documentation

Welcome to the documentation for Dream Engine. This section serves as a comprehensive
guide for developers aiming to understand, extend, and build with the engine. Whether 
you're integrating Dream Engine into a new game project or exploring its internal 
architecture, the documentation provides structured insights into how the engine works 
and how to use it effectively.

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