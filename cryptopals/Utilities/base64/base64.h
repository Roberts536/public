#pragma once

#include <iostream>
#include <string>
#include <bitset>

const int MAX_BLOCK_SIZE{ 3 };
const int MAX_BLOCK_SIZE_BITS{ 8 * MAX_BLOCK_SIZE };

void blockToBitset(const std::string& block, std::bitset<MAX_BLOCK_SIZE_BITS>& outBits);
std::string base64_encode(const std::string input);