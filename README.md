# DS_C_A3_i232503
# Player and Game Data Management System

## Overview

This project implements a **Player and Game Data Management System** that allows users to manage player information and the games they have played. The system uses **Binary Search Trees (BSTs)** to store and efficiently handle operations such as inserting, deleting, searching, and editing players and games. It also supports various functionalities like saving data to CSV files, finding the top N players, and checking if a player has played a specific game.

---

## Features

### 1. Insert Player
- Adds a new player to the system.
- Ensures no duplicate players exist (based on Player ID).

### 2. Delete Player
- Deletes a player from the system using the player's unique ID.

### 3. Search Player
- Allows searching for a player by their ID.
- Displays detailed information about the player.

### 4. Insert Game
- Adds a new game entry to a player's record.

### 5. Delete Game
- Deletes a specific game from a player's list of played games by `Game_Id`.

### 6. Search Game
- Searches for a game based on its `Game_Id`.
- Displays the corresponding game details.

### 7. Find Top N Players
- Finds and displays the top N players who have played the most games.

### 8. Check if Player has Played a Game
- Checks whether a player has played a specific game.
- Displays the game details if found.

### 9. Display Path of a Player
- Displays the path taken in the BST to locate a player by their Player ID.

### 10. Display Path of a Game
- Displays the path taken to locate a game in the tree based on its `Game_Id`.

### 11. Save Game Data to CSV
- Saves all game data to a CSV file using **Preorder Traversal**.

### 12. Save Player Data to CSV
- Saves player data (including their games) to a CSV file.

### 13. Edit Player Entry
- Allows modification of a player's details (e.g., name, phone number, etc.).
- Repositions the player in the BST if necessary.

### 14. Edit Game Entry
- Allows modification of a game's details (e.g., hours played, achievements unlocked).
- Repositions the game in the player's game tree.

### 15. Exit
- Exits the program.

---

## Code Structure

### `Tree` Class

This class encapsulates the operations related to players and games. It provides methods for inserting, deleting, searching, and editing players and games, as well as saving the data to CSV files.

#### Key Methods:
- **`insertPlayerData()`**: Inserts a new player into the system.
- **`deletePlayer()`**: Deletes a player by their Player ID.
- **`searchPlayer()`**: Searches for a player by ID.
- **`insertGameData()`**: Inserts a new game for a player.
- **`deleteGame()`**: Deletes a game from a player's record.
- **`search_Game()`**: Searches for a game by its `Game_Id`.
- **`find_top_player()`**: Displays the top N players who have played the most games.
- **`has_played()`**: Checks if a player has played a specific game.
- **`Player_Display()`**: Displays the path to locate a player.
- **`GameDisplay()`**: Displays the path to locate a game.
- **`savePlayerData()`**: Saves player data to a CSV file.
- **`saveGameData()`**: Saves game data to a CSV file.
- **`edit_player_entry()`**: Edits player information and adjusts the tree if needed.