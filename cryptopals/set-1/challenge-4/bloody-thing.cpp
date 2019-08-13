#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<unsigned char> hex_to_vuchar(
	const std::string hex_input);
std::vector<std::string> decrypt_sb_xor(
	const std::vector<unsigned char> vuchar);

int main()
{
	const std::vector<float> ENGLISH_FREQS { 
			8.34, 1.54, 2.73, 4.14, 12.60,
			2.03, 1.92, 6.11, 6.71, 0.23,
			0.87, 4.24, 2.53, 6.80, 7.70,
			1.66, 0.09, 5.68, 6.11, 9.37,
			2.85, 1.06, 2.34, 0.20, 2.04, 0.06 };

	std::string hex_input = "7b5a4215415d544115415d5015455447414c155c46155f4058455c5b523f";

	// Convert to a vector of ASCII unsigned chars
	std::vector<unsigned char> vuchar;
	vuchar = hex_to_vuchar(hex_input);

	// Decrypt the single-byte XOR
	std::vector<std::string> printable_texts;
	printable_texts = decrypt_sb_xor(vuchar);

	// For each of the printable texts returned
	for (int i=0; i<printable_texts.size(); i++)
	{
		// Grab the text
		std::string text = printable_texts[i];

		// Print it
		std::cout << text << std::endl;
	}

	return 0;
}
