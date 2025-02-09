cmake_minimum_required(VERSION 3.18)
project(SimpsonsHitRun)

# Set the C++ standard to use (adjust based on the project's needs)
set(CMAKE_CXX_STANDARD 17)

# Automatically find all .cpp files in the src/ directory and its subdirectories
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Add SDL2 include and library directories
include_directories(${PROJECT_SOURCE_DIR}/include/SDL2)
link_directories(${PROJECT_SOURCE_DIR}/lib/SDL2)

# Add GLAD include and library directories
include_directories(${PROJECT_SOURCE_DIR}/include/glad)  # Adjust path to where GLAD headers are located
link_directories(${PROJECT_SOURCE_DIR}/lib/glad)        # Adjust path to where GLAD libraries are located

# Add Mesa include and library directories
include_directories(${PROJECT_SOURCE_DIR}/include/mesa)  # Adjust path to where Mesa headers are located
link_directories(${PROJECT_SOURCE_DIR}/lib/mesa)        # Adjust path to where Mesa libraries are located

# Add OpenAL include and library directories (from the aerisarn fork or your own build)
include_directories(${PROJECT_SOURCE_DIR}/include/openal)
link_directories(${PROJECT_SOURCE_DIR}/lib/openal)

# Add Choreo include and library directories (if it's located in src/libs/choreo)
add_subdirectory(src/libs/choreo)  # This will build Choreo if it has its own CMakeLists.txt

# Add SDL2, GLAD, Mesa, and OpenAL as link libraries
add_executable(SimpsonsHitRun ${SOURCE_FILES})

# Link libraries (SDL2, OpenGL, Mesa, GLAD, Choreo, OpenAL)
target_link_libraries(SimpsonsHitRun 
    SDL2
    OpenGL::GL  # Standard OpenGL package
    glad        # Link to GLAD for OpenGL extensions
    mesa        # Link to Mesa (assumes Mesa built as a library)
    choreo      # Link to Choreo library target if available
    openal-soft # If OpenAL Soft is being used (adjust based on your setup)
)

# Optional: Install the executable
# install(TARGETS SimpsonsHitRun DESTINATION bin)

# UWP-specific settings (if building for UWP)
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
