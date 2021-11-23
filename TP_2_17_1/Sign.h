#pragma once
#include "helper.h"
#include "Marray.h"
using namespace std;

class Sign
{
private:
	string secondName, firstName;
	int birthDate[3]; //day mounth year
	int curSign;
public:
	Sign();
	Sign(string secondName, string firstName, int birthDate[3], int curSign);
	Sign(const Sign& student);
	~Sign();

	void inputFromConsole();
	void printToConsole();
	void change();

	string getSecondName() { return secondName; }
	void setSecondName(string secondName) { this->secondName = secondName; }

	string getFirstName() { return firstName; }
	void setFirstName(string firstName) { this->firstName = firstName; }

	int* getBirthDate() { return birthDate; }
	void setBirthDate(const int birthDate[3]) { this->birthDate[0] = birthDate[0]; this->birthDate[1] = birthDate[1]; this->birthDate[2] = birthDate[2]; }

	int getCurSign() { return curSign; }
	void setCurSign(int curSign) { this->curSign = curSign; }

	Sign& operator=(const Sign& sign);
	bool operator>(Sign& sign);
};

