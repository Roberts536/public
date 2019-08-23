#include "base64_decode_file.h"
#include "readThroughChars/readThroughChars.h"
#include "base64.h"

/*
Decodes a source file from Base64 to raw bytes,
placing the output in the destination file.
*/
void base64_decode_file(std::string source, std::string dest)
{
	// 4 times this number of bytes will be pulled off the file at a time
	const size_t QUARTER_BLOCK_SIZE{ 100 };

	// Prepare the input and filestreams
	std::ifstream inf(source);
	if (!inf)
	{
		std::cerr << "File " << source
			<< " cannot be opened for reading.\n";
		exit(1);
	}
	std::ofstream outf(dest);
	if (!outf)
	{
		std::cerr << "File " << dest
			<< " cannot be opened for writing.\n";
		exit(1);
	}

	while (inf)
	{
		// Decode four Base64 characters and write to file
		std::string fourChars{ readThroughChars(&inf, 4) };
		outf << base64_decode(fourChars);
	}
}