#include <iostream>
#include <string>
#include "hamming_distance.h"

int main()
{
	std::string in1{ "this is a test" };
	std::string in2{ "wokka wokka!!!" };

	int distance{ hamming_distance(in1, in2) };

	std::cout << distance << std::endl;

	return 0;
}
