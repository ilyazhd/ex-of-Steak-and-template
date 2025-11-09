#include "header.h"

int main() {

	Stack<char> CH;
	std::string ch;


	//вагоны 0  -  белый
	//       1  -  черный
	std::cout << "input string of 0 and 1:\n";
	std::cin >> ch;
	std::cout << CH.VagonNormalise(ch);

	//std::cout << "input string with scobci:\n";
	//std::cin >> ch;
	//std::cout << CH.IsRightCh(ch);

	return 0;
}