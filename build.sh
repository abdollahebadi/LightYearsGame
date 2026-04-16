#!/bin/bash

BUILD_DIR="./build"
DEPS_DIR="./_deps"
DEFAULT_INSTALL_DIR="./install"

if [ "$1" == "clean-build" ]; then
    echo "Cleaning build and install directories..."
    rm -rf "$BUILD_DIR"
    rm -rf "$DEFAULT_INSTALL_DIR"
    echo "Clean complete."
elif [ "$1" == "clean-all" ]; then
    echo "Cleaning build, install and dependencies directories..."
    rm -rf "$BUILD_DIR"
    rm -rf "$DEFAULT_INSTALL_DIR"
    rm -rf "$DEPS_DIR"
    echo "Clean all complete."
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR" || exit

# Ask user for install location
echo ""
echo "Where would you like to install the game?"
echo "Press Enter to use the default: $DEFAULT_INSTALL_DIR"
read -p "Install path: " USER_INSTALL_DIR

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