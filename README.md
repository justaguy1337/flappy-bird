# Flappy-Bird

A C++ implementation of the classic Flappy Bird game with simple graphics and input handling.

---

## Features
- Faithful recreation of Flappy Bird mechanics (flap, gravity, pipes)
- Real-time gameplay loop and basic collision detection
- Keyboard controls for flapping and restarting
- Score tracking during runs

---

## Requirements
- C++11 or newer compatible compiler (tested: GCC, Clang, MSVC)
- Standard graphics library (may use SFML, SDL2, or raw OpenGL depending on implementation)

---

## Installation

### Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install build-essential libsfml-dev cmake
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
./flappy
```

### Linux (Fedora)
```bash
sudo dnf install gcc-c++ SFML-devel cmake
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
./flappy
```

### macOS
```bash
brew install sfml cmake
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(sysctl -n hw.ncpu)
./flappy
```

### Windows (Visual Studio)
```bash
# Install SFML, then:
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
.\Release\flappy.exe
```

### Windows (MinGW)
```bash
# Install SFML and MinGW, then:
mkdir build
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
.\flappy.exe
```
