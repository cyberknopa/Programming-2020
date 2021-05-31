#include<iostream>
#include "Stroka.h"
#include "IdentStroka.h"
#include "DesStroka.h"
#include <vector>
using namespace std;
Stroka* input();
bool Check(Stroka** allObjects);
static vector<string> objectType;

	int main() {
		setlocale(LC_ALL, "Russian");
		Stroka** allObjects = new Stroka*[5];
		for (size_t i = 0; i < 5; i++)
		{
			allObjects[i] = input();
		}
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Экземпляры классов созданы. Теперь для созданных экземпляров будет произведена проверка всех разработанных методов" << endl;	
		cout << "---------------------------------------------------------------------------" << endl;
		if (Check(allObjects)) {
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "Проверка методов прошла без ошибок. Об успешности реализации можно судить из информации в консоли вывода." << endl;
		}
		else {
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "Во время проверки разработанных методов произошла ошибка. Используйте отладку для устранения." << endl;
		}
		DiagnosticPrint();
		cout << "Тестирование завершено." << endl;
	}

	Stroka* input() {
		cout << "------------------------------------------------------------" << endl;
		cout << "Выберите класс. Строка_идентификатор - введите \"1\"; Десятичная_строка - введите \"2\"" << endl << "Введите номер: ";
		int classNumber;
		cin >> classNumber;
		while ((classNumber != 1) && (classNumber != 2)) {
			cout << "Введён неверный номер. Введите номер ещё раз: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> classNumber;		
		}
		if (classNumber == 1) {
			cout << "Введите идентификатор: ";
			string id;
			cin >> id;
			IdentStroka* obj = new IdentStroka(id.c_str());
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			objectType.push_back("IdentStroka");
			return obj;
		}
		else {
			cout << "Введите десятичное число: ";
			string number;
			cin >> number;
			DesStroka* obj = new DesStroka(number.c_str());
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			objectType.push_back("DesStroka");
			return obj;
		}
	}

	bool Check(Stroka** allObjects) {
		for (size_t i = 0; i < 5; i++)
		{
			if (objectType[i] == "IdentStroka") {
				try {
					cout << allObjects[i]->GetStr() << endl;
					cout << allObjects[i]->GetLen() << endl;
					IdentStroka tmp("itmo");
					*(allObjects[i]) = tmp;
					allObjects[i][3];
					IdentStroka tmp2("fbit");
					cout << (*(IdentStroka*)(allObjects[i]) + tmp2).GetStr() << endl;
					cout << (*(IdentStroka*)(allObjects[i]) + "hello world").GetStr() << endl;
					cout << ("My name is Alex " + *(IdentStroka*)(allObjects[i])).GetStr() << endl;
					allObjects[i]->Show();
				}
				catch(exception e){
					return false;
				}
				return true;
			}
			else {
				try {
					cout << allObjects[i]->GetStr() << endl;
					cout << allObjects[i]->GetLen() << endl;
					cout << ((DesStroka*)allObjects[i])->IsPositive() << endl;
					cout << ((DesStroka*)allObjects[i])->GetValue() << endl;
					DesStroka tmp("125");
					*(allObjects[i]) = tmp;
					cout << (*(DesStroka*)(allObjects[i]) + tmp).GetValue() << endl;
					cout << (*(DesStroka*)(allObjects[i]) + "228").GetValue() << endl;
					cout << ("1337" + *(DesStroka*)(allObjects[i])).GetValue() << endl;
					allObjects[i]->Show();
				}
				catch(exception e){
					return false;
				}
				return true;
			}
		}
	}

	void DiagnosticPrint() {
		cout << "---------------------------------------------------" << endl;
		cout << "Количество вызванных конструкторов:" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Класс Stroka:" << endl;
		Stroka::Diagnostic();
		cout << "---------------------------------------------------" << endl;
		cout << "Класс DesStroka:" << endl;
		DesStroka::Diagnostic();
		cout << "---------------------------------------------------" << endl;
		cout << "Класс IdentStroka:" << endl;
		IdentStroka::Diagnostic();
		cout << "---------------------------------------------------" << endl;
	}
