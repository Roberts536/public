#pragma once

#include "base64.h"

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;
using CryptoPP::byte;
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

size_t encrypt_ecb_block(byte* dest, const byte* block, const size_t blockSize, const byte *key);
size_t decrypt_ecb_block(byte* dest, const byte* block, const size_t blockSize, const byte *key);
