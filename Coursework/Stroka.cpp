#include "Stroka.h"
#include<iostream>

using namespace std;

void Stroka::Diagnostic()
{
	cout << "Конструктор Stroka(): " << ConstrWithoutArgs << " раз." << endl;
	cout << "Конструктор Stroka(int): " << ConstrInt << " раз." << endl;
	cout << "Конструктор Stroka(char): " << ConstrChar << " раз." << endl;
	cout << "Конструктор Stroka(const char*): " << ConstrConstChar << " раз." << endl;
	cout << "Конструктор Stroka(const Stroka&): " << ConstrConstStroka << " раз." << endl;
	cout << "-----------------------------------------------" << endl;
}

void Stroka::Show(void)
{
	cout << "Значение поля pointerChar: " << pointerChar << endl;
	cout << "Значение поля length: " << length << endl;
	cout << "Отработал метод Stroka::Show" << endl;
}

Stroka::Stroka()
{
	ConstrWithoutArgs++;
	length = 0;
	pointerChar = nullptr;
	cout << "Отработал конструктор Stroka()" << endl;
}

Stroka::Stroka(int input)
{
	ConstrInt++;
	length = input;
	pointerChar = new char[length + 1];
	if (input == 0) pointerChar[0] = '\0';
	cout << "Отработал конструктор Stroka(int)" << endl;
}

Stroka::Stroka(char input)
{
	ConstrChar++;
	length = 1;
	pointerChar = new char[length + 1];
	pointerChar[0] = input;
	pointerChar[1] = '\0';
	cout << "Отработал конструктор Stroka(char)" << endl;
}

Stroka::Stroka(const char* input)
{
	ConstrConstChar++;
	length = strlen(input);
	pointerChar = new char[length + 1];
	strcpy_s(pointerChar, length + 1, input);
	cout << "Отработал конструктор Stroka(const char*)" << endl;
}

Stroka::Stroka(const Stroka& input)
{
	ConstrConstStroka++;
	length = input.length;
	pointerChar = new char[length + 1];
	strcpy_s(pointerChar, length + 1, input.pointerChar);
	cout << "Отработал конструктор Stroka(const Stroka&)" << endl;
}

Stroka::~Stroka()
{
	if (pointerChar) delete[] pointerChar;
	cout << "Отработал деструктор ~Stroka()" << endl;
}
