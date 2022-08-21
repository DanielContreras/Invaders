# Space Invaders

Space Invaders written in C++ using the SDL2 library. This game does not use any other game libraries or graphics libraries; SDL2 will do the majority of this work. As a result, we can compile and run the application cross-platform. However, at the moment the `CMakeLists.txt` supports Linux only, as long as you have the dependencies installed. 

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

The `CMakeLists.txt` file searches your system for `spdlog` and for `SDL2`; if you are on Linux this means you should use your respective package manager to install these dependencies. The other dependencies will be pulled in as a git-submodule which CMake will resolve. 

First, we download the project and install the git-submodules, with the following command.
```shell
git clone --recurse-submodules https://github.com/DanielContreras/SpaceInvaders && cd SpaceInvaders
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
On Linux this will create an executable that can be found in the `build/bin/debug/` folder. You can run the program with

```shell
./build/bin/debug/SpaceInvaders
```

## License
This project is licensed under the MIT License - See the [License.md](https://github.com/DanielContreras/SDL2-Game/blob/main/LICENSE.md) file for details.
