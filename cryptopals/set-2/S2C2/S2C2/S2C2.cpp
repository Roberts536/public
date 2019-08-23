//#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "readThroughChars/readThroughChars.h"
#include "base64.h"
#include "encrypt_aes_block.h"
#include "aes.h"
using CryptoPP::AES;
#include "base64_decode_file/base64_decode_file.h"

typedef unsigned char byte;

/*
Set 2, Challenge 2 of the Cryptopals Challenges:
Implement AES in CBC mode.
*/
int main()
{
	const std::string IN_FILE{ "10.txt" };
	const std::string OUT_FILE{ "10_output.txt" };
	const std::string RAW_FILE{ "raw.dat" };
	const byte IV[16]{ 0 };
	const byte KEY[AES::DEFAULT_KEYLENGTH+1] { "YELLOW SUBMARINE" };
	// Trailing null character will be ignored during encryption

	// Set up the filestreams
	base64_decode_file(IN_FILE, RAW_FILE);
	std::ifstream rawStream(RAW_FILE);
	if (!rawStream)
	{
		std::cerr << "File " << IN_FILE
			<< " could not be opened for reading.\n";
		return 1;
	}
	std::ofstream outStream(OUT_FILE);
	if (!outStream)
	{
		std::cerr << "File " << OUT_FILE
			<< " could not be opened for writing.\n";
	}

	// Store the output of the previous encryption
	byte addBlock[AES::BLOCKSIZE]{ *IV };

	while (rawStream)
	{
		// Grab a block from the file
		char rawBytes[AES::BLOCKSIZE+1];
		rawStream.get(rawBytes, AES::BLOCKSIZE+1);

		// Convert to byte type for encryption
		byte block[AES::BLOCKSIZE];
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			block[i] = static_cast<byte>(rawBytes[i]);
		}

		// XOR with the previous encrypted block (or IV)
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			block[i] ^= addBlock[i];
		}

		// Encrypt with ECB and append to file
		byte encrypted[AES::BLOCKSIZE];
		size_t encryptedBlocksize = 
			encrypt_ecb_block(encrypted, block, AES::BLOCKSIZE, KEY);
		memcpy(&addBlock, encrypted, AES::BLOCKSIZE);
		outStream << encrypted;
	}
}
