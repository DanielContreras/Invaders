# Invaders

Space Invaders like game written in C++. For this project we use [SDL2](https://www.libsdl.org/) to handle the platform layer functions, such as audio and input. SDL2 will also handle the animations and rendering of the application. Using SDL2 allows the application to be built cross-platform with relative ease. We also use [spdlog](https://github.com/gabime/spdlog) for logging and [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) for a simple math library. 

## Getting started

In the following steps we will go over the necessary programs required to build and run the project. 

### Prerequisites

- [CMake](https://cmake.org/download/)
- [SDL2](https://www.libsdl.org/index.php)
- [SDL2_image](https://github.com/libsdl-org/SDL_image)
- [SDL2_mixer](https://github.com/libsdl-org/SDL_mixer)
- [SDL2_ttf](https://github.com/libsdl-org/SDL_ttf)
- [spdlog](https://github.com/gabime/spdlog)

## Installation

First, we download the project and install the git-submodules, with the following command
```shell
git clone --recurse-submodules https://github.com/DanielContreras/SpaceInvaders && cd SpaceInvaders
```
If you cloned the repository without `recurse-submodules` you can run
```shell
git submodule init && git submodule update
```

## Building and Running on Linux

The `CMakeLists.txt` file searches your system for `spdlog` and for `SDL2`; this means you should install the dependencies mentioned in the prerequisite section using your distributions respective package manager. For more information on installing these dependencies please visit their respective github pages. 

With your dependencies resolved you can continue on to creating the build directory. You can do this by running 
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
Similarly, if you need to clean the build files you can run
```shell
cmake --build build/ --target clean
```
After building, this creates an executable that can be found in the `build/bin/debug/` folder. You can run the program with

```shell
./build/bin/debug/SpaceInvaders
```

## Building and Running on Windows

If you are on Windows it is recommended that you use the [vcpkg](https://vcpkg.io/en/index.html) package manager to easily install the prerequisite packages. For more information on installing packages and setting up `vcpkg`, please visit their [getting started](https://vcpkg.io/en/getting-started.html) page. The `CMakeLists.txt` file currently searches your system for the necessary libraries. If you do not plan on using `vcpkg` then you will need to re-configure the build files yourself. 

Assuming you are using `vcpkg`, we begin by installing `vcpkg` from the project root directory
```shell
git clone https://github.com/Microsoft/vcpkg.git
```
Then we run the bootstrap script to build `vcpkg`
```shell
.\vcpkg\bootstrap-vcpkg.bat
```
Followed by installing the prerequisite packages necessary for building the project
```shell
.\vcpkg\vcpkg.exe install spdlog:x64-windows sdl2:x64-windows sdl2-ttf:x64-windows sdl2-image:x64-windows sdl2-mixer:x64-windows
```

Assuming you have installed the packages using `vcpkg` the next step is to build the project. To do this we first create the build files with
```shell
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake 
```
making sure to replace `[path to vcpkg]` with the actual path to this file. Next, we actually build the project using
```shell
cmake --build build/
```
Similarly, if you need to clean the build files you can run
```shell
cmake --build build/ --target clean
```
After building, this creates an executable that can be found in the `/build/bin/debug/Debug/` folder. You can run the program with
```shell
.\build\bin\debug\Debug\SpaceInvaders.exe 
```

## License
This project is licensed under the MIT License - See the [License.md](https://github.com/DanielContreras/SDL2-Game/blob/main/LICENSE) file for details.
