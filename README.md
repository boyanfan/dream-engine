# Dream Engine

Dream Engine is a lightweight and modular 2D game 
engine written in modern C++. It provides essential 
utilities and abstractions to help you build simple 
games efficiently and cleanly.

---

## Getting Started
Clone the repository from the GitHub using the 
following command.

```bash
git clone https://github.com/boyanfan/dream-engine.git
cd dream-engine
```

Before building Dream Engine, make sure **SDL3**, 
**CMake**, and **PkgConfig** have been installed. 
You can check them from your terminal using the
following commands.

```bash
cmake --version
pkg-config --version
pkg-config --modversion sdl3
```

Then you can build it using the following commands.
By default, Dream Engine builds as a static library.

```bash
mkdir build && cd build
cmake .. && make
```

## Using Dream Engine in Your Project
To use Dream Engine in your own CMake-based 
projects, you can either install Dream Engine 
to a system or local path or include it as a 
subdirectory. If you choose the latter 
(without installation), your `CMakeLists.txt`
configuration may include the following fields.

```cmake
add_subdirectory(dream-engine)
target_link_libraries(${PROJECT_NAME} PRIVATE dream_engine)
target_include_directories(${PROJECT_NAME} PRIVATE dream-engine/core/include)
```

---

## Next Step

To get the most out of the Dream Engine, we highly encourage 
developers to explore the [Dream Engine Documentation](docs/README.md),
It provides clear, structured guidance on how to use 
core classes, extend engine features, and build 
polished 2D games efficiently.