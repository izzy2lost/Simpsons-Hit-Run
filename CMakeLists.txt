cmake_minimum_required(VERSION 3.18)
project(SimpsonsHitRun)

# Set the C++ standard to use (adjust based on the project's needs)
set(CMAKE_CXX_STANDARD 17)

# Automatically find all .cpp files in the src/ directory and its subdirectories
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Find OpenGL package (required for OpenGL-based rendering)
find_package(OpenGL REQUIRED)

# Add the main executable
add_executable(SimpsonsHitRun ${SOURCE_FILES})

# Add SDL2, GLAD, Mesa, and OpenAL include directories
target_include_directories(SimpsonsHitRun PRIVATE
    ${PROJECT_SOURCE_DIR}/include/SDL2
    ${PROJECT_SOURCE_DIR}/include/glad
    ${PROJECT_SOURCE_DIR}/include/mesa
    ${PROJECT_SOURCE_DIR}/include/openal
)

# Link the necessary libraries
target_link_directories(SimpsonsHitRun PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/SDL2
    ${PROJECT_SOURCE_DIR}/lib/glad
    ${PROJECT_SOURCE_DIR}/lib/mesa
    ${PROJECT_SOURCE_DIR}/lib/openal
)

# Add Choreo subdirectory (this assumes a CMakeLists.txt exists for Choreo)
add_subdirectory(src/libs/choreo)

# Link libraries to the project
target_link_libraries(SimpsonsHitRun PRIVATE
    SDL2
    OpenGL::GL
    glad
    mesa
    choreo
    openal-soft
)

# UWP-specific settings (only applied for MSVC)
if(MSVC)
    # Enable UWP platform
    set(CMAKE_SYSTEM_NAME WindowsStore)
    set(CMAKE_SYSTEM_VERSION 10.0)
    set(CMAKE_VS_PLATFORM_TOOLSET "v143")  # Adjust based on your Visual Studio version
    
    # Add UWP-specific compile and link flags
    add_compile_options("/D _XBOX_UWP")
    add_link_options("/D _XBOX_UWP")
    
    # Set platform-specific properties
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_UNICODE /DUNICODE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MT")  # Use static runtime if needed
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")
endif()