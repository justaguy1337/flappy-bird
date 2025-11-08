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
sudo apt install build-essential libsfml-dev
g++ src/*.cpp -I. -o flappy.exe -lsfml-graphics -lsfml-window -lsfml-system
./flappy.exe
```

### CMake
```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release -j$(nproc)
cd bin
./flappy
```

### Windows
- Use Visual Studio
