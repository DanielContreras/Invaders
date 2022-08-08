# Space Invaders

Space Invaders written in C++ using the SDL2 library. This game does not use any other game libraries or graphics libraries; SDL2 will do the majority of this work. As a result, we can compile and run the application cross-platform. At the moment the supported platforms are Windows and Linux, as long as you have the dependancies installed. 

## Getting started

In the following steps we will go over the necessary programs required to build and run the project. 

### Prerequisites

- [CMake](https://cmake.org/download/)
- [SDL2](https://www.libsdl.org/index.php)
- [SDL2_image](https://github.com/libsdl-org/SDL_image)
- [SDL2_mixer](https://github.com/libsdl-org/SDL_mixer)
- [SDL2_ttf](https://github.com/libsdl-org/SDL_ttf)
- [spdlog](https://github.com/gabime/spdlog)

### Installing

To begin installation, you first clone the git repository.
```shell
git clone https://github.com/DanielContreras/SpaceInvaders && cd SpaceInvaders
```

### Building and Running
After cloning, we build the project
```shell
cmake -B build && build --build build/
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
