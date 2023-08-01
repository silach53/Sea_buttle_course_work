# 1 Technical Assignment
The product is a sea battle game interface in C/C++ and a Python library that uses this interface, allowing to create custom agents. The library will include the following features:
- Method returning the composition of ships that should be on the field according to the game rules.
- Function to create a field with correctly placed ships, ensuring that the composition of ships on the field is valid and that ships do not overlap.
- Function to make a shot at a specific cell, which will check the correctness of the coordinates and update the cell state according to the game rules.
- Methods to return the field size and print the field state to a file.
- All code execution will be performed on the fast C++ language, while user actions will be legalized through the Python interface.

Agents will be written in Python and will be able to use the interface provided by the library to interact with the game state and make decisions. The underlying game logic and calculations will be handled by the C++ implementation, ensuring fast and efficient performance. In general, the library is designed to provide a convenient and friendly interface for the classic Sea Battle game, as well as to provide flexibility in implementing custom agents.

# 2 User Description
The user gets a game engine library that works efficiently due to the code written in C/C++. A template in main.py is offered as a demo version, from which one can start writing their agents. It has implemented interactions in the game environment and demonstrated examples of using various functions to manipulate the game state.

## 2.1 Documentation: API for interacting with the sea battle library
Class: sea
This class provides an interface to interact with the C++ library, which implements the Sea Battle game.

Properties:
- lib: a ctypes object representing the loaded C++ library.
- makegame_c: a ctypes function object for creating a new game instance.
- fill_board_c: a ctypes function object for filling the board with a specific ship composition.
- make_a_move: a ctypes function object to make a move on the game field.
- print_board: a ctypes function object for printing the current state of the game field.
- end_of_the_game: a ctypes function object to check if the game is over.
- who_won: a ctypes function object to check which player won the game.
- b0_feeled: a ctypes function object to check if player 1's fleet has been completely destroyed.
- b1_feeled: a ctypes function object to check if player 2's fleet has been completely destroyed.
- ship_roster_f: a ctypes function object to get a list of ships for the game.
- n: A ctypes variable object to get the number of rows in the game field.
- m: A ctypes variable object to get the number of columns in the game field.
- rs: A ctypes variable object to get the number of different types of ships in the game.
Methods:
- makegame(): creates a new game instance and returns a ctypes void pointer to it.
- fill_board(state, bot_id, mas): fills the game field with a specific ship composition. The state parameter should be a ctypes void pointer returned by the makegame() method. The bot_id parameter should be an integer representing the player ID (either 0 or 1). The mas parameter should be a 2D list of integers representing the ship composition on the board, where 0 represents an empty cell and 1 represents a ship cell.
- ship_roster(): returns a list of integers representing the list of ships for the game.
- make_a_move(state, bot_id, i, j): makes a move at the specified coordinates on the game field. The state parameter should be a ctypes void pointer returned by the makegame() method. The bot_id parameter should be an integer representing the player ID (either 0 or 1). The i and j parameters should be integers representing the coordinates of the row and column on the board, respectively.
- print_board(state): outputs the current state of the game field. The state parameter should be a ctypes void pointer returned by the makegame() method.
- end_of_the_game(state): returns a boolean value indicating whether the game has ended or not. The state parameter should be a ctypes void pointer returned by the makegame() method.
- who_won(state): returns an integer indicating the winner of the game (-1 if the game is not over, 0 if player 1 won, 1 if player 2 won, 2 if the game ended in a draw). The state parameter should be an empty ctypes pointer returned by `makegame`.

# 3 Technical Documentation
## 3.1 Installation Instructions
1. Make sure you have Windows/Unix/MacOS operating system installed and the latest version of the Python interpreter.
2. Enter the following in the console: git clone https://github.com/silach53/Sea_buttle_course_work.git
3. Compile the project through Cmake
4. Build the “Lambda” project
5.  Build “Install” (or in the command line: cmake install)
## 3.2 System Architecture Diagram
![image](https://github.com/silach53/Sea_buttle_course_work/assets/132053832/4a4d0b5f-bf42-4986-a724-be25537d5a57)


## 4 Testing Instructions
### 4.1 Technical Requirements
- Python Interpreter (version 3.x or later)
- Cmake minimum version 3.5.
- C++ Standard 17.

### 4.2 Testing 
Ensure you have the Windows/Unix/MacOS operating system installed and the latest version of the Python interpreter. Follow the steps below to test the application:

1. Clone the repository by typing this command in your console: `git clone https://github.com/silach53/Sea_buttle_course_work.git`
2. Build the project through Cmake.
3. Build the project "Lamda".
4. Build "Install" (or in the command line `cmake install`).
5. Open the "install" folder.
6. Run the command `python main.py` to start the script.
7. Open "print_board.txt" file to view the current state of the game board. Note that a field was created on the right side, it will also be created the next time you run main.py. On the left side of the board, a deterministic agent shoots at the cells sequentially, from left to right, top to bottom.
8. Run the command `python main.py` again, this time one of the agents will make other random moves.
9. Open "print_board.txt" file again, to view the updated state of the game board, note that one of the agents on the right side of the field made random actions, and on the left side of the board, the deterministic agent performed the same actions.
