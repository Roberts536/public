// A function that takes two equal-length hex strings
// and returns their XOR
#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
#include <iomanip>
using namespace std;

string hex_xor(string input_hex, string cross_hex)
{
	// Check that the strings are equal length
	if (input_hex.length() != cross_hex.length()) {
		throw invalid_argument("input strings must be of equal length");
	}
	
	// We work on 8-byte blocks, i.e. 16 hex chars
	const int MAX_BLOCK_SIZE = 16;
	const int NUM_BLOCKS = ceil(input_hex.length()/(float)MAX_BLOCK_SIZE);
	stringstream stream;
	for (int i=0; i<NUM_BLOCKS; i++) {
		// Extract the relevant blocks as unsigned longs
		string input_block_string = input_hex.substr(i*MAX_BLOCK_SIZE, MAX_BLOCK_SIZE);
		unsigned long input_block = stol(input_block_string, nullptr, 16);
		unsigned long cross_block = stol(
				cross_hex.substr(i*MAX_BLOCK_SIZE, MAX_BLOCK_SIZE), nullptr, 16);
		// XOR them, and append the result as a hex string to result_string
		unsigned long result_long = input_block ^ cross_block;
		stream << setfill('0') << setw(input_block_string.length())
			<< hex << result_long;
	}

	return stream.str();
}

