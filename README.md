# Starfield Navigator

Starfield Navigator is a 2D space exploration game built in C++ using the SFML library. Players control a starship, navigating through a procedurally generated starfield, avoiding asteroids, and collecting resources to survive. The game features smooth controls, collision detection, and a dynamic scoring system.

## Features
- Procedurally generated starfield with moving stars.
- Player-controlled starship with smooth movement.
- Asteroids as obstacles with collision detection.
- Collectible resources to increase score.
- Modular and extensible codebase for easy contributions.

## Prerequisites
- C++17 or later
- SFML 2.5.1 or later
- CMake 3.10 or later
- A C++ compiler (e.g., g++, MSVC, clang)

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/starfield-navigator.git
   cd starfield-navigator
   ```
2. Install SFML:
   - On Ubuntu: `sudo apt-get install libsfml-dev`
   - On macOS: `brew install sfml`
   - On Windows: Download SFML from [sfml-dev.org](https://www.sfml-dev.org) and follow the setup guide.
3. Build the project:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
4. Run the game:
   ```bash
   ./StarfieldNavigator
   ```

## Controls
- **W**: Accelerate forward
- **A/D**: Rotate ship left/right
- **Space**: Pause/unpause game
- **Escape**: Quit game

## Contributing
Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a feature branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m "Add your feature"`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Open a Pull Request.

## Sponsor
Support the development of Starfield Navigator by becoming a [GitHub Sponsor](https://github.com/sponsors/yourusername). Your support helps maintain and improve this project!

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
- Built with [SFML](https://www.sfml-dev.org)
- Inspired by classic space exploration games