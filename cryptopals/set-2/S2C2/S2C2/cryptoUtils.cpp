#include "cryptoUtils.h"

typedef unsigned char byte;

/* Adds two AES blocks of size AES::BLOCKSIZE */
void addAESBlock(const byte* actorBlock, byte* victimBlock)
{
	for (int i = 0; i < AES::BLOCKSIZE; i++)
		victimBlock[i] ^= actorBlock[i];
}

/*
Decrypts a binary file using AES in the chosen mode.
Uses AES default key length and block size.
Message length must be a multiple of block size.
N.B. Even if the user wants ECB mode, they must pass
in a dummy IV which will not be used.
*/
void decryptFile(
	const AES_MODE mode,
	const std::string sourceFile,
	const std::string destFile,
	const byte* key,
	const byte* IV)
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
			<< destFile << " for writing.\n";
	}

	ECB_Mode<AES>::Decryption decryption(
		key, AES::DEFAULT_KEYLENGTH);
	char rawBytes[AES::BLOCKSIZE];
	byte previousBlock[AES::BLOCKSIZE];
	memcpy(previousBlock, IV, AES::BLOCKSIZE);

	while (rawStream)
	{
		// Must get chars one at a time else extraction
		// will stop if a delimiting char is encountered
		for (int i = 0; i < AES::BLOCKSIZE; i++)
			rawBytes[i] = rawStream.get();

		if (rawStream.eof())
			break;

		// Decryption object only accepts unsigned types
		byte block[AES::BLOCKSIZE]{ 0 };
		for (int i = 0; i < AES::BLOCKSIZE; i++)
			block[i] = static_cast<byte>(rawBytes[i]);

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

		if (mode == AES_CBC)
		{
			addAESBlock(previousBlock, decrypted);
			memcpy(previousBlock, block, AES::BLOCKSIZE);
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
