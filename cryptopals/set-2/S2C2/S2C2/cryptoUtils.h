#pragma once

#include <iostream>
#include <fstream>
#include <string>

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

void ECBDecrypt(std::string source, std::string dest, byte* key);
