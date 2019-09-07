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
	// Trailing null character will be ignored during encryption

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

	// Create the decryption object
	ECB_Mode<AES>::Decryption ecbDecryption(KEY, AES::DEFAULT_KEYLENGTH);

	// Store the output of the previous encryption
	byte addBlock[AES::BLOCKSIZE]{ *IV };
	char rawBytes[AES::BLOCKSIZE];

	while (rawStream)
	{
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			rawBytes[i] = rawStream.get();
		}

		//rawStream.get(rawBytes, AES::BLOCKSIZE + 1)
		
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
		
		// Convert back to char and append to file
		std::cout << "\n";
		for (int i = 0; i < AES::BLOCKSIZE; i++)
		{
			byte letter{ decrypted[i] };
			if (isalpha(letter) || letter == ' ')
			{
				std::cout << std::setfill(' ')
					<< std::setw(FIELD_WIDTH) 
					<< static_cast<char>(letter);
			}
			else
			{
				std::cout << std::setfill(' ')
					<< std::setw(FIELD_WIDTH) 
					<< "*";
			}
			
		}
	}
	if (rawStream.fail())
	{
		std::cerr << "\nFailbit set. Number of characters read: "
			<< rawStream.gcount();
	}

	return 0;
}
