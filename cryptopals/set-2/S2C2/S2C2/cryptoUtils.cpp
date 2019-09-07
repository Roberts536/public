#include "cryptoUtils.h"

typedef unsigned char byte;

/*
Decrypts a binary file using AES in ECB mode.
Uses AES default key length and block size.
Message length must be a multiple of block size.
*/
void ECBDecrypt(std::string source, std::string dest, byte* key)
{
	// Set up the filestreams
	std::ifstream rawStream(source, std::ios_base::in | std::ios_base::binary);
	if (!rawStream)
	{
		std::cerr << "Error while opening file: " << source
			<< " for reading.\n";
	}
	std::ofstream outStream(dest);
	if (!outStream)
	{
		std::cerr << "Error while opening file: " << dest
			<< " for writing.\n";
	}

	// Set up for ECB Decryption
	ECB_Mode<AES>::Decryption ecbDecryption(key, AES::DEFAULT_KEYLENGTH);
	char rawBytes[AES::BLOCKSIZE];

	// Read raw bytes, decrypt and output
	while (rawStream)
	{
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			rawBytes[i] = rawStream.get();
		}

		// Break if the EOF has been reached
		if (rawStream.eof())
			break;

		// Convert to byte type for decryption
		byte block[AES::BLOCKSIZE]{ 0 };
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			block[i] = static_cast<byte>(rawBytes[i]);
		}

		// Decrypt with ECB
		byte decrypted[AES::BLOCKSIZE];
		try
		{
			ecbDecryption.ProcessData(decrypted, block, AES::BLOCKSIZE);
		}
		catch (const CryptoPP::Exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::exit(1);
		}

		// Output
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			byte letter{ decrypted[i] };
			if (isprint(letter) || letter == '\n')
			{
				std::cout << letter;
				outStream << letter;
			}
			else
			{
				std::cout << '.';
				outStream << '.';
			}
		}
	}
	
}
