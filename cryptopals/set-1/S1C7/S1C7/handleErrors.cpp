#include <iostream>
#include <openssl/sha.h>
#include "openssl-test.h"
#include <openssl/opensslv.h>
#include <openssl/ssl.h>
#include <openssl/crypto.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

void handleErrors(void)
{
	ERR_print_errors_fp(stderr);
	abort();
}