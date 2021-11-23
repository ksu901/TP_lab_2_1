#include "Sign.h"

Sign::Sign() : secondName("�� ������"), firstName("�� ������"), curSign(0)
{
	birthDate[0] = 0;
	birthDate[1] = 0;
	birthDate[2] = 0;
	cout << "������ ����������� Sign" << endl;
}

Sign::Sign(string secondName, string firstName, int birthDate[3], int curSign) :
	secondName(secondName), firstName(firstName), curSign(curSign)
{
	setBirthDate(birthDate);
	cout << "������ ����������� Sign" << endl;
}

Sign::Sign(const Sign& sign) : secondName(sign.secondName), firstName(sign.firstName), curSign(sign.curSign)
{
	setBirthDate(sign.birthDate);
	cout << "������ ����������� ����������� Sign" << endl;
}

Sign::~Sign()
{
	cout << "������ ���������� Sign" << endl;
}

void Sign::inputFromConsole()
{
	cout << "������� �������: ";
	getline(cin, secondName);
	cout << "������� ���: ";
	getline(cin, firstName);
	cout << "������� ���� ��������: ";
	birthDate[0] = safeInput(1, 31);
	birthDate[1] = inputMounth();
	cout << "������� ��� ��������: ";
	birthDate[2] = safeInput(1, INT32_MAX);
	curSign = inputSign();
}

void Sign::printToConsole()
{
	cout << "�������: " << secondName << endl;
	cout << "���: " << firstName << endl;
	cout << "���� ��������: " << birthDate[0] << "." << birthDate[1] << "." << birthDate[2] << endl;
	cout << "���� �������: " << SIGNS[curSign] << endl;
}

void Sign::change()
{
	cout << "������� ����� �������: ";
	getline(cin, secondName);
	cout << "������� ���� ���: ";
	getline(cin, firstName);
	cout << "������� ����� ���� ��������: ";
	birthDate[0] = safeInput(1, 31);
	birthDate[1] = inputMounth();
	cout << "������� ����� ��� ��������:\n";
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