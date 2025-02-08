set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_VERSION 10.0)

# Set the architecture of the target system (x86_64 for 64-bit UWP)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Specify the C and C++ compilers to use
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Path to the UWP SDK (you might need to adjust this based on your environment)
set(CMAKE_UWP_SDK_PATH "C:/Program Files (x86)/Windows Kits/10/") 

# Set the UWP platform toolset version
set(CMAKE_TOOLCHAIN_FILE "C:/path/to/uwp-toolchain.cmake")

# Add additional settings or dependencies here if necessary
