#!/bin/bash
: ' A script to solve level 6 of the Krypton challenge.
Based on the observation that a byte will always be
encoded the same way if it appears in the same position.
This means we can decrypt the ciphertext one byte
at a time.
'
ciph=PNUKLYLWRQKGKBE
plain=""
upalph=({A..Z})
lowalph=({a..z})
ourdir=$(pwd)
echo "" > input
echo "" > output
chmod 666 input output
cd /krypton/krypton6

for (( i=1; i<=$(echo -n $ciph | wc -m); i++ ))
do
	for (( j=0; j<26; j++ ))
	do
		found=false
		# Add one character to the plaintext and encrypt
		letter="${lowalph[$j]}"
		echo $plain$letter > $ourdir/input
		./encrypt6 $ourdir/input $ourdir/output
		outbytes=$(cat $ourdir/output | hexdump -v -n $i -e '1/1 "%02X" " "')
		ciphbytes=$(echo $ciph | hexdump -v -n $i -e '1/1 "%02X" " "')

		# See if the encrypted text matches the ciphertext
		if [ "$ciphbytes" == "$outbytes" ]
		then
			# We've found the next letter of plaintext
			found=true
			plain=$plain$letter
			break
		fi
	done
	if [ $found = false ]
	then
		# This means we couldn't match the ith byte
		echo "NO MATCH FOUND"
		exit 1
	fi
done
echo $plain
