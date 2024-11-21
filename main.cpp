#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string>
using namespace std;

void gotoxy(int x, int y) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
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
    int a;
    const int tank_size = 300; // Move the declaration outside the switch statement
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
                cout << "Enter a number with 6 digits: ";
                cin >> a;
                if (to_string(a).length() != 6) {
                    cout << "The number must have 6 digits!" << endl;
                    break;
                }
                else {
                    string num_str = to_string(a);
                    int sum1 = (num_str[0] - '0') + (num_str[1] - '0') + (num_str[2] - '0');
                    int sum2 = (num_str[3] - '0') + (num_str[4] - '0') + (num_str[5] - '0');
                    if (sum1 == sum2) {
                        cout << "The number is lucky!" << endl;
                    }
                    else {
                        cout << "The number is not lucky!" << endl;
                    }
                }
                break;

            case 2:
                cout << "Enter a number with 4 digits: ";
                cin >> a;
                if (to_string(a).length() != 4) {
                    cout << "The number must have 4 digits!" << endl;
                    break;
                }
                else {
                    int digit4 = a % 10;
                    int digit3 = (a / 10) % 10;
                    int digit2 = (a / 100) % 10;
                    int digit1 = (a / 1000) % 10;

                    cout << "Result: " << digit2 << digit1 << digit4 << digit3 << endl;
                }
                break;

            case 3: {
                int numbers[7];
                cout << "7 Numbers: " << endl;
                cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3] >> numbers[4] >> numbers[5] >> numbers[6];
                int max1 = (numbers[0] > numbers[1]) ? numbers[0] : numbers[1];
                int max2 = (numbers[2] > numbers[3]) ? numbers[2] : numbers[3];
                int max3 = (numbers[4] > numbers[5]) ? numbers[4] : numbers[5];
                int max4 = numbers[6];
                int max12 = (max1 > max2) ? max1 : max2;
                int max34 = (max3 > max4) ? max3 : max4;
                int max_final = (max12 > max34) ? max12 : max34;
                cout << "Maximum number : " << max_final << endl;
                break;
            }
            case 4: {
                int AB, BC;
                int luggage_size;
                int refueling;
                cout << "Enter the distance between A and B: ";
                cin >> AB;
                cout << "Enter the distance between B and C: ";
                cin >> BC;
                cout << "Enter the luggage size: ";
                cin >> luggage_size;

                if (luggage_size <= 2000) {
                    int you_need;
					
                    if (luggage_size < 500) {

                        you_need = (AB+BC) * 1;
                    }
                    else if (luggage_size < 1000) {
                        you_need = (AB + BC) * 4;
                    }
                    else if (luggage_size < 1500) {
                        you_need = (AB + BC) * 7;
                    }
                    else {
                        you_need = (AB + BC) * 9;
                    }
                    if (you_need > tank_size) {
                        int you_need_to_b;
                        if (luggage_size < 500) {

                            you_need_to_b = AB * 1;
                        }
                        else if (luggage_size < 1000) {
                            you_need_to_b = AB * 4;
                        }
                        else if (luggage_size < 1500) {
                            you_need_to_b = AB * 7;
                        }
                        else {
                            you_need_to_b = AB * 9;
                        }
                        if (you_need_to_b > tank_size) {
                            cout << "You can't fly this route" << endl;
                        }
                        else {
                            refueling = tank_size - you_need_to_b;
							cout << "You need: " << you_need_to_b << " liters " << "From A to B for refueling and you need to refill " << refueling << endl;
                        }
                    }
                    else {
                        refueling = tank_size - you_need;

                        cout << "You need: " << you_need << " liters " << "From A to C" << endl;
                    }
                }
                else {
                    cout << "You can't fly this route" << endl;
                }
                break;
            }
            case 5:
                return 0;
            }
            system("pause");
            display_menu(selected);
        }
    }
    return 0;
}
