#include <iostream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

char maze[10][10] = { {'#','=','#','#','#','#','#','#','#','#'},
							{'#','.','.','.','.','#','#','#','#','#'},
							{'#','.','#','#','.','#','.','.','.','#'},
							{'#','.','#','#','#','#','.','#','.','#'},
							{'#','.','.','.','#','#','.','#','.','#'},
							{'#','.','#','.','#','#','.','#','#','#'},
							{'#','#','#','.','.','.','.','.','#','#'},
							{'#','#','#','.','#','#','#','.','#','#'},
							{'#','.','.','.','#','#','#','.','#','#'},
							{'#','#','#','#','#','#','#','=','#','#'} };

void ClearArea() {
	system("CLS");
}

void MoveHandle(int move, int& X, int& Y) {
	switch (move = _getch()) {
	case KEY_UP:
		if (Y - 1 >= 0) {
			if (maze[Y - 1][X] != '#') {
				Y--;
			}
		}
		break;

	case KEY_DOWN:
		if (Y + 1 <= 9) {
			if (maze[Y + 1][X] != '#') {
				Y++;
			}
		}
		break;

	case KEY_RIGHT:
		if (X + 1 <= 9) {
			if (maze[Y][X + 1] != '#') {
				X++;
			}
		}
		break;

	case KEY_LEFT:
		if (X - 1 >= 0) {
			if (maze[Y][X - 1] != '#') {
				X--;
			}
		}
	}
}

void DisplayPlayer(int& X, int& Y) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == X && i == Y) {
				cout << "+ ";
				continue;
			}
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

bool CheckFinish(int& X, int& Y) {
	if (X == 7 && Y == 9) {
		return true;
	}
	return false;
}

int main()
{
	cout << "                        ____    ____       ___    ___    ___    _____  ____    ____ _____" << endl;
	cout << "   /\\  /\\        /\\        /   |          |   |  |   |  |   |     |   |       |       |" << endl;
	cout << "  /  \\/  \\      /__\\      /    |____      |___|  |___|  |   |     |   |____   |       |" << endl;
	cout << " /        \\    /    \\    /     |          |      |\\     |   |   _ |   |       |       | " << endl;
	cout << "/          \\  /      \\  /____  |____      |      | \\    |___|   |_|   |____   |____   |" << endl;
	Sleep(3000);
}