#include "cryptoUtils.h"

typedef unsigned char byte;

/*
Decrypts a binary file using AES in ECB mode.
Uses AES default key length and block size.
Message length must be a multiple of block size.
*/
void decryptFile(
	const AES_MODE mode,
	const std::string sourceFile,
	const std::string destFile,
	const byte* key)
{
	std::ifstream rawStream(sourceFile, std::ios_base::in 
							| std::ios_base::binary);
	if (!rawStream)
	{
		std::cerr << "Error while opening file: " 
			<< sourceFile << " for reading.\n";
	}
	std::ofstream outStream(destFile);
	if (!outStream)
	{
		std::cerr << "Error while opening file: " 
			<< destFile	<< " for writing.\n";
	}

	ECB_Mode<AES>::Decryption decryption(
		key, AES::DEFAULT_KEYLENGTH);
	char rawBytes[AES::BLOCKSIZE];

	while (rawStream)
	{
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			rawBytes[i] = rawStream.get();
		}

		if (rawStream.eof())
			break;

		// Decryption object only accepts unsigned types
		byte block[AES::BLOCKSIZE]{ 0 };
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			block[i] = static_cast<byte>(rawBytes[i]);
		}

		byte decrypted[AES::BLOCKSIZE];
		try
		{
			decryption.ProcessData(
				decrypted,
				block,
				AES::BLOCKSIZE
			);
		}
		catch (const CryptoPP::Exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::exit(1);
		}

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
