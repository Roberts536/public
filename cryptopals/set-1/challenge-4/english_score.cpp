// Code for Set 1, Challenge 1 in Cryptopals
// Single-byte XOR cipher
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <limits>
#include <cassert>

float chisq_stat(
	const std::vector<float> observed, 
	const std::vector<float> expected);

float english_score(std::string input_text) {

	// Make sure the input isn't empty
	assert(input_text.length()>0 &&
		"Input string cannot be empty.");

	// Strip to alphabet characters only and make lowercase
	std::stringstream stream;
	int special_count {0};
	for (int i=0; i<input_text.length(); i++) {
		unsigned char letter = input_text[i];
		if (isalpha(letter)) {
			stream << static_cast<unsigned char>(tolower(letter));
		}

		// Count the number of special chars for later
		else if (letter != ' ')
			special_count++;
	}
	std::string stripped_input = stream.str();

	// If the text has nontrivial length
	if (input_text.length() > 9)
	{
		// Make sure special chars aren't more than 20%
		if (special_count/(float)input_text.length()>0.2)
		{
			return std::numeric_limits<float>::max();
		}
	}

	// Calculate frequencies of each character
	std::vector<float> observed;
	observed.resize(26);
	for (int i=0; i<stripped_input.length(); i++) {
		unsigned char letter = stripped_input[i];
		observed[letter-97]++;	// a=97 in ASCII
	}

	// Calculate the expected letter frequencies
	std::vector<float> english_freqs { 
		8.34, 1.54, 2.73, 4.14, 12.60,
		2.03, 1.92, 6.11, 6.71, 0.23,
		0.87, 4.24, 2.53, 6.80, 7.70,
		1.66, 0.09, 5.68, 6.11, 9.37,
		2.85, 1.06, 2.34, 0.20, 2.04, 0.06 };
	std::vector<float> expected;
	expected.resize(26);
	for (int i=0; i<26; i++) {
		expected[i] = english_freqs[i] / 100;
		expected[i] *= stripped_input.length();
	}

	// Return the Chi-Squared statistic
	return chisq_stat(observed, expected);

}

