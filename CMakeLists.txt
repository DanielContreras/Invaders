cmake_minimum_required(VERSION 3.1) # CMake version check
project(Invaders) # Create project "Invaders"
set(CMAKE_CXX_STANDARD 20) # Enable c++20 standard

if(WIN32)
  set(CMAKE_TOOLCHAIN_FILE
      "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif(WIN32)

if(UNIX)
  # Add SDL2 CMake modules
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dep/cmake/sdl2)
endif(UNIX)

# Add SDL2 library
find_package(SDL2 REQUIRED)
if(WIN32)
  find_package(SDL2-image REQUIRED)
endif(WIN32)
if(UNIX)
  find_package(SDL2_image REQUIRED)
endif(UNIX)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Look for spdlog package (has to be installed on system)
if(NOT TARGET spdlog)
  # Stand-alone build
  find_package(spdlog REQUIRED)
endif()

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/debug)

# Set linker flags to a constant
if(UNIX)
  set(GCC_COVERAGE_COMPILE_FLAGS "-m64 -g -Wall")
endif(UNIX)

# Add linker flag constants to cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# Add all .cc inside the src/ folder and sub-directories to ${SOURCE_FILES}
file(GLOB_RECURSE SOURCE_FILES "src/*.cc")

# Add header files (-I include)
include_directories(include dep/Eigen)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link spdlog pre-compiled library
if(WIN32)
  target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE spdlog::spdlog
    PRIVATE SDL2::SDL2
    PRIVATE SDL2::SDL2main
    PRIVATE SDL2::SDL2_image
    PRIVATE
      $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
    PRIVATE
      $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>
  )
elseif(UNIX)
  target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE spdlog::spdlog
    PRIVATE SDL2::Main
    PRIVATE SDL2::Image
    PRIVATE SDL2::TTF
    PRIVATE SDL2::Mixer)
endif(WIN32)
