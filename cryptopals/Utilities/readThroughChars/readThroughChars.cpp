#include "readThroughChars.h"

/*
A function to read off a certain number of chars from an
input filestream, discarding the delimiting character and
moving onto the next line if needed.

If EOF is reached before num bytes have been read,
the vector is returned with all the characters before EOF.
*/

std::string readThroughChars(std::ifstream *inf, int num, char delim)
{
	// Check that the filestream is okay
	if (!(*inf))
		std::cerr << "Filestream is not good.";

	// Protect against negative input
	if (num < 0)
		num = 0;

	// Read off chars from the file
	std::string output;
	while (output.length() < num)
	{
		char this_char;
		(*inf).get(this_char);
		if ((*inf).eof())
			break;
		if (this_char != delim)
			output.push_back(this_char);
	}

	return output;
}
