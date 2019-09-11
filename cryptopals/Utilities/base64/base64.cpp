#include "base64.h"
typedef unsigned char byte;
const char BASE64_LOOKUP[64]{
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
std::string result;

/*
Helper function. Coverts a block into a bitset.
E.g. 'aaa' -> <01100001 01100001 01100001>
*/
std::bitset<MAX_BLOCK_SIZE_BITS> blockToBitset(const std::string block)
{
	std::bitset<MAX_BLOCK_SIZE_BITS> outBits(0);
	for (int j = 0; j < MAX_BLOCK_SIZE; j++)
	{
		// The last block could be shorter
		if (block.length() >= j + 1)
		{
			std::bitset<MAX_BLOCK_SIZE_BITS> charBits(block[j]);
			outBits |= charBits;
		}

		if (j < MAX_BLOCK_SIZE - 1)
			outBits <<= 8;
	}
	return outBits;
}

/*
Base64 encodes an input string. 
*/
std::string base64_encode(const std::string input)
{
	// Base64 encodes bytes in blocks of three bytes
	int numBlocks{ (int) ceilf(input.size() / (float)MAX_BLOCK_SIZE) };

	for (int i = 0; i < numBlocks; i++)
	{
		std::string block{ input.substr(i * MAX_BLOCK_SIZE, MAX_BLOCK_SIZE) };
		std::bitset<MAX_BLOCK_SIZE_BITS> blockBits{ blockToBitset(block) };

		// Base64 characters are read off 6 bits at a time
		std::bitset<6> base64_char_bits;
		int numBase64Chars = (int)std::ceilf(8 * block.size() / (float)6);
		for (int j = 0; j < numBase64Chars; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				// Bitset index starts from lowest bit (as opposed to leftmost)
				base64_char_bits[k] = blockBits[6 * (3 - j) + k];
			}
			result += BASE64_LOOKUP[base64_char_bits.to_ulong()];
		}
		for (int j = numBase64Chars; j < 4; j++)
			result += '=';
	}
	
	return result;
}
