# so_long

**so_long** is a simple 2D game built using the **MinilibX graphics library**.  
Developed as part of the **42 School Curriculum**, this project focuses on rendering a basic tile-based map, handling player input, and implementing simple game logic.

---

## 🎮 Game Description

- The player controls a character that must collect all collectibles and reach the exit.
- The map is composed of walls, empty spaces, collectibles, a player start position, and an exit.
- The game ends successfully when the player collects all items and reaches the exit.
- The game ends in failure if an invalid move is attempted (or optionally with enemies if implemented as a bonus).

---

## 🛠️ Features

- ✅ **2D Map Rendering** using **MinilibX**
- ✅ **Player Movement** with keyboard input
- ✅ **Collectibles Management**
- ✅ **Exit Unlocks** after collecting all items
- ✅ **Valid Path Check** with a simple flood-fill algorithm
- ✅ **Move Counter Display**
- ✅ **Error Handling** for invalid maps and moves
- ✅ **Optional Bonus** (if implemented)
  - Enemies with AI movement
  - Animation effects
  - Sound effects

---

## 📜 Map Format

- The map must be a `.ber` file.
- The map is a rectangle surrounded by walls.
- Required elements:
  - `1` — Wall
  - `0` — Empty space
  - `C` — Collectible
  - `E` — Exit
  - `P` — Player start position

**Example Map:**
