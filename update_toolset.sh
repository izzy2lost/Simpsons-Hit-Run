#!/bin/bash

# Directory to search for .sln files (you can adjust this if needed)
search_dir="."

# Recursively find all .sln files
find "$search_dir" -name "*.sln" | while read sln_file; do
    echo "Processing solution: $sln_file"
    
    # Get the paths to all .vcxproj files referenced in the .sln file
    grep -oP '(?<=Project".*".*)\K[^"]*\.vcxproj' "$sln_file" | while read vcxproj_file; do
        # Make sure the .vcxproj file exists
        if [[ -f "$vcxproj_file" ]]; then
            # Check if the .vcxproj file contains the old toolset (v100)
            if grep -q "<PlatformToolset>v100</PlatformToolset>" "$vcxproj_file"; then
                echo "Retargeting $vcxproj_file to v143..."
                
                # Use xmlstarlet to change PlatformToolset from v100 to v143
                xmlstarlet ed -u '//PlatformToolset[text()="v100"]' -v "v143" "$vcxproj_file" > tmp.xml && mv tmp.xml "$vcxproj_file"
                
                echo "Updated $vcxproj_file to use v143."
            fi
        else
            echo "Warning: $vcxproj_file not found, skipping."
        fi
    done
done

echo "Retargeting complete!"