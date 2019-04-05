// Main file for set 1 challenge 2 in cryptopals challenges
#include <iostream>
#include <string>
using namespace std;

string hex_xor(string input_hex, string cross_hex);

int main() {
	
	const string INPUT_HEX = "1c0111001f010100061a024b53535009181c";
	const string CROSS_HEX = "686974207468652062756c6c277320657965";
	
	cout << "Performing XOR with: " << endl << CROSS_HEX << endl;
	cout << "On: " << endl << INPUT_HEX << endl;
	cout << "Result: " << endl << hex_xor(INPUT_HEX, CROSS_HEX) << endl;

	return 0;
}
