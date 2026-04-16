#!/bin/bash

BUILD_DIR="./build"
DEFAULT_INSTALL_DIR="./install"

if [ "$1" == "clean" ]; then
    echo "Cleaning build and install directories..."
    rm -rf "$BUILD_DIR"
    rm -rf "$DEFAULT_INSTALL_DIR"
    echo "Clean complete."
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR" || exit

# Ask user for install location
echo ""
echo "Where would you like to install the game?"
echo "Press Enter to use the default: $DEFAULT_INSTALL_DIR"
read -p "Install path: " USER_INSTALL_DIR

# Use default if user just pressed Enter
if [ -z "$USER_INSTALL_DIR" ]; then
    INSTALL_DIR="../$DEFAULT_INSTALL_DIR"
else
    INSTALL_DIR="$USER_INSTALL_DIR"
fi

echo ""
echo "Installing to: $INSTALL_DIR"
echo ""

echo "Configuring..."
cmake ..

echo "Building..."
cmake --build .

echo "Installing..."
cmake --install . --prefix "$INSTALL_DIR"

echo ""
echo "Done! Executable is at $INSTALL_DIR/bin/"