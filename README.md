CodeSnake: A C Project in Gaming

Setup Function:
Initializes game environment parameters such as width, height, and gameover status.
Sets initial positions for the snake and fruit.
Utilizes pseudo-random number generation to place the fruit within the game grid.
Initializes variables for score and tail segment count.

Draw Function:
Renders the game screen by printing characters representing game elements.
Utilizes nested loops to traverse the game grid and print appropriate characters.
Conditions printing based on snake's position, fruit location, and presence of tail segments.


Input Function:
Handles user input for controlling snake movement.
Uses functions like kbhit() and getch() to detect and retrieve keyboard input.
Implements a switch statement to interpret different key presses and update movement direction accordingly.

Logic Function:
Implements core game logic including updating snake's position and checking for collisions.
Updates snake's head position based on current movement direction.
Detects collisions with game boundaries or the snake's own body.
Manages scenarios where snake consumes fruit, updating score and snake length.
Updates positions of snake's tail segments to maintain continuity.

Main Function:
Acts as entry point for the program.
Executes game loop, rendering screen, processing input, and updating game state.
Implements loop for allowing player to restart game after game over.
Utilizes label-based loop for game restart functionality.
