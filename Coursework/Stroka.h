#pragma once
#include <vector> 
#include<iostream>
using namespace std;

class Stroka
{
protected:
	int length;
	char* pointerChar;
	static int ConstrWithoutArgs;
	static int ConstrInt;
	static int ConstrChar;
	static int ConstrConstChar;
	static int ConstrConstStroka;
public:
	static void Diagnostic();
	char* GetStr() const { cout << "Отработал метод Stroka::getStr() ";  return  pointerChar; }
	int GetLen() const { cout << "Отработал метод Stroka::getLen() ";  return length; }
	void Show();


	Stroka();
	Stroka(int);
	Stroka(char);
	Stroka(const char*);
	Stroka(const Stroka&);
	~Stroka();
};
