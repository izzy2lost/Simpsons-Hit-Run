#!/bin/bash

# Find all .vcxproj files recursively
find . -name "*.vcxproj" | while read file; do
    echo "Processing: $file"

    # Check if x64 already exists
    if grep -q '<ProjectConfiguration Include="Release|x64">' "$file"; then
        echo "x64 already exists in $file"
    else
        echo "Adding x64 configuration to $file"

        # Duplicate Win32 configurations and replace with x64
        awk '
        /<ProjectConfiguration Include="Release\|Win32">/ { 
            print $0; sub("Win32", "x64", $0); print $0; next 
        }
        /<ProjectConfiguration Include="Debug\|Win32">/ { 
            print $0; sub("Win32", "x64", $0); print $0; next 
        }
        /<PropertyGroup Condition='\''\$\w+\|\$\w+'\''=="(Debug|Release)\|Win32" / { 
            print $0; sub("Win32", "x64", $0); print $0; next 
        }
        { print }
        ' "$file" > "$file.tmp" && mv "$file.tmp" "$file"
    fi
done