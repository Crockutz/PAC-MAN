#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
bool gameOver;
int x, y;
int pointX, pointY;
const int ROW = 21, COL = 51;
int score = 0;
enum Direction{ STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;
int enemy1X = 15, enemy1Y = 16;
int enemy2X = 8, enemy2Y = 5;
int enemy3X = 10, enemy3Y = 30;
bool e1 = false;
bool e2 = false;
bool e3 = false;

char map[ROW][COL] = {
"##################################################", // 0
"#                                                #", // 1
"#     ############          ###############      #", // 2
"#                                                #", // 3
"#                                                #", // 4
"#     ############          ###############      #", // 5
"#                                                #", // 6
"#                                                #", // 7
"#                   #    #           #####       #", // 8
"#                   #    #           #   #       #", // 9
"#                   #    #           #   #       #", // 10
"#                   #    #           #   #       #", // 11
"#                   ######           #   #       #", // 12
"#                                                #", // 13
"#    #########                                   #", // 14
"#                      ################          #", // 15
"#                                                #", // 16
"#    #########         ################          #", // 17
"#                                                #", // 18
"##################################################"
};

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = 10;
	y = 13;
	pointX = 3;
	pointY = 26;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			
			if (i == x && j == y)
			{
				if (dir == LEFT)
					cout << ">";
				else if (dir == RIGHT)
					cout << "<";
				else if (dir == UP)
					cout << "v";
				else if (dir == DOWN)
					cout << "^";
			}
			else if (i == enemy1X && j == enemy1Y)
				cout << "X";
			else if (i == enemy2X && j == enemy2Y)
				cout << "X";
			else if (i == enemy3X && j == enemy3Y)
				cout << "X";
			else
				cout << map[i][j];
		}
		cout << endl;
	}
	
}

void direction()
{
	if (GetAsyncKeyState(0x57))
		dir = UP;
	if (GetAsyncKeyState(0x53))
		dir = DOWN;
	if (GetAsyncKeyState(0x41))
		dir = LEFT;
	if (GetAsyncKeyState(0x44))
		dir = RIGHT;

	switch (dir)
	{
	case UP:
		if (map[x - 1][y] != '#')
			x--;
		break;
	case DOWN:
		if (map[x + 1][y] != '#')
			x++;
		break;
	case LEFT:
		if (map[x][y - 1] != '#')
			y--;
		break;
	case RIGHT:
		if (map[x][y + 1] != '#')
			y++;
		break;
	}

	if (x == enemy1X && y == enemy1Y)
		gameOver = true;
	if (x == enemy2X && y == enemy2Y)
		gameOver = true;
	if (x == enemy3X && y == enemy3Y)
		gameOver = true;
}

void Enemies()
{
	if (e1 == false)
	{
		enemy1Y--;
		if (map[enemy1X][enemy1Y - 1] == '#')
			e1 = true;
	}
	else
	{
		enemy1Y++;
		if (map[enemy1X][enemy1Y + 1] == '#')
			e1 = false;
	}

	if (e2 == false)
	{
		enemy2X--;
		if (map[enemy2X - 1][enemy2Y] == '#')
			e2 = true;
	}
	else
	{
		enemy2X++;
		if (map[enemy2X + 1][enemy2Y] == '#')
			e2 = false;
	}

	if (e3 == false)
	{
		enemy3Y--;
		if (map[enemy3X][enemy3Y - 1] == '#')
			e3 = true;
	}
	else
	{
		enemy3Y++;
		if (map[enemy3X][enemy3Y + 1] == '#')
			e3 = false;
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		direction();
		Draw();
		Enemies();
		Sleep(100);
	}
	return 0;
}
