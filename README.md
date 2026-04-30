````markdown
# coreLib

coreLib is an experimental C++ project for rebuilding foundational library components from first principles.

This project uses a Core/App architecture:

- `Core` builds into a static library.
- `App` builds into an executable and links against `Core`.
- Library code lives in the `core` namespace.
- `App` is used for testing and exploration.

## Structure

```text
coreLib
│
├─ Core
│  └─ Source
│     └─ core
│
├─ App
│  └─ Source
│
├─ Scripts
├─ Vendor
└─ Build.lua
````

## Core

`Core` contains the reusable library code.

Library code should live inside the `core` namespace:

```cpp
namespace core
{

}
```

Application code may use a namespace alias:

```cpp
namespace ns = core;
```

Example:

```cpp
ns::cout << "Hello from coreLib\n";
```

## App

`App` is the executable project.

It is mainly used to test and experiment with the code in `Core`.

## Build System

This project uses Premake to generate project files.

Important files:

* `Build.lua`
* `Core/Build-Core.lua`
* `App/Build-App.lua`

On Windows, run:

```text
Scripts/Setup-Windows.bat
```

Then open the generated Visual Studio solution.


## Credits

This project is based on a C++ Core/App project template using Premake from The Cherno.

Premake binaries are included in `Vendor/`.

## License

The original template is released under the UNLICENSE.

Premake is licensed under the BSD 3-Clause license.
