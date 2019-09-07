#include "base64_decode_file/base64_decode_file.h"
#include "readThroughChars/readThroughChars.h"
#include "base64.h"

#include <iomanip>
typedef unsigned char byte;

/*
Decodes a source file from Base64 to raw bytes,
placing the output in the destination file.
*/
void base64_decode_file(std::string source, std::string dest)
{
	// Prepare the input and filestreams
	std::ifstream inf(source);
	if (!inf)
	{
		std::cerr << "Error while opening file: " << source
			<< " for reading.\n";
	}
	std::ofstream outf(dest, 
		std::ios_base::out | std::ios_base::binary);
	if(!outf)
	{
		std::cerr << "Error while opening file: " << dest
			<< " for writing.\n";
	}

	while (inf)
	{
		// Decode four Base64 characters and write to file
		std::string fourChars{ readThroughChars(&inf, 4) };
		outf << base64_decode(fourChars);

		/*
		// Also write them to std::cout as integers
		for (char letter : base64_decode(fourChars))
		{
			byte letterByte = static_cast<byte>(letter);
			std::cout << std::setfill(' ')
				<< std::setw(4)
				<< static_cast<int>(letterByte);
		}
		*/
	}
}