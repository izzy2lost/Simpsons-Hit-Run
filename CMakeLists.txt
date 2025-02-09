cmake_minimum_required(VERSION 3.18)
project(SimpsonsHitRun)

# Set the C++ standard to use (adjust based on the project's needs)
set(CMAKE_CXX_STANDARD 17)

# Automatically find all .cpp files in the src/ directory and its subdirectories
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Add SDL2 include and library directories
include_directories(${PROJECT_SOURCE_DIR}/include/SDL2)
link_directories(${PROJECT_SOURCE_DIR}/lib/SDL2)

# Add Choreo include and library directories (if it's located in src/libs/choreo)
add_subdirectory(src/libs/choreo)  # This will build Choreo if it has its own CMakeLists.txt

# Find OpenGL package (required for OpenGL-based rendering)
find_package(OpenGL REQUIRED)

# Add executable target
add_executable(SimpsonsHitRun ${SOURCE_FILES})

# Link libraries (SDL2, OpenGL, and Choreo)
target_link_libraries(SimpsonsHitRun SDL2 OpenGL::GL choreo)  # Link to Choreo library target if available

# Optional: Link OpenAL if needed
# target_link_libraries(SimpsonsHitRun OpenAL::OpenAL)

# Optional: Install the executable
# install(TARGETS SimpsonsHitRun DESTINATION bin)
