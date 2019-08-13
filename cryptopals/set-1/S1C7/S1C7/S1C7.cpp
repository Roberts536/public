#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <openssl/err.h>

#include "base64.h"

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
	unsigned char *iv, unsigned char *plaintext);
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
	unsigned char *iv, unsigned char *ciphertext);

int main()
{
	// Initialise crypto libraries
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();

	// Get the first line from the file
	std::string fromFile{ "CRIwqt4+szDbqkNY+I0qbDe3LQz0wiw0SuxBQtAM5TDdMbjCMD/venUDW9BL" };
	fromFile = base64_decode(fromFile);

	// A 128 bit key
	unsigned char *key = (unsigned char *)"YELLOW SUBMARINE";

	// A 128 bit IV
	unsigned char *iv = (unsigned char *)"0123456789012345";

	// Message to be encrypted
	unsigned char *plaintext =
		(unsigned char *)"I'm back and I'm having fun with all of my friends, who are also having fun themselves.";

	/*
	 * Buffer for ciphertext. Ensure the buffer is long enough for the
	 * ciphertext which may be longer than the plaintext, depending on the
	 * algorithm and mode.
	 */
	unsigned char ciphertext[128];

	/* Buffer for the decrypted text */
	unsigned char decryptedtext[128];

	int decryptedtext_len, ciphertext_len;

	/* Encrypt the plaintext */
	ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv,
		ciphertext);

	/* Do something useful with the ciphertext here */
	printf("Ciphertext is:\n");
	BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

	/* Decrypt the ciphertext */
	decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv,
		decryptedtext);

	/* Add a NULL terminator. We are expecting printable text */
	decryptedtext[decryptedtext_len] = '\0';

	/* Show the decrypted text */
	printf("Decrypted text is:\n");
	printf("%s\n", decryptedtext);


	return 0;

}
