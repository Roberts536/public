/*
Function used in the 128b AES key scheduler.
The nonlinear function 'g' takes as input a 32-bit word and returns another.
It makes use of the AES S-box and requires a 'round coefficient' RC,
which is an element of the Galois field GF(2^8), i.e. an 8b value.
*/

#include <iostream>
#include <bitset>

std::bitset<32> key_schedule_g(std::bitset<32> input_word, int round)
{
	std::bitset<32> output_word;

	std::bitset<8> current_byte;
	for (int i = 0; i < 4; i++)
	{
		// Fill current_byte with the next byte along modulo 4
		// i.e. if i=0, current_byte becomes the second byte (index 1) of input_word
		for (int j = 0; j < 4; j++)
		{
			current_byte[j] = input_word[(j + 4 * (i+1)) % 16];
		}

		// Run the current byte through the AES S-box
		// TODO

		// For the first block, we XOR with the round coefficient
		if (i = 0)
		{
			// The round coefficient is equivalent to x^(r-1) in GF(2^8)
			// (Assuming we start the rounds at 1, not 0)
			std::bitset<8> round_coeff;
			if (round < 9)
			{
				round_coeff.set(9 - round);
			}
			else {
				// Polynomial x^9 must be reduced in GF(2^8) by the AES polynomial
				// It's reduced to the polynomial x^5 + x^4 + x^2 + x^1 => (00110110)_2
				round_coeff.set(3);
				round_coeff.set(4);
				round_coeff.set(6);
				round_coeff.set(7);
			}

			current_byte ^= round_coeff;
		}

		// Append the resulting byte to the output word
		for (int k = 0; k < 4; k++)
		{
			output_word[k + 4 * i] = current_byte[k];
		}
	}

	return output_word;
}
