#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;
using CryptoPP::byte;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
#include <sstream>

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "cryptlib.h"
using CryptoPP::Exception;

#include "hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "aes.h"
using CryptoPP::AES;

#include "modes.h"
using CryptoPP::ECB_Mode;

#include "base64.h"
std::string base64_decode(std::string const& encoded_string);

int main(int argc, char* argv[])
{
	AutoSeededRandomPool prng;

	// Use the key given by Cryptopals
	const char key_text[]{ "YELLOW SUBMARINE" };
	byte key[AES::DEFAULT_KEYLENGTH];
	for (int i = 0; i < sizeof(key); i++)
	{
		key[i] = key_text[i];
	}

	string cipher, recovered;

	// Open the ciphertext input filestream
	std::string in_filename{ "7.txt" };
	std::ifstream inf(in_filename);
	// If there's a problem opening the ifstream
	if (!inf)
	{
		// Tell the user the problem, and exit
		std::cerr << "Could not open file: "
			<< in_filename << " for reading.\n";
		return 1;
	}

	// Keep pulling input from the file while we can
	while (inf)
	{
		// Pull a line off the input filestream
		string line;
		getline(inf, line);

		// Decrypt (uses 3rd party stuff) and add to sstream
		cipher += base64_decode(line);
	}

	// Decrypt
	try
	{
		// Initialise the Decryption object and feed it the key
		ECB_Mode< AES >::Decryption d;
		d.SetKey(key, sizeof(key));

		// Strip the padding as required, and decode
		StringSource s(cipher, true,
			new StreamTransformationFilter(d,
				new StringSink(recovered)
			)
		);

		cout << "Recovered text: " << recovered << endl;
	}
	catch (const CryptoPP::Exception& e)
	{
		cerr << e.what() << endl;
		std::exit(1);
	}

	return 0;
}