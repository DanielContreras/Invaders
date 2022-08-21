cmake_minimum_required(VERSION 3.1) # CMake version check
project(SpaceInvaders) # Create project "Space Invaders"
set(CMAKE_CXX_STANDARD 20) # Enable c++20 standard

# Add SDL2 CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dep/cmake/sdl2)

# Add SDL2 library
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
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
set(GCC_COVERAGE_COMPILE_FLAGS "-m64 -g -Wall")

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
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE spdlog::spdlog
  PRIVATE SDL2::Main
  PRIVATE SDL2::Image
  PRIVATE SDL2::TTF
  PRIVATE SDL2::Mixer)

# build to bin/debug
install(TARGETS ${PROJECT_NAME} DESTINATION bin/debug)
install(FILES "main.cc" DESTINATION src)
