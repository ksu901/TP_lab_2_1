#include "helper.h"

int inputMounth() {
	for (int i = 0; i < 12; i++)
		std::cout << i + 1 << ". " << MOUNTH[i] << std::endl;
	std::cout << "¬ведите номер мес€ца: ";
	return safeInput(1, 12) - 1;
}

int inputSign() {
	for (int i = 0; i < 12; i++)
		std::cout << i + 1 << ". " << SIGNS[i] << std::endl;
	std::cout << "¬ведите номер знака зодиака: ";
	return safeInput(1, 12) - 1;
}