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
	const byte KEY[AES::DEFAULT_KEYLENGTH+1] { "YELLOW SUBMARINE" };

	// Set up the filestreams
	base64_decode_file(IN_FILE, RAW_FILE);
	std::ifstream rawStream(RAW_FILE, std::ios_base::in | std::ios_base::binary);
	if (!rawStream)
	{
		std::cerr << "Error while opening file: " << RAW_FILE
			<< " for reading.\n";
	}
	std::ofstream outStream(OUT_FILE);
	if (!outStream)
	{
		std::cerr << "Error while opening file: " << OUT_FILE
			<< " for writing.\n";
	}

	// Set up for ECB Decryption
	ECB_Mode<AES>::Decryption ecbDecryption(KEY, AES::DEFAULT_KEYLENGTH);
	byte addBlock[AES::BLOCKSIZE]{ *IV };
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

		/*
		// XOR with the previous encrypted block (or IV)
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			block[i] ^= addBlock[i];
		}
		*/

		// Decrypt with ECB
		byte decrypted[AES::BLOCKSIZE];
		try
		{
			ecbDecryption.ProcessData(decrypted, block, AES::BLOCKSIZE);
			memcpy(&addBlock, decrypted, AES::BLOCKSIZE);
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

	return 0;
}
