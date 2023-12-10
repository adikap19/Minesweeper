#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Name: Adi Kapuri
ID: 208184093

This program is the Minesweepers game.
The player inserts which Square he wants to expose in the game board until he hit a bomb and lost or avoided all the bombs and won the game.
*/

#define MAX_SIZE 22
#define SIZE 8
#define MINES_AMOUNT 8
#define PAIRS 2

void welcomingAndSettings();
void startGame();
void InitialBoard(char board[][MAX_SIZE], int rows ,int cols);
int sizeOptions(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE]);
void printGameBoard(char board[][MAX_SIZE], int rows, int cols);
void gameLogic(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE], int rows, int cols);
bool isChoiceValid(int rowChoice, int colChoice, char board[][MAX_SIZE], int rows, int cols);
bool hittedBomb(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE], int rows ,int cols, int row_choice, int col_choice);
void setBombs(char hiddenBoard[][MAX_SIZE], int rows, int cols);
void FillSquaresAroundBomb(char hiddenBoard[][MAX_SIZE], int rows, int cols, int x, int y);
void MinusOneOption(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE], int rows, int cols, int numToOpen);
bool winning(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE], int rows, int cols);

void main()
{
	startGame();
}

void startGame() //setting the progress of the game from the first game settings till the end
{
	int size, logSizeOfBoard;
	char board[MAX_SIZE][MAX_SIZE], hiddenBoard[MAX_SIZE][MAX_SIZE];

	welcomingAndSettings();
	logSizeOfBoard = sizeOptions(board, hiddenBoard);
	gameLogic(board, hiddenBoard, logSizeOfBoard, logSizeOfBoard);
}

void welcomingAndSettings() //welcoming message and settings
{
	printf("Welcome to Minesweeper!\n");
	printf("\nPlease choose one of the following options and enter it's number:\n");
	printf("\n1 - for size 8X8\n\n2 - for size 12X12\n\n3 - for size 15X15\n\n4 - for custom size\n\n0 - Exit\n\n");
}

int sizeOptions(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE])// setting the game board according to the size that the user chose
{
	int logSize = 0, size_choice;

	scanf("%d", &size_choice); //according to the options in the welcoming function

	switch (size_choice)
	{
	case 1:
		logSize = SIZE;
		InitialBoard(board, logSize, logSize);
		printGameBoard(board, logSize, logSize);
		setBombs(hiddenBoard, logSize, logSize);
		break;
	case 2:
		printf("Not valid yet!\n\n");
		startGame();
		break;
	case 3:
		printf("Not valid yet!\n\n");
		startGame();
		break;
	case 4:
		printf("Not valid yet!\n\n");
		startGame();
		break;
	case 0:
		exit(1);
		break;
	default:
		printf("Invalid Choice. Try again.\n\n");
		startGame();
	}

	return logSize;
}

void InitialBoard(char board[][MAX_SIZE], int rows ,int cols) //initial the game board with 'X'
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			board[i][j] = 'X';
}

void printGameBoard(char board[][MAX_SIZE], int rows, int cols)// printing the game board with the changes that happens when the user exposes a square in the board
{
	int i, j;

	printf("\n    ");

	for (i = 0; i < cols; i++)
		printf("%4d", i);

	printf("\n  ____");
	for (i = 0; i < cols; i++)
		printf("____");

	printf("\n");

	for (i = 0; i < rows; i++)
	{
		if (i < 10)
		{
			printf("   %d ", i);

			for (j = 0; j < cols; j++)
				printf("| %c ", board[i][j]);

			printf("|\n");
		}
		else
		{
			printf("%d", i);

			for (j = 0; j < cols; j++)
				printf("| %c ", board[i][j]);

			printf("|\n");
		}
	}

	printf("  ____");
	for (i = 0; i < cols; i++)
		printf("____");
}

void gameLogic(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE], int rows, int cols) // getting the user's choice for his next move until he wins or loses by the game rules
{
	int row_choice, col_choice;
	bool gameEnded = false;

	printf("\nPlease enter your move, row and column : ");
	scanf("%d %d", &row_choice, &col_choice);

	while (gameEnded == false)
	{
		if (row_choice == -1) // -1 : game addition
		{
			if (col_choice >= 0) //valid col choice
			{
				MinusOneOption(board, hiddenBoard, rows, cols, col_choice);
				printGameBoard(board, rows, cols);

				if (winning(board, hiddenBoard, rows, cols)) //the player won
				{
					gameEnded = true;
					printf("\n\nYou won!! congragulations! CHAMPION!\n");
				}
				else
				{
					printf("\nPlease enter your move, row and column : ");
					scanf("%d %d", &row_choice, &col_choice);
				}
			}
			else //if the player inserted unvalid col number
			{
				printf("Please enter a valid choice!\n\n");
				scanf("%d %d", &row_choice, &col_choice);
			}	
		}

		else //the cols choice is not -1
		{
			if (isChoiceValid(row_choice, col_choice, board, rows, cols)) //if the player inserted valid input
			{
				if (hiddenBoard[row_choice][col_choice] == '*') //hitted a bomb
					gameEnded = hittedBomb(board, hiddenBoard, rows, cols, row_choice, col_choice);

				else //number or space
				{
					board[row_choice][col_choice] = hiddenBoard[row_choice][col_choice];
					printGameBoard(board, rows, cols);

					if (winning(board, hiddenBoard, rows, cols)) //the player won
					{
						gameEnded = true;
						printf("\n\nYou won!! congragulations! CHAMPION!\n");
					}
					else
					{
						printf("\nPlease enter your move, row and column : ");
						scanf("%d %d", &row_choice, &col_choice);
					}
				}
			}
			else //if the player inserted unvalid input
			{
				printf("Please enter a valid choice!\n");
				scanf("%d %d", &row_choice, &col_choice);
			}
		}
	}
}

bool isChoiceValid(int rowChoice, int colChoice, char board[][MAX_SIZE], int rows, int cols) // in order to check if the user's choice is valid
{
	if (rowChoice < rows && rowChoice >= 0 && colChoice < cols && colChoice >=0 && board[rowChoice][colChoice] == 'X')
		return true;

	return false;
}

bool hittedBomb(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE], int rows, int cols, int row_choice, int col_choice) // in case the user hitted a bomb
{
	board[row_choice][col_choice] = hiddenBoard[row_choice][col_choice];
	printGameBoard(board, rows, cols);
	printf("\nYou've hit a bomb! Game over!\n");
	printGameBoard(hiddenBoard, rows, cols);

	return true;
}

void setBombs(char hiddenBoard[][MAX_SIZE], int rows, int cols) // put 8 bombs randomly in the game board
{
	int x = 0, y = 0, i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			hiddenBoard[i][j] = ' ';

	srand(time(NULL));

	for (i = 0; i < MINES_AMOUNT; i++)
	{
		x = rand() % rows;
		y = rand() % cols;

		if (hiddenBoard[x][y] != '*')
		{
			hiddenBoard[x][y] = '*';
			FillSquaresAroundBomb(hiddenBoard, rows, cols, x, y);
		}
		else
			i--;
	}
}

void FillSquaresAroundBomb(char hiddenBoard[][MAX_SIZE], int rows, int cols, int x, int y) //fill the squares around the bombs with number that represent how many bombs there are around
{
	int i, j;

	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && i < rows && j >= 0 && j < cols)
			{
				if (hiddenBoard[i][j] != '*')
				{
					if (hiddenBoard[i][j] != ' ')
						hiddenBoard[i][j]++;
					else
						hiddenBoard[i][j] = '1';
				}
			}
		}
	}
}

void MinusOneOption(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE], int rows, int cols, int numToOpen) //if the player inserted -1 in the row choice, squares will open as the col choice amount
{
	int i, j, count = 0;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (board[i][j] == 'X' && hiddenBoard[i][j] != '*')
			{
				board[i][j] = hiddenBoard[i][j];
				count++;
			}

			if (count == numToOpen)
				return;
		}
	}
}

bool winning(char board[][MAX_SIZE], char hiddenBoard[][MAX_SIZE], int rows, int cols) //cheking if all the squares but the bombs are open - if so, the player won
{
	int i, j;
	bool isWon = true;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (hiddenBoard[i][j] != '*' && board[i][j] == 'X')
			{
				isWon = false;
				break;
			}
		}
	}
	return isWon;
}
