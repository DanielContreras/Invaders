# Space Invaders

Space Invaders written in C++ using the SDL2 library. This game does not use any other game libraries or graphics libraries; SDL2 will do the majority of this work. As a result, we can compile and run the application cross-platform. At the moment the supported platforms are Windows and Linux, as long as you have the dependencies installed. 

## Getting started

In the following steps we will go over the necessary programs required to build and run the project. 

### Prerequisites

- [CMake](https://cmake.org/download/)
- [SDL2](https://www.libsdl.org/index.php)
- [SDL2_image](https://github.com/libsdl-org/SDL_image)
- [SDL2_mixer](https://github.com/libsdl-org/SDL_mixer)
- [SDL2_ttf](https://github.com/libsdl-org/SDL_ttf)
- [spdlog](https://github.com/gabime/spdlog)

### Installation

On Linux all of the prerequisite packages can be installed by the distributions respective package manager. This is the preferred way to install all of the prerequisite packages since it makes compilation easier and faster. On Windows, however, you may not always have this option. In this case you are going to want to install the project and enable all of the git submodules. At the moment the git submodules for `SDL2` are using the `MSVC` development files. If you wish to compile with the `MinGW` development files then you will have to manually remove the dependencies from the `dep/` folder and install the proper ones. 

To install and enable the git submodules, you can run the following command:
```shell
git clone --recurse-submodules https://github.com/DanielContreras/SpaceInvaders && cd SpaceInvaders
```
However, if you have installed the prerequisite packages through your respective package manager, then you simply need to run
```shell
git clone https://github.com/DanielContreras/SpaceInvaders && cd SpaceInvaders
```

### Building and Running
The following steps can all be done from the root directory. First, we create the build directory.
```shell
cmake -B build
```
If you are using the `clangd` LSP, you can create the `compile_commands.json` at this point as well.
```shell
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 build/
```
And then to build the project we run
```shell
cmake --build build/
```
Similarily, if you need to clean the build files you can run
```shell
cmake --build build/ --target clean
```
On Linux this will create an executable that can be found in the `build/bin/debug/` folder. Similarily, on Windows this will create the executable in `build/x64/Debug/`. The executable `SpaceInvaders` will be found in these respective directories. On Linux you can run the executable with

```shell
./build/bin/debug/SpaceInvaders
```
and on Windows,
```shell
.\build\x64\Debug\SpaceInvaders
```

## License
This project is licensed under the MIT License - See the [License.md](https://github.com/DanielContreras/SDL2-Game/blob/main/LICENSE.md) file for details.
