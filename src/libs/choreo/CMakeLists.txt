# src/libs/choreo/CMakeLists.txt
cmake_minimum_required(VERSION 3.18)

project(Choreo)

# Add Choreo source files (adjust path if needed)
file(GLOB_RECURSE CHOREO_SRC "src/*.cpp")

# Add include directories for Choreo (adjust path if needed)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the library target
# Static library
add_library(choreo STATIC ${CHOREO_SRC})

# Optionally, if you want a DLL instead of a static library:
# add_library(choreo SHARED ${CHOREO_SRC})

# Specify the output directories for the library
set_target_properties(choreo PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

# Optionally link any dependencies (if needed)
# target_link_libraries(choreo some_dependency)