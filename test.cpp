#include "Randoms.h"

#include <iostream>

void TEST_RANDOM_UINTS() {
	std::cout << __FUNCSIG__ << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << Random::Uint32() << " ";
	}
	std::cout << "\n\n";
}		  
		  
void TEST_RANDOM_INTS() {
	std::cout << __FUNCSIG__ << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << Random::Int32() << " ";
	}
	std::cout << "\n\n";
}		  
		  
void TEST_RANDOM_FLOATS() {
	std::cout << __FUNCSIG__ << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << Random::Float() << " ";
	}
	std::cout << "\n\n";
}		  
		  
void TEST_RANDOM_DOUBLES() {
	std::cout << __FUNCSIG__ << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << Random::Double() << " ";
	}
	std::cout << "\n\n";
}		  
		  
void TEST_RANDOM_BOOLS() {
	std::cout << __FUNCSIG__ << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << std::boolalpha << Random::Bool() << " ";
	}
	std::cout << "\n\n";
}		 
		  
void TEST_RANDOM_CHARS() {
	std::cout << __FUNCSIG__ << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << Random::Char() << " ";
	}
	std::cout << "\n\n";
}		 
		 
void TEST_RANDOM_LETTERS() {
	std::cout << __FUNCSIG__ << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << Random::Letter() << " ";
	}
	std::cout << "\n\n";
}		  
		  
void TEST_RANDOM_NAMES() {
	std::cout << __FUNCSIG__ << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << Random::Name() << " ";
	}
	std::cout << std::endl;
}



int main() {
	TEST_RANDOM_UINTS();
	TEST_RANDOM_INTS();
	TEST_RANDOM_FLOATS();
	TEST_RANDOM_DOUBLES();
	TEST_RANDOM_BOOLS();
	TEST_RANDOM_CHARS();
	TEST_RANDOM_LETTERS();
	TEST_RANDOM_NAMES();
	return 0;
}