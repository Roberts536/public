#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::string pad_pkcs7(int blockLength, std::string hex_message)
{
	// Determine the number of padding bytes needed
	unsigned int padSize{ blockLength - hex_message.length() / 2 % blockLength };
	if (padSize == 0)
		padSize = blockLength;

	// Pad the message
	std::stringstream paddedMsg;
	paddedMsg << hex_message;
	for (int i = 0; i < padSize; i++)
	{
		paddedMsg << std::setfill('0') << std::setw(2) 
			<< std::hex << padSize;
	}

	return paddedMsg.str();
}
