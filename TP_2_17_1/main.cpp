#include "Sign.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Sign>& signs);
void changeObject(Marray<Sign>& signs);
void deleteObject(Marray<Sign>& signs);
void print(Marray<Sign>& signs);
void searchObjects(Marray<Sign>& signs);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Sign> signs;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			addObject(signs);
			break;
		case 2:
			changeObject(signs);
			break;
		case 3:
			deleteObject(signs);
			break;
		case 4:
			print(signs);
			break;
		case 5:
			searchObjects(signs);
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "5. Вывести запись по месяцу рождения" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Marray<Sign>& signs) {
	Sign student;
	student.inputFromConsole();
	signs += student;
	signs.sort();
}

void changeObject(Marray<Sign>& signs) {
	if (signs.getSize() > 0) {
		print(signs);
		cout << "Введите номер записи для изменения: ";
		signs[safeInput(1, signs.getSize()) - 1].change();
	}
	else
		cout << "Список записей пуст. Нечего изменять\n";
	signs.sort();
}

void deleteObject(Marray<Sign>& signs) {
	if (signs.getSize() > 0) {
		print(signs);
		cout << "Введите номер записи для удаления: ";
		signs -= safeInput(1, signs.getSize()) - 1;
	}
	else
		cout << "Список записей пуст. Нечего удалять\n";
	signs.sort();
}

void print(Marray<Sign>& signs) {
	if (signs.getSize() == 0)
		cout << "Список записей пуст.\n";
	else {
		cout << "Список записей\n";
		for (int i = 0; i < signs.getSize(); i++) {
			cout << i + 1 << ". Запись\n";
			signs[i].printToConsole();
		}
	}
}

void searchObjects(Marray<Sign>& signs) {
	if (signs.getSize() == 0)
		cout << "Список записей пуст\n";
	else {
		bool isPrint = false;
		int mounth = inputMounth();
		for (int i = 0; i < signs.getSize(); i++)
				if (signs[i].getBirthDate()[1] == mounth) {
					isPrint = true;
					signs[i].printToConsole();
				}
			
		if (!isPrint)
			cout << "Людей, родившихся в этот месяц нет.\n";
	}
}