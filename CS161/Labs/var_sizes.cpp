//var_sizes.cpp
#include <iostream>


#define NUM_BITS_IN_BYTE 8

int main ()
{
	
	std::cout << "A char takes up " << sizeof(char) << " bytes of memory\n";
	std::cout << "A int takes up " << sizeof(int) << " bytes of memory\n";
	std::cout << "A float takes up " << sizeof(float) << " bytes of memory\n";
	std::cout << "A long takes up " << sizeof(long) << " bytes of memory\n";
	std::cout << "A short takes up " << sizeof(short) << " bytes of memory\n";
	std::cout << "A double takes up " << sizeof(double) << " bytes of memory\n";
	std::cout << "A bool takes up " << sizeof(bool) << " bytes of memory\n";
	
	
	
	return 0;
}