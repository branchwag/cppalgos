#include <iostream>

int main(int argc, char* argv[]) {
	if (argc > 1) {
		char c = argv[1][0]; //first char, first arg
		std::cout << "Character: " << c << "\n";
		std::cout << "ASCII: " << (int)c << std::endl;
	} else {
		std::cout << "Please provide char as argument" << std::endl;
	}
	return 0;
}
