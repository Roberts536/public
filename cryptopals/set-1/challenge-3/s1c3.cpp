// Code for Set 1, Challenge 1 in Cryptopals
// Single-byte XOR cipher
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <limits>
using namespace std;

float english_score(string plaintext_input);

int main() {

	const string HEX_INPUT = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

	float best_plaintext_score = numeric_limits<float>::max();
	string best_plaintext = "";

	// Check every possible byte as a key i
	for (int i=0; i<256; i++) {
		stringstream plaintext_stream;

		// Reverse the XOR cipher using key i
		bool plaintext_is_printable = true;
		for (int j=0; j<HEX_INPUT.length(); j+=2) {
			int letter_int = stoi(HEX_INPUT.substr(j,2),nullptr,16);
			int xor_result = letter_int ^ i;

			// Only accept printable characters
			if (!isprint(xor_result)) {
				plaintext_is_printable = false;
				break;
			}
			unsigned char result_char = xor_result;
			plaintext_stream << result_char;
		}

		// If printable, find score and compare to current best
		if(plaintext_is_printable) {
			float score = english_score(plaintext_stream.str());
			if (score < best_plaintext_score) {
				best_plaintext_score = score;
				best_plaintext = plaintext_stream.str();
			}
		}
	}

	cout << "The best plaintext is: ";
	cout << best_plaintext << endl;
	cout << "With a score of: " << best_plaintext_score;
	cout << endl;

	return 0;
}
