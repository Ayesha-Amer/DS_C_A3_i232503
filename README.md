# Player and Game Data Management System

## Overview

The **Player and Game Data Management System** is a C++ project designed to manage player information and track the games they have played. It leverages **Binary Search Trees (BSTs)** to ensure efficient handling of player and game data. The system allows for various operations such as inserting, deleting, searching, and editing players and games, as well as saving data to CSV files and displaying top players based on the number of games played.

---

## Key Features

The system provides the following functionalities:

- **Insert and Delete Players**: Add new players to the system and remove them using their unique `Player_ID`.
- **Insert and Delete Games**: Track the games played by players, with the ability to insert new games and delete them.
- **Search for Players and Games**: Search for a player or a game using their respective IDs, and view detailed information.
- **Find Top N Players**: Retrieve the top N players based on the number of games they have played.
- **Check if a Player has Played a Specific Game**: Determine whether a player has played a specific game by providing both the player and game IDs.
- **Edit Player and Game Entries**: Modify player and game information and ensure the data is reorganized if needed.
- **Display Preorder Traversal**: Display the structure of the data in a Binary Search Tree (BST) for both players and games.
- **Save Data to CSV**: Export both player and game data to CSV files using Preorder Traversal, maintaining the hierarchy of data.

The program is designed to be flexible and extensible, allowing for easy future improvements and modifications.

---

## Design and Architecture

### Data Structure: Binary Search Tree (BST)

The system makes use of a **Binary Search Tree (BST)** to store player and game data. This choice allows efficient operations like insertion, deletion, and searching, with an average time complexity of `O(log n)` in balanced trees.

- **Players**: The players are stored in a BST, with `Player_ID` as the key.
- **Games**: Each player has a subtree of games they’ve played, also represented as a BST, where the `Game_ID` serves as the key.

This design helps in quick lookups, additions, and deletions, ensuring that the system performs well even as data scales.

### Key Components

- **`Tree` Class**: The main class that handles the insertion, deletion, and searching of both players and games. It also includes methods to save data, check if a player has played a game, and find the top players based on the number of games played.
  
- **`Player` Class**: Represents a player in the system. Each player has their own set of personal details (e.g., name, email, phone number) and a list of games they have played (stored as a BST).
  
- **`Games` Class**: Represents a game. Each game has attributes like the game’s name, developer, publisher, file size, and number of downloads. Each game is associated with a player, and this information is stored in the player's game tree.
  
- **`GamesPlayed_Class` Class**: A helper class used for managing game data in the player's game tree. It stores details about the game, such as hours played and achievements unlocked.

### CSV Export with Preorder Traversal

To preserve the structure of the BST when the program is restarted, the data is saved to a CSV file using **Preorder Traversal**. This traversal method ensures that the tree's hierarchy is retained and can be rebuilt when reloading the data.

---

## Handling Input and Operations

The program offers a text-based menu to perform various operations. User inputs are validated where necessary to ensure the integrity of the data. The following operations are available:

- **Insert Player**: Adds a new player to the system.
- **Delete Player**: Deletes a player from the system based on their `Player_ID`.
- **Search Player**: Allows searching for a player by their `Player_ID` and displays their information.
- **Insert Game**: Adds a new game to a player's list of played games.
- **Delete Game**: Deletes a game from the player's record.
- **Search Game**: Allows searching for a game based on its `Game_ID` and displays its information.
- **Find Top N Players**: Retrieves the top N players with the most games played.
- **Check if Player has Played a Game**: Checks whether a player has played a specific game, based on both `Player_ID` and `Game_ID`.
- **Edit Player Entry**: Allows modifying a player's details and repositioning them in the tree if necessary.
- **Edit Game Entry**: Allows modifying a game's details and repositioning it in the game tree.

