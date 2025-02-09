# Initialize vcpkg if it's not already initialized
if (-not (Test-Path -Path "vcpkg")) {
    Write-Host "Cloning vcpkg..."
    git clone https://github.com/microsoft/vcpkg.git
}

# Navigate to the vcpkg directory
cd vcpkg

# Bootstrap vcpkg if not already bootstrapped
if (-not (Test-Path -Path "vcpkg.exe")) {
    Write-Host "Bootstrapping vcpkg..."
    .\bootstrap-vcpkg.bat
}

# Install required dependencies
Write-Host "Installing dependencies..."
.\vcpkg install sdl2 openal-soft glad --triplet x64-uwp

# Return to the root of the repository
cd ..

Write-Host "vcpkg setup and dependencies installed."