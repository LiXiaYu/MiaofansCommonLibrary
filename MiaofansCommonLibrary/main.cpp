#include <iostream>
#include <string>

#include "BigInt.h"


int main() 
{
	using namespace MiaofansCommonLibrary;

	using Int2333 = BigInt<2333>;

	Int2333 a(5522);
	Int2333 b(-888);

	Int2333 c = a + b;
	
	std::string sc = c.to_string();

	std::cout << sizeof(Int2333) << std::endl;

	//std::cout << sc << std::endl;
	return 0;

}