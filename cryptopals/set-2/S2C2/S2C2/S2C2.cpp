#include "S2C2.h"
using CryptoPP::AES;
typedef unsigned char byte;

/*
Set 2, Challenge 2 of the Cryptopals Challenges:
Implement AES decryption in CBC mode.
*/
int main()
{
	const std::size_t FIELD_WIDTH{ 3 };
	const std::string IN_FILE{ "S2C2/10.txt" };
	const std::string OUT_FILE{ "S2C2/10_output.txt" };
	const std::string RAW_FILE{ "S2C2/raw.bin" };
	const AES_MODE mode{ AES_CBC };

	// Key and IV arrays should not have null terminators
	byte KEY[AES::DEFAULT_KEYLENGTH]{};
	for (int i=0; i<AES::DEFAULT_KEYLENGTH; i++)
		KEY[i] = "YELLOW SUBMARINE"[i];
	byte IV[AES::BLOCKSIZE]{};
	IV[AES::BLOCKSIZE-1] = 0;

	// Decrypt
	base64_decode_file(IN_FILE, RAW_FILE);
	decryptFile(mode, RAW_FILE, OUT_FILE, KEY, IV);

	return 0;
}

