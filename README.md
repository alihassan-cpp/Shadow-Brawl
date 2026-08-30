# Shadow Brawl 🦖

Shadow Brawl is a console-based endless runner game developed in C++ using Programming Fundamentals (PF) and Object-Oriented Programming (OOP) concepts.

The player controls a dinosaur and must jump over obstacles, avoid flying obstacles, and survive for as long as possible while trying to achieve the highest score.

---

## 🎮 Features

- Console-based endless runner gameplay
- Dinosaur jumping and gravity physics
- Multiple obstacle types
- Flying obstacles
- Random obstacle patterns
- Collision detection
- Increasing game speed
- Score system
- Persistent high score using file handling
- Main menu
- Instructions screen
- Pause and resume system
- Game-over screen
- 3-2-1-GO countdown
- Colored console interface

---

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `SPACE` | Jump |
| `W` | Jump |
| `P` | Pause / Resume |
| `Q` | Quit |
| `R` | Return to menu |
| `B` | Back to menu |

---

## 🧠 Concepts Used

### Programming Fundamentals

- Variables
- Conditions
- Loops
- Functions
- Vectors
- Random number generation
- File handling
- Input / Output

### Object-Oriented Programming

- Classes and objects
- Encapsulation
- Constructors
- Member functions
- Composition
- Abstraction
- Separation of responsibilities

---

## 📁 Project Structure

```text
Shadow-Brawl/
│
├── Game.h
├── Game.cpp
│
├── Dinosaur.h
├── Dinosaur.cpp
│
├── Obstacle.h
├── Obstacle.cpp
│
├── Console.h
├── Console.cpp
│
├── main.cpp
├── highscore.txt
├── README.md
└── .gitignore
```

---

## ⚙️ Requirements

- Windows
- C++ compiler
- Visual Studio or another compatible C++ IDE

The project uses Windows console functionality such as:

- `<windows.h>`
- `<conio.h>`

---

## 🚀 How to Run

1. Clone the repository.
2. Open the project in Visual Studio.
3. Build the project.
4. Run the program.
5. Select `1. PLAY` from the main menu.

---

## 🎯 Objective

Survive as long as possible, avoid obstacles, and achieve the highest score.

The game automatically saves the high score using file handling so it remains available when the game is launched again.

---

## 🏗️ Project Architecture

The project is divided into several classes, each with a specific responsibility.

### `Game`

Controls the main game loop, game states, scoring, obstacle spawning, collision detection, menus, and difficulty.

### `Dinosaur`

Handles the player's position, jumping, gravity, movement, and drawing.

### `Obstacle`

Handles obstacle position, movement, type, size, and drawing.

### `Console`

Provides console-related functionality such as cursor positioning, colors, and screen control.

---

## 📌 Project Goal

Shadow Brawl was created as a practical C++ project to apply Programming Fundamentals and Object-Oriented Programming concepts to a complete playable game.

The project is developed incrementally using Git and GitHub for version control and professional development practice.