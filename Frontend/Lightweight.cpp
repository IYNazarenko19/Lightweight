#include <iostream>
#include <iomanip>
using namespace std;

void menu()
{
	cout << "                        ____    ____       ___    ___    ___    _____  ____    ____ _____" << endl;
	cout << "   /\\  /\\        /\\        /   |          |   |  |   |  |   |     |   |       |       |" << endl;
	cout << "  /  \\/  \\      /__\\      /    |____      |___|  |___|  |   |     |   |____   |       |" << endl;
	cout << " /        \\    /    \\    /     |          |      |\\     |   |   _ |   |       |       | " << endl;
	cout << "/          \\  /      \\  /____  |____      |      | \\    |___|   |_|   |____   |____   |" << endl;

	int choice;
	cout << endl << endl;
	cout << setw(63) << "|   1 --------> PLAY           |" << endl;
	cout << setw(63) << "|                              |" << endl;
	cout << setw(63) << "|   2 --------> RULES          |" << endl;
	cout << setw(63) << "|                              |" << endl;
	cout << setw(63) << "|   3 --------> DESCRIPTION    |" << endl;
	cout << setw(63) << "|______________________________|" << endl;
	cout << setw(63) << "|                              |" << endl;
	cout << setw(63) << "|         YOUR CHOICE?         |" << endl;

	cin >> choice;

	if (choice == 1)
	{

	}
	else if (choice == 2)
	{

	}
	else if (choice == 3)
	{

	}
	else
	{
		cout << "NOT A VALID NUMBER!" << endl;
	}
}

int main()
{
	menu();
}