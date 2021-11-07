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
    Sleep(00);

    string Menu[3] = { "----> START GAME", "----> SETTINGS", "----> EXIT" };
    int p = 0;

    while (true)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << setw(80) << "            _____               ___       " << endl;
        cout << setw(85) << "|\\/|   /\\     |   |\\  |   |\\/| |    |\\  | |   |" << endl;
        cout << setw(85) << "|  |  /--\\    |   | \\ |   |  | |--- | \\ | |   |" << endl;
        cout << setw(85) << "|  | /    \\ __|__ |  \\|   |  | |___ |  \\| |___|" << endl << endl << endl;

        for (int i = 0; i < 3; i++)
        {
            if (i == p)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                cout << setw(64) << Menu[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << setw(64) << Menu[i] << endl;
            }
        }
        cout << endl;

        while (true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                p -= 1;
                if (p == -1)
                {
                    p = 2;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                p += 1;
                if (p == 3)
                {
                    p = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch (p)
                {
                case 0:
                {
                    int PlposX = 1;
                    int PlposY = 0;
                    int movement = 0;

                    while (!CheckFinish(PlposX, PlposY)) {
                        DisplayPlayer(PlposX, PlposY);
                        MoveHandle(movement, PlposX, PlposY);
                        ClearArea();
                    }
                    cout << "You win";
                    Sleep(3000);
                } break;

                case 1:
                {
                    cout << setw(73) << "This is the settings/instructions" << endl << endl;;
                    cout << setw(74) << "Use the arrow key LEFT to move LEFT;" << endl;
                    cout << setw(75) << "Use the arrow key RIGHT to move RIGHT;" << endl;
                    cout << setw(72) << "Use the arrow key UP to move UP;" << endl;
                    cout << setw(74) << "Use the arrow key DOWN to move DOWN;" << endl << endl;
                    cout << setw(87) << "Your starting and finishing positions are marked with '=';" << endl;
                    cout << setw(74) << "Your player is marked with '+';" << endl;
                    cout << setw(78) << "The walls of the maze are marked with '#';" << endl;
                    cout << setw(74) << "Your task is to complete the maze;" << endl;
                    cout << setw(61) << "Have fun!" << endl;

                    Sleep(15000);
                } break;

                case 2:
                {
                    return 0;
                } break;
                }

                break;
            }
        }
    }
}