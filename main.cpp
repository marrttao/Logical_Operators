#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string>
using namespace std;

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void setcolor(unsigned short color) {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(con, color);
}

void set_background_color(unsigned short color) {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(con, (color << 4) | 0x0F);
}

void display_menu(int selected) {
    system("cls");
    cout << "#>-------<MENU>-------<#" << endl;
    cout << "|      1. task_1       |" << endl;
    cout << "|      2. task_2       |" << endl;
    cout << "|      3. task_3       |" << endl;
    cout << "|      4. task_4       |" << endl;
    cout << "#>--------------------<#" << endl;

    int y_coord = 1;
    for (int i = 1; i <= 5; ++i) {
        gotoxy(10, y_coord);
        if (i == selected) {
            set_background_color(0x0A);
        }
        else {
            setcolor(7);
        }
        switch (i) {
        case 1: cout << "Task_1"; break;
        case 2: cout << "Task_2"; break;
        case 3: cout << "Task_3"; break;
        case 4: cout << "Task_4"; break;
        case 5: cout << "Exit"; break;
        }
        y_coord++;
    }
    setcolor(7);
}

int main() {
    int selected = 1;
    display_menu(selected);
    int a,b;
    while (true) {
        char choice = _getch();
        if (choice == -32) {
            choice = _getch();
            switch (choice) {
            case 72:
                if (selected > 1) selected--;
                break;
            case 80:
                if (selected < 5) selected++;
                break;
            }
            display_menu(selected);
        }
        else if (choice == 13) {
            system("cls");
            switch (selected) {
            case 1:
                
                cout << "Enter a number: ";
                cin >> a;
                cout << endl << ((a % 2 == 0) ? "Number is even" : "Number is odd") << endl;
                break;
            case 2:
                
				cout << "Enter number: ";
				cin >> a;
				cout << "Enter number: ";
				cin >> b;
                cout << endl << ((a < b) ? a : b)<< endl;
                break;
            case 3:
				cout << "Enter number: ";
				cin >> a;
				cout << endl << ((a > 0) ? "Positive" : (a<0) ? "Negative" : "Zero") << endl;
                break;
            case 4:
                cout << "Enter number: ";
                cin >> a;
                cout << "Enter number: ";
                cin >> b;
                cout << endl << ((a == b) ? "Numbers are similar" : (a > b) ? to_string(b) + ", " + to_string(a) : to_string(a) + ", " + to_string(b)) << endl;
                break;

            case 5:
                return 0;
            }
            system("pause");
            display_menu(selected);
        }
    }
    return 0;
}