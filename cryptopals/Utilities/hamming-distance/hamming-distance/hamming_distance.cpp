/*
A function to find the Hamming distance between two strings. 
The Hamming distance, or edit distance, is the number of
differing bits. The strings must be of equal length.
*/
#include <string>
#include <iostream>
#include <cassert>
#include <bitset>
#include "hamming_distance.h"

int hamming_distance(std::string input_string_1, std::string input_string_2)
{
	// Check that the strings are of equal length
	assert(input_string_1.length()==input_string_2.length() &&
		"Input strings must have equal length." );

	// Make a variable to store the Hamming distance
	int hamming_distance{ 0 };

	// Loop over each character in the input strings
	for (int i = 0; i < input_string_1.length(); i++)
	{
		// Store the relevant letters in bitsets
		std::bitset<8> bits1{ static_cast<unsigned long>(input_string_1[i]) };
		std::bitset<8> bits2{ static_cast<unsigned long>(input_string_2[i]) };

		// Find the edit distance between them
		bits1 ^= bits2;
		hamming_distance += bits1.count();
	}

	return hamming_distance;
}