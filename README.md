# CSE1001
My coding assignments from CSE1001 in C. These are the assigns I learned C with. 
Each file can be run from 'gcc -o'. No input files are required for any programs. 

# memory.c
This program creates a randomly generated memory game. You are presented a 4 x 4 square (0 indexed) that you can choose to make a match. The board will display with the attempt or if it is right, it will be shown every time the board is printed. If you get to 8 points, you win the game. 

# ordinals.c
This program will print the Ordinal (1st, 2nd, 3rd, 4th, etc) from 1 to a given input (less than 65335). A negitive number will exit the program.
BUG: Currently, this prints 11th, 12th, 13th for only the 11, 12, 13 and not for all numbers with 11, 12, 13 as the last 2 digits (ex: 1112 prints as 1112th). 

# pressure.c
This program will print the pressure in all the different measurments. 
Future Update: Move the calculations into a function

# war.c
This program is a Player V.S. CPU game of war. The decks are randomly shuffled to both player and CPU and you can play though war like normal. 
