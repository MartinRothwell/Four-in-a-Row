#include <iostream>
#include <time.h>
#include "Connect_Four.h"
using namespace std;

int main()
{
	bool win1 = false,//checks for player win
		win2 = false,//checks for computer win
		win3 = false; // checks for a tie.
	int winSize = GetConnectionSize();
	char** GameBoard = BuildGameBoard(winSize);
	while ((win1 == false) && (win2 == false) && (win3 == false))
	{
		PlayerMove(GameBoard, winSize);
		win1 = CheckRowWin(GameBoard, winSize);
		if (win1 == true)
		{
			DisplayGameBoard(GameBoard, winSize);
			break;
		}
		win1 = CheckColumnWin(GameBoard, winSize);
		if (win1 == true)
		{
			DisplayGameBoard(GameBoard, winSize);
			break;
		}
		win1 = CheckRightDiagonalWin(GameBoard, winSize);
		if (win1 == true)
		{
			DisplayGameBoard(GameBoard, winSize);
			break;
		}
		win1 = CheckLeftDiagonalWin(GameBoard, winSize);
		if (win1 == true)
		{
			DisplayGameBoard(GameBoard, winSize);
			break;
		}

		ComputerMove(GameBoard, winSize);
		win2 = CheckRowWin(GameBoard, winSize);
		if (win2 == true)
		{
			DisplayGameBoard(GameBoard, winSize);
			break;
		}
		win2 = CheckColumnWin(GameBoard, winSize);
		if (win2 == true)
		{
			DisplayGameBoard(GameBoard, winSize);
			break;
		}
		win2 = CheckRightDiagonalWin(GameBoard, winSize);
		if (win2 == true)
		{
			DisplayGameBoard(GameBoard, winSize);
			break;
		}
		win2 = CheckLeftDiagonalWin(GameBoard, winSize);
		if (win2 == true)
		{
			DisplayGameBoard(GameBoard, winSize);
			break;
		}
		win3 = CheckTie(GameBoard, winSize);
		DisplayGameBoard(GameBoard, winSize);
	}
	if (win1 == true)
	{
		cout << "You Win!! Have a cookie. . .\n";
	}
	else if (win2 == true)
	{
		cout << "You lose. . . No cookie for you.\n";
	}
	else if (win3 == true)
	{
		cout << "No one wins. Sucks for you, but, me, I get a cookie.\n";
	}
	DestroyGameBoard(GameBoard, winSize);

	return 0;
}

int GetConnectionSize(void)
{
	int winSize;
	cout << "How many connections should be needed to win the game? Choose a number from 3-6.";
	cin >> winSize;

	while (winSize < 3 || winSize > 6)
	{
		cout << "That amount it not accepted. Please choose a number between 3 and 6.";
		cin >> winSize;
	}

	return winSize;
}

// Create a dynamic 2D character array for the game board 
char** BuildGameBoard(int winSize)
{
	int rows = winSize + 2, cols = winSize + 3;

	char**GameBoard = new char *[rows];

	for (int i = 0; i<winSize + 2; i++)
	{
		GameBoard[i] = new char[cols];
	}

	return GameBoard;
}

void DisplayGameBoard(char **GameBoard, int winSize)
{
	int rows = winSize + 2, cols = winSize + 3;
	for (int i = 0; i<rows; i++)
	{

		for (int j = 0; j<cols; j++)
		{
			cout << "|" << GameBoard[i][j];
		}
		cout << "|\n";
	}
}

//Asks the player which column they would like to move into
void PlayerMove(char **GameBoard, int winSize)
{
	int rows = winSize + 2, cols = winSize + 3, colChoice;
	bool checkChoice = false;
	while (checkChoice == false)
	{
		cout << "Please choose the column you would like to move into.";
		cin >> colChoice;
		if ((colChoice >= 0) && (colChoice<cols))
		{
			checkChoice = true;
			if ((GameBoard[0][colChoice] == 'O') || (GameBoard[0][colChoice] == 'X'))
			{
				checkChoice = false;
				cout << "\nThat column choice is out of bounds.\n";
			}
			if (checkChoice == true)
			{
				for (int i = rows - 1; i >= 0; i--)
				{
					if ((GameBoard[i][colChoice] != 'X') && (GameBoard[i][colChoice] != 'O'))
					{
						GameBoard[i][colChoice] = 'O';
						break;
					}
				}
			}
			if (checkChoice == true)
				break;
		}
		else
			cout << "\nThat column choice is out of bounds.\n";
	}
}

//uses rand() to move for the computer
void ComputerMove(char **GameBoard, int winSize)
{
	srand(time(NULL));
	int rows = winSize + 2, cols = winSize + 3, colChoice;
	bool checkChoice = false;
	while (checkChoice == false)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		colChoice = ((rand()) % cols);

		if ((colChoice >= 0) && (colChoice<cols))
		{
			checkChoice = true;
			if ((GameBoard[0][colChoice] == 'O') || (GameBoard[0][colChoice] == 'X'))
			{
				checkChoice = false;
			}
			if (checkChoice == true)
			{
				for (int i = rows - 1; i >= 0; i--)
				{
					if ((GameBoard[i][colChoice] != 'X') && (GameBoard[i][colChoice] != 'O'))
					{
						GameBoard[i][colChoice] = 'X';
						break;
					}
				}
			}
			if (checkChoice == true)
				break;
		}
	}
}

bool CheckRowWin(char **GameBoard, int winSize)
{
	int inArow = 1;
	bool win = false;
	int rows = winSize + 2, cols = winSize + 3;

	for (int i = rows - 1; i>0; i--)
	{
		inArow = 1;
		for (int j = 0; j<cols; j++)
		{
			{
				if (GameBoard[i][j] == GameBoard[i][j + 1])
				{
					if ((GameBoard[i][j] == 'O') || (GameBoard[i][j] == 'X'))
					{
						inArow++;
						if (winSize == inArow)
						{
							win = true;
							return win;
						}
						else
							win = false;
					}
				}
				else
				{
					inArow = 1;
					win = false;
				}
			}
		}
	}

	return win;
}

bool CheckColumnWin(char **GameBoard, int winSize)
{
	int inArow = 1;
	bool win = false;
	int rows = winSize + 2, cols = winSize + 3;

	for (int j = 0; j<cols; j++)
	{
		inArow = 1;
		for (int i = rows - 1; i>0; i--)
		{
			if ((GameBoard[i][j] == 'O') || (GameBoard[i][j] == 'X'))
			{
				if (GameBoard[i][j] == GameBoard[i - 1][j])
				{
					inArow++;
					if (winSize == inArow)
					{
						win = true;
						return win;
					}
					else
						win = false;
				}
				else
				{
					inArow = 1;
					win = false;
				}
			}
		}
	}


	return win;
}

bool CheckRightDiagonalWin(char **GameBoard, int winSize)
{
	int inArow = 1;
	bool win = false;
	int rows = winSize + 2, cols = winSize + 3;

	for (int i = rows - 1; i >= 0; i--)
	{
		inArow = 1;
		for (int j = 0; j<cols; j++)
		{
			if ((GameBoard[i][j] == 'O') || (GameBoard[i][j] == 'X'))
			{
				int k = i, l = j;
				while ((k != 0) && (GameBoard[k][l] == GameBoard[k - 1][l + 1]))
				{
					++inArow;
					if (winSize == inArow)
					{
						win = true;
						return win;
					}
					else
					{
						win = false;
					}
					--k, ++l;
				}
			}
			if (win == true)
				break;
			else
			{
				inArow = 1;
			}
		}
		if (win == true)
			break;
	}

	return win;
}

bool CheckLeftDiagonalWin(char **GameBoard, int winSize)
{
	int inArow = 1;
	bool win = false;
	int rows = winSize + 2, cols = winSize + 3;

	for (int i = rows - 1; i >= 0; i--)
	{
		inArow = 1;
		for (int j = cols - 1; j >= 0; j--)
		{
			if ((GameBoard[i][j] == 'O') || (GameBoard[i][j] == 'X'))
			{
				int k = i, l = j;
				while ((k != 0) && (GameBoard[k][l] == GameBoard[k - 1][l - 1]))
				{
					++inArow;
					if (winSize == inArow)
					{
						win = true;
						return win;
					}
					else
					{
						win = false;
					}
					--k, --l;
				}
			}
			inArow = 1;
		}
	}


	return win;
}

bool CheckTie(char **GameBoard, int winSize)
{
	bool win = false;
	int rows = winSize + 2, cols = winSize + 3, full = 1;

	for (int j = 0; j<cols - 1; j++)
	{
		if ((GameBoard[0][j] == 'O') || (GameBoard[0][j] == 'X'))
		{
			++full;
		}
	}
	if (full == cols)
		win = true;

	return win;
}

void DestroyGameBoard(char **GameBoard, int winSize)
{
	int rows = winSize + 2, cols = winSize + 3;

	delete[]GameBoard;

}
