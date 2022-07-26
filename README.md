# SDL2-Game
Simple "game" made using C++ and SDL2

## Getting started

In order to install and build the project we will explore some packages you are going to need.

### Prerequisites

- [CMake](https://cmake.org/download/)
- [SDL2](https://www.libsdl.org/index.php)
- [SDL2_image](https://github.com/libsdl-org/SDL_image)

### Installing and Building

To begin installation, you first clone the git repository.
```shell
git clone https://github.com/DanielContreras/SDL2-Game && cd SDL2-Game
```
After cloning we build the project
```
cmake -B build && build --build build/
```
From here, anytime we wish to build the project going forward, we can simply run
```
cmake --build build/
```
This will create an executable that can be found in the `build/bin/debug` folder and will be called `App`. You can run the executable by running
```
./build/bin/debug/App
```

## License
This project is licensed under the MIT License - See the [License.md](https://github.com/DanielContreras/SDL2-Game/blob/main/LICENSE.md) file for details.
