#pragma once
#include "Stroka.h"
#include<iostream>

class DesStroka :
	public Stroka
{
private:
	static int ConstrWithoutArgs2;
	static int ConstrInt2;
	static int ConstrConstChar2;
	static int ConstrConstDesStroka;
public:
	static void Diagnostic();
	bool IsPositive();
	int GetValue() const { return atoi(pointerChar); }

	DesStroka();
	DesStroka(int);
	DesStroka(const char*);
	DesStroka(const DesStroka&);
	~DesStroka();

	DesStroka& operator = (const DesStroka&);
	friend DesStroka operator + (const DesStroka&, const DesStroka&);
	friend DesStroka operator + (const DesStroka&, const char*);
	friend DesStroka operator + (const char*, const DesStroka&);
};
