//#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "readThroughChars.h"
#include "base64.h"
#include "encrypt_ecb_block.h"
#include "aes.h"
using CryptoPP::AES;

typedef unsigned char byte;

/*
Programme for Set 2, Challenge 2 of the Cryptopals Challenges:
Implement AES in CBC mode.
*/
int main()
{
	const byte IV[16]{ 0 };
	const byte KEY[AES::DEFAULT_KEYLENGTH+1] { "YELLOW SUBMARINE" };
	// Trailing null character will be ignored during encryption

	// Set up the input filestream
	std::string in_filename{ "10.txt" };
	std::ifstream inf(in_filename);
	if (!inf)
	{
		std::cerr << "File " << in_filename
			<< " could not be opened for reading.\n";
		return 1;
	}

	// Set up the output filestream
	std::string out_filename{ "10_output.txt" };
	std::ofstream outf(out_filename);
	if (!outf)
	{
		std::cerr << "File " << out_filename
			<< " could not be opened for writing.\n";
	}

	// A buffer to store raw bytes for extraction
	std::string byteBuffer;

	// A block to store the output of the last encryption
	byte addBlock[AES::BLOCKSIZE]{ *IV };

	// Convert its contents to bytes (i.e. unsigned char)
	while (inf)
	{
		// Fill up the buffer with raw bytes decoded from Base64
		if (byteBuffer.length() < AES::BLOCKSIZE)
		{
			// Need at least ceil(AES::BLOCKSIZE * 4 / 3) new chars
			// Must also be a multiple of 4 for Base64 decoding
			std::string fourChars{ 
				readThroughChars(&inf, 4*AES::BLOCKSIZE) };
			byteBuffer += base64_decode(fourChars);
		}

		// Move the first AES::BLOCKSIZE bytes from buffer to array
		char block[AES::BLOCKSIZE];
		std::size_t length{ byteBuffer.copy(block, AES::BLOCKSIZE) };
		if (!inf.eof())	//If EOF, buffer might be too short (& we don't need)
			byteBuffer = byteBuffer.substr(AES::BLOCKSIZE, byteBuffer.length());

		// Convert to byte type for encryption
		byte blockBytes[AES::BLOCKSIZE];
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			blockBytes[i] = static_cast<byte>(block[i]);
		}

		// XOR with the previous encrypted block (or IV)
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			blockBytes[i] ^= addBlock[i];
		}

		// Encrypt with ECB and append to file
		byte encrypted[AES::BLOCKSIZE];
		size_t encryptedBlocksize = 
			encrypt_ecb_block(encrypted, blockBytes, AES::BLOCKSIZE, KEY);
		memcpy(&addBlock, encrypted, AES::BLOCKSIZE);
		outf << encrypted;
	}

}
