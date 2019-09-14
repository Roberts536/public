#include "S2C2.h"
using CryptoPP::AES;
typedef unsigned char byte;

/*
Set 2, Challenge 2 of the Cryptopals Challenges:
Implement AES in CBC mode.
*/
int main()
{
	const std::size_t FIELD_WIDTH{ 3 };
	const std::string IN_FILE{ "S2C2/7.txt" };
	const std::string OUT_FILE{ "S2C2/7_output.txt" };
	const std::string RAW_FILE{ "S2C2/raw.bin" };
	const byte IV[16]{ 0 };

	// Prepare the key
	const byte KEY_STRING[AES::DEFAULT_KEYLENGTH+1] { "YELLOW SUBMARINE" };
	byte KEY[AES::DEFAULT_KEYLENGTH]{};
	for (int i = 0; i < AES::DEFAULT_KEYLENGTH; i++)
		KEY[i] = KEY_STRING[i];

	// Decrypt
	base64_decode_file(IN_FILE, RAW_FILE);
	decryptFile(AES_ECB, RAW_FILE, OUT_FILE, KEY);

	return 0;
}

