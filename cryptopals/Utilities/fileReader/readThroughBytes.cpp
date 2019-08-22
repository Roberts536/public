#include "readThroughBytes.h"

/*
A function to read off a certain number of bytes from an
input filestream, discarding the delimiting character and
moving onto the next line if needed.

If EOF is reached before numBytes bytes have been read,
the vector is returned with all the characters before EOF.
*/

std::vector<char> readThroughBytes(std::ifstream *inf, int numBytes, char delim)
{
	// Check that the filestream is okay
	if (!(*inf))
	{
		std::cerr << "Filestream is not good.";
	}

	if (numBytes < 0)
		numBytes = 0;

	// Read off bytes from the file
	std::vector<char> bytes;
	while (bytes.size() < numBytes)
	{
		char this_char;
		(*inf).get(this_char);
		if ((*inf).eof())
			break;
		if (this_char != delim)
			bytes.push_back(this_char);
	}

	return bytes;
}
