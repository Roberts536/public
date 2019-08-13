// Code for Set 1, Challenge 1 in Cryptopals
// Single-byte XOR cipher
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cassert>

float english_score(std::string plaintext_input);

/*
Decrypt a single-byte XOR cipher by brute-forcing
all 256 possible keys.

For each key, we compare the character frequencies
to what would be expected in English text using
Pearson's Chi-squared test.

Return a vector of all the strings that are
printable when decrypted.
*/
std::vector<std::string> decrypt_sb_xor(
	const std::vector<unsigned char> vuchar)
{
	// Make sure the input isn't empty
	assert(vuchar.size()>0 &&
		"Input vector cannot have zero length");

	// Make somewhere to keep the good outputs
	std::vector<std::string> outputs;

	// For every possible one-byte key i
	unsigned char i {0};
	do
	{
		// Make somewhere to store the plaintext
		std::stringstream text_stream;

		// Operate on each char in the ciphertext
		bool is_printable = true;
		for (int j=0; j<vuchar.size(); j++)
		{
			// Reverse XOR with key i
			unsigned char xor_result = vuchar[j] ^ i;

			// If the character is printable
			if (isprint(xor_result))
			{
				// Add it to the plaintext stream
				text_stream << xor_result;
			} 
			
			// Line feeds are also OK
			else if (xor_result != 10) 
			{
				// But reject unprintable characters
				is_printable = false;
				break;
			} 			
		}

		// If printable, add it to the outputs
		if (is_printable &&	text_stream.str().length()>0)
			outputs.push_back(text_stream.str());

		i++;
	}
	/* After all keys have been tried, the 
	unsigned char wraps back to 0 and this 
	condition evaluates false */
	while (i > 0);

	//std::cout << "Hello" << std::endl;
	return outputs;
}
