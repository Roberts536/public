//#include "pch.h"
#include <iostream>

#include "pad_pkcs7.h"

int main()
{
	std::string myString{ "4141424243434444" };
	std::string finalString{ pad_pkcs7(8,myString) };

	std::cout << finalString << std::endl;

	return 0;
}
