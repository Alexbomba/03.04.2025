#include <iostream>
#include <windows.h>

using namespace std;

void Line(int length, char symbol, int color, bool horizontal) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 0; i < length; i++) {
		cout << symbol;
		if (!horizontal)
			cout << "\n";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Rectangle(int width, int height, char border, char fill, int borderColor, int fillColor, int cordX, int cordY) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int y = 0; y < height; y++) {
        COORD coord = { (short)cordX, (short)(cordY + y) };
        SetConsoleCursorPosition(h, coord);
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height - 1 || x == 0 || x == width -  1) {
                SetConsoleTextAttribute(h, borderColor);
                cout << border;
            }
            else {
                SetConsoleTextAttribute(h, fillColor);
                cout << fill;
            }
        }
    }
    SetConsoleTextAttribute(h, 7); 
}

double Cube(double number) {
    return number * number * number;
}

bool IsPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main()
{
    Line(20, '@', 12, true);
    Rectangle(20, 5, '#', '.', 12, 14, 5, 5);
    cout << "\n\nCube of number = " << Cube(4) << '\n';
    cout << IsPrime(17) << "\n";
    cout << IsPrime(88) << "\n";

}