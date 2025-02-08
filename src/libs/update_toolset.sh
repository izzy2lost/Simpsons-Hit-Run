#!/bin/bash

# Directory to search for .vcxproj files (you can adjust this if needed)
search_dir="."

# Recursively find all .vcxproj files
find "$search_dir" -name "*.vcxproj" | while read vcxproj_file; do
    # Check if the .vcxproj file contains the old toolset (v100)
    if grep -q "<PlatformToolset>v100</PlatformToolset>" "$vcxproj_file"; then
        echo "Retargeting $vcxproj_file to v143..."

        # Use xmlstarlet to change PlatformToolset from v100 to v143
        xmlstarlet ed -u '//PlatformToolset[text()="v100"]' -v "v143" "$vcxproj_file" > tmp.xml && mv tmp.xml "$vcxproj_file"

        echo "Updated $vcxproj_file to use v143."
    fi
done