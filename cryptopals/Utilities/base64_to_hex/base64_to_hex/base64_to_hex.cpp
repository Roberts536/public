// Code to convert base64 into hex
// Cryptopals utilities
#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <cmath>

int main()
{
	//std::stringstream in_stream_b64{ "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t" };
	std::stringstream in_stream_b64{ "SS" };
	std::stringstream out_stream;

	// Add a lookup table to get numbers from base64
	const char BASE64_LOOKUP[65] = {
	'A', 'B', 'C', 'D', 'E',
	'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y',
	'Z', 'a', 'b', 'c', 'd',
	'e', 'f', 'g', 'h', 'i',
	'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x',
	'y', 'z', '0', '1', '2',
	'3', '4', '5', '6', '7',
	'8', '9', '+', '/' };

	// Make a bitset and stringstream for use in the while loop
	std::bitset<24> block_bitset{};
	std::stringstream conversion_stream;
	conversion_stream << std::setfill('0') << std::hex;

	// While we can keep reading off the input stream
	int i{ 0 };
	while (in_stream_b64.good()) {

		// Try to pull off a base64 character
		char b64_char(in_stream_b64.get());
		
		// Get its number from the lookup table
		// NB EOF doesn't get converted but doesn't matter
		int b64_int;
		for (int j = 0; j < 64; j++) {
			if (BASE64_LOOKUP[j] == b64_char)
				b64_int = j;
		}

		// If we didn't read EOF, push the int onto the bitset
		if (!(b64_char == std::char_traits<char>::eof()))
		{
			block_bitset <<= 6;
			block_bitset |= b64_int;
		}

		// If the bitset is full, write hex result to output stream
		// Also do this if the stream has ended and block non-empty
		if (i % 4 == 3 || 
			(b64_char == std::char_traits<char>::eof() && i % 4 != 0))
		{
			// Set the output width based on number of characters read
			conversion_stream << std::setw(ceil((6*(i%4+1))/(float) 4));

			// Convert the bitset to an unsigned long
			unsigned long block_output{ block_bitset.to_ulong() };

			// Convert the number to hex
			std::string hex_string;
			conversion_stream << block_output;
			conversion_stream >> hex_string;
			conversion_stream.str("");
			conversion_stream.clear();

			// Put the hex string into the output stream
			out_stream << hex_string;

			// Reset the bitset 
			// Normally not necessary because the left-shift
			// erases what's in there. But when we reach EOF,
			// we might have to print out an incomplete block.
			block_bitset.reset();

			i++;
		}
	}
	std::cout << out_stream.str() << std::endl;

	return 0;
}
