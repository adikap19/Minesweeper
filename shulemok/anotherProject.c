////dolev ifrah i.d 20939818
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>//for sqrt func
//#define ROWS 22//sizeofarray
//#define COLS 22	//sizeofarray
//
//void printboard(char board[][COLS], int rows, int cols);//print gaming board
//void FillBoard(char board[][COLS], int rows, int cols);//fill board with X
//void FillBoardWithBombs(char board[][COLS], int rows, int cols);//fill  board with bombs
//void FillBombArea(char board[][COLS], int rows, int cols, int x, int y);//filling area around bombs
//void MinusOne(char board[][COLS], char boardofbombs[][COLS], int rows, int cols, int num);//minusone cheat
//void openneighbors(char board[][COLS], char boardofbombs[][COLS], int rows, int cols, int x, int y);//rec func of opening all nearby spaces and numbers
//int checkwin(char boardofbombs[][COLS], char board[][COLS], int rows, int cols);//checking if the player won
//sizeofboard(int sizerow, int sizecol);//define the board size
//miesweepgame();//in order to not implement anything in main
//void main()
//{
//	miesweepgame();
//}
//
//
//void printboard(char board[][COLS], int rows, int cols)
//{
//	int i, j;
//	printf(" ");
//	for (i = 0; i < cols; i++)
//	{
//		printf("%4d", i);
//
//	}
//	printf("\n   ");
//	for (i = 0; i < cols; i++)
//	{
//		printf("____");
//	}
//	printf("\n");
//	for (i = 0; i < rows; i++)
//	{
//		if (i < 10)// beacause 10+ its two letters i added space to fit the game board
//		{
//			printf(" %d", i);
//			for (j = 0; j < cols; j++)
//			{
//				printf("| %c ", board[i][j]);
//			}
//			printf("|\n");
//		}
//		else
//		{
//			printf("%d", i);
//			for (j = 0; j < cols; j++)
//			{
//				printf("| %c ", board[i][j]);
//			}
//			printf("|\n");
//		}
//	}
//}
//
//void FillBoard(char board[][COLS], int rows, int cols)
//{
//	int i, j;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			board[i][j] = 'X';
//		}
//	}
//}
//
//void FillBoardWithBombs(char boardofbombs[][COLS], int rows, int cols)
//{
//	int row, col;
//	int i, j;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			boardofbombs[i][j] = ' ';
//		}
//	}
//	srand(time(NULL));
//	for (i = 0; i < sqrt(rows * cols); i++)
//	{
//		row = rand() % rows;
//		col = rand() % cols;
//		if (boardofbombs[row][col] != '*')//some bombs may rand on the same spot so added a case that checks it and decrease the i counter by 1
//		{
//			boardofbombs[row][col] = '*';
//			FillBombArea(boardofbombs, rows, cols, row, col);
//		}
//		else
//			i--;
//	}
//
//
//}
//
//void FillBombArea(char board[][COLS], int rows, int cols, int x, int y)
//{
//	int i, j;
//	for (i = x - 1; i <= x + 1; i++)
//	{
//		for (j = y - 1; j <= y + 1; j++)
//		{
//			if (i >= 0 && i < rows && j >= 0 && j < cols)
//			{
//				if (board[i][j] != '*')
//				{
//					if (board[i][j] != ' ')
//						board[i][j]++;
//					else
//						board[i][j] = '1';
//				}
//			}
//		}
//	}
//}
//void openneighbors(char board[][COLS], char boardofbombs[][COLS], int rows, int cols, int x, int y)//checking all nearby spaces and numbers including edge cases
//{
//	if (x < 0 || y < 0 || x >= rows || y >= cols)//to be sure its in the range of the game
//		return;
//	if (board[x][y] != 'X' && board[x][y] != 'F')
//		return;
//	if (boardofbombs[x][y] != ' ')
//	{
//		if (boardofbombs[x][y] != '*')
//			board[x][y] = boardofbombs[x][y];
//		return;
//	}
//	board[x][y] = boardofbombs[x][y];
//	openneighbors(board, boardofbombs, rows, cols, x - 1, y - 1);
//	openneighbors(board, boardofbombs, rows, cols, x - 1, y);
//	openneighbors(board, boardofbombs, rows, cols, x - 1, y + 1);
//	openneighbors(board, boardofbombs, rows, cols, x, y - 1);
//	openneighbors(board, boardofbombs, rows, cols, x, y + 1);
//	openneighbors(board, boardofbombs, rows, cols, x + 1, y - 1);
//	openneighbors(board, boardofbombs, rows, cols, x + 1, y);
//	openneighbors(board, boardofbombs, rows, cols, x + 1, (y + 1));
//}
//
//void MinusOne(char board[][COLS], char boardofbombs[][COLS], int rows, int cols, int num)
//{
//	int i, j;
//	int count = 0;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			if ((board[i][j] == 'X' || board[i][j] == 'F') && boardofbombs[i][j] != '*')
//			{
//				board[i][j] = boardofbombs[i][j];
//				count++;
//				if (count == num)
//					return;
//			}
//		}
//	}
//}
//
//int checkwin(char boardofbombs[][COLS], char board[][COLS], int rows, int cols)
//{
//	int i, j;
//	int res = 1;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			if (boardofbombs[i][j] != '*' && (board[i][j] == 'X' || board[i][j] == 'F'))
//			{
//				res = 0;
//				break;
//			}
//		}
//	}
//	return res;
//}
//
//
//
//
//sizeofboard(int sizerow, int sizecol)
//{
//	int i, j;
//	int rows, cols;
//	char flagoropen;
//	int Play = 1;//1<=>keep playing   0<=>stop
//	int Valid = 1;//1<=>last turn was ok   //0<=>last turn was unvalid, dont print the board again
//	char board[ROWS][COLS];//every board is 22*22 and has it own logic size
//	char boardofbombs[ROWS][COLS];
//	FillBoard(board, sizerow, sizecol);
//	FillBoardWithBombs(boardofbombs, sizerow, sizecol);
//	while (Play == 1)
//	{
//		if (Valid == 1)
//		{
//			printboard(board, sizerow, sizecol);
//			printf("Please enter your move, row and coloumn: \n");
//		}
//		else
//		{
//			Valid = 1;
//		}
//
//		scanf("%d %d", &rows, &cols);
//		scanf(" %c", &flagoropen);
//		if (flagoropen != 'o' && flagoropen != 'O' && flagoropen != 'f' && flagoropen != 'F')//check validity of variables
//		{
//			printf("UNVALID: Please enter a valid choice: \n");
//		}
//		else if (rows == -1 && flagoropen == 'o')
//		{
//			if (cols >= 0)
//			{
//				MinusOne(board, boardofbombs, sizerow, sizecol, cols);
//				if (checkwin(boardofbombs, board, sizerow, sizecol))
//				{
//					printboard(boardofbombs, sizerow, sizecol);
//					printf("You Won Champ!!!\n");
//					Play = 0;
//				}
//			}
//			else
//			{
//				printf("UNVALID: Please enter a valid choice: \n");
//				Valid = 1;
//			}
//		}
//		else
//		{
//			if (rows >= 0 && rows < sizerow && cols >= 0 && cols < sizecol && (board[rows][cols] == 'X') || (board[rows][cols] == 'F'))//if not minus one and its in valid choice 
//			{
//
//				if (flagoropen == 'f' || flagoropen == 'F')
//					board[rows][cols] = 'F';
//
//
//				else
//				{
//					if (boardofbombs[rows][cols] == '*')
//					{
//						printboard(boardofbombs, sizerow, sizecol);
//
//						printf("You Lose!!!\n");
//						Play = 0;//play= 0 means end of while loop
//					}
//
//					else
//					{
//						openneighbors(board, boardofbombs, sizerow, sizecol, rows, cols);
//
//						if (checkwin(boardofbombs, board, sizerow, sizecol))
//						{
//							printboard(boardofbombs, sizerow, sizecol);
//							printf("You Won Champ!!!\n");
//							Play = 0;
//						}
//
//
//					}
//				}
//			}
//			else
//			{
//				printf("UNVALID: Please enter a valid choice: \n");
//				Valid = 1;
//			}
//		}
//
//	}
//}
//miesweepgame()//the game itself in order to not implement anything in main
//{
//	int unvalid;
//	int boardsize;
//	int sizerow, sizecol;
//	printf("please choose the board you would like to play with:\n1. 8x8\n2. 12x12\n3. 15x15\n4. choose row and coloumn betwin 1-22\n");
//	unvalid = 1;
//	while (unvalid == 1)
//	{
//		scanf("%d", &boardsize);
//		if (boardsize < 1 || boardsize > 4)
//		{
//			printf("please enter a valid choice!\n");
//			unvalid = 1;
//		}
//		else
//			unvalid = 0;
//	}
//	switch (boardsize)
//	{
//	case(1):
//		sizeofboard(8, 8);
//		break;
//	case (2):
//		sizeofboard(12, 12);
//		break;
//	case(3):
//		sizeofboard(15, 15);
//		break;
//	case(4):
//		printf("please enter the size of rows and cols you want to play with:");
//		scanf("%d %d", &sizerow, &sizecol);
//		sizeofboard(sizerow, sizecol);
//		break;
//	default: printf("Please enter a valid choice");
//	}
//}