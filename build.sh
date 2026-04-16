#!/bin/bash

# Default build type
BUILD_TYPE="build"

# Parse argument
if [ "$1" == "clean" ]; then
    BUILD_TYPE="clean"
fi

# Project root is where this script lives
PROJECT_ROOT="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

if [ "$BUILD_TYPE" == "clean" ]; then
    echo "Cleaning build directory..."
    rm -rf "$BUILD_DIR"
    echo "Clean complete."
fi

# Create build dir if it doesn't exist
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR" || exit

# Configure
echo "Configuring..."
cmake ..

# Build
echo "Building..."
cmake --build .

echo "Done!"