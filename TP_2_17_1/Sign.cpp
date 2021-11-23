#include "Sign.h"

Sign::Sign() : secondName("Не задано"), firstName("Не задано"), curSign(0)
{
	birthDate[0] = 0;
	birthDate[1] = 0;
	birthDate[2] = 0;
	cout << "Вызван конструктор Sign" << endl;
}

Sign::Sign(string secondName, string firstName, int birthDate[3], int curSign) :
	secondName(secondName), firstName(firstName), curSign(curSign)
{
	setBirthDate(birthDate);
	cout << "Вызван конструктор Sign" << endl;
}

Sign::Sign(const Sign& sign) : secondName(sign.secondName), firstName(sign.firstName), curSign(sign.curSign)
{
	setBirthDate(sign.birthDate);
	cout << "Вызван конструктор копирования Sign" << endl;
}

Sign::~Sign()
{
	cout << "Вызван деструктор Sign" << endl;
}

void Sign::inputFromConsole()
{
	cout << "Введите фамилию: ";
	getline(cin, secondName);
	cout << "Введите имя: ";
	getline(cin, firstName);
	cout << "Введите день рождения: ";
	birthDate[0] = safeInput(1, 31);
	birthDate[1] = inputMounth();
	cout << "Введите год рождения: ";
	birthDate[2] = safeInput(1, INT32_MAX);
	curSign = inputSign();
}

void Sign::printToConsole()
{
	cout << "Фамилия: " << secondName << endl;
	cout << "Имя: " << firstName << endl;
	cout << "Дата рождения: " << birthDate[0] << "." << birthDate[1] << "." << birthDate[2] << endl;
	cout << "Знак зодиака: " << SIGNS[curSign] << endl;
}

void Sign::change()
{
	cout << "Введите новую фамилию: ";
	getline(cin, secondName);
	cout << "Введите ново имя: ";
	getline(cin, firstName);
	cout << "Введите новый день рождения: ";
	birthDate[0] = safeInput(1, 31);
	birthDate[1] = inputMounth();
	cout << "Введите новый год рождения:\n";
	birthDate[2] = safeInput(1, INT32_MAX);
	curSign = inputSign();
}

Sign& Sign::operator=(const Sign& sign) {
	if (this == &sign)
		return *this;
	secondName = sign.secondName;
	firstName = sign.firstName;
	curSign = sign.curSign;
	setBirthDate(sign.birthDate);
	return *this;
}

bool Sign::operator>(Sign& sign) {
	return curSign > sign.curSign;
}