#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "encrypt_ecb_block.h"

/*
Encrypts a block to dest using AES in ECB mode.
Assumes the key length is AES::DEFAULT_KEYLENGTH
*/
size_t encrypt_ecb_block(byte* dest, const byte* block, const size_t blockSize , const byte *key)
{
	try
	{
		ECB_Mode<AES>::Encryption ecbEncryption(key, AES::DEFAULT_KEYLENGTH);
		ecbEncryption.ProcessData(dest, block, blockSize);
	}
	catch (const CryptoPP::Exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}

	return blockSize;
}