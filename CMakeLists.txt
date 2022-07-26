cmake_minimum_required(VERSION 3.23.2)  # CMake version check
project(App)                            # Create project "SDL2-Game"
set(CMAKE_CXX_STANDARD 20)              # Enable c++20 standard

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/debug)

# Set linker flags to a constant
SET(GCC_COVERAGE_COMPILE_FLAGS "-m64 -g -Wall")
SET(GCC_COVERAGE_LINK_FLAGS    "-lSDL2main -lSDL2 -lSDL2_image")

# Add linker flag constants to cmake
 SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
 SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

 # Add all .cc and .h files inside the src/ folder to ${SOURCE_FILES}
file(GLOB SOURCE_FILES "src/*.cc" "src/.h")

# Add header files (-I include)
include_directories(include)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES} )

# build to bin/debug
install(TARGETS ${PROJECT_NAME} DESTINATION bin/debug)
install(FILES "main.cc" DESTINATION src)
