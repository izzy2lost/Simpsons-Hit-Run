cmake_minimum_required(VERSION 3.18)  # Or the version that matches your setup
project(SimpsonsHitRun)

# Set the C++ standard to use (adjust based on the project's needs)
set(CMAKE_CXX_STANDARD 17)

# Specify the source files to be compiled (add all your source files here)
set(SOURCE_FILES
    src/main.cpp  # Example: Replace with the actual source file paths
    # Add other source files as needed
)

# Add executable target
add_executable(SimpsonsHitRun ${SOURCE_FILES})

# If using external libraries, link them here (for example, SDL2 or OpenAL)
# target_link_libraries(SimpsonsHitRun SDL2 OpenAL)

# Set the installation location (optional)
# install(TARGETS SimpsonsHitRun DESTINATION bin)
