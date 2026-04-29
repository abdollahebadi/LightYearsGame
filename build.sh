#!/bin/bash

BUILD_DIR="./build"

if [ "$1" == "clean-build" ]; then
    echo "Cleaning build directory (preserving _deps)..."
    find "$BUILD_DIR" -mindepth 1 -maxdepth 1 ! -name "_deps" -exec rm -rf {} +
    echo "Clean complete."
elif [ "$1" == "clean-all" ]; then
    echo "Cleaning build directory entirely (including _deps)..."
    rm -rf "$BUILD_DIR"
    echo "Clean all complete."
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR" || exit

echo "Configuring..."
cmake ..

echo "Building..."
cmake --build .

echo ""
echo "Done! Executable is at $BUILD_DIR/LightYearsGame/LightYearsGame"