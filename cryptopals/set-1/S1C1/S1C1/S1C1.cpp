// Code to convert hex into base64
// Cryptopals challenges, set 1, challenge 1
#include <iostream>
#include <string>
#include <array>
#include <bitset>

int main()
{
	const std::string HEX_INPUT{ "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d" };
	//const std::string HEX_INPUT("49276d20");
	const char BASE64_LOOKUP[64] = {
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
	std::string result_base64{ "" };

	// We work on blocks of size at most 24 bits
	// This is 6 hex characters, or 4 base64 characters
	const int MAX_BLOCK_SIZE = 6;
	int num_blocks = ceil(HEX_INPUT.size() / (float)MAX_BLOCK_SIZE);

	// Convert block-by-block
	for (int i = 0; i < num_blocks; i++) {

		// Extract the as a string and convert to a bitset
		std::string block = HEX_INPUT.substr(i*MAX_BLOCK_SIZE, MAX_BLOCK_SIZE);
		std::bitset<24> block_bits(std::stol(block, nullptr, 16));
		// If contents doesn't fill a multiple of 6 bits, left-shift
		block_bits <<= (2 * (block.size() % 3));

		// Convert the bitset into base64 characters
		std::bitset<6> base64_char_bits;
		int num_used_bits = MAX_BLOCK_SIZE * ceil(4 * block.size() / (float)MAX_BLOCK_SIZE);
		for (int j = num_used_bits / 6 - 1; j >= 0; j--) {
			// Get the relevant 6 bits from the bitset
			for (int k = 0; k < 6; k++) {
				base64_char_bits[k] = block_bits[6 * j + k];
			}
			// Convert to base64 and append to results string
			result_base64 += BASE64_LOOKUP[base64_char_bits.to_ulong()];
		}

	}

	std::cout << result_base64 << std::endl;

	return 0;
}
