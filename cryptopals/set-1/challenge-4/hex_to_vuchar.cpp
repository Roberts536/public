#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>

// Convert a hex string to a vector of unsigned chars
std::vector<unsigned char> hex_to_vuchar(const std::string hex_input)
{
	// Make space to store the output
	std::vector<unsigned char> vuchar;
	const int NUM_CHARS = ceil(hex_input.length()/(float)2);
	vuchar.reserve(NUM_CHARS);

	// Loop over pairs of hex numbers (i.e. bytes)
	for (int i=0; i<NUM_CHARS; i++)
	{
		// Take 2 hex characters as a substring
		std::string ss {hex_input.substr(2*i,2)};

		// Convert it to a uchar and add it to the output
		int ss_int = stoi(ss, nullptr, 16);
		vuchar.push_back(static_cast<unsigned char>(ss_int));
	}

	return vuchar;
}
