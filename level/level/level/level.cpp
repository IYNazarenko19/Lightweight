#include<iostream>
#include<conio.h>
#include<stdlib.h>

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