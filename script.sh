#!/bin/bash
# Break a Vignere cipher of key length 6
lowalph=({a..z})
upalph=({A..Z})
key_length=6
declare -a key
ciphertext=$(cat ./found1 | sed s/' '//g)
pwd_enc=$(echo "HCIKV RJOX" | sed s/' '//g)
echo "Length of ciphertext is: " ${#ciphertext}

# A function to look up the position in the alphabet of a letter
# Beware: the result is zero-indexed
function posalph {
	for i in {0..25}
	do
		if [[ "$1" == "${lowalph[$i]}" || "$1" == "${upalph[$i]}" ]]
		then
			echo $i
			return 0
		fi
	done
}

# Extract the 6 different ciphertexts coming from the key
declare -a ciph_arr
for (( i=0; i<$key_length; i++))
do
	sub_ciph=""	# This is one of the ciphertexts
	for (( j=i; j<${#ciphertext}; j+=$key_length ))
	do
		# Concatenate the matched letter
		sub_ciph="$sub_ciph""${ciphertext:$j:1}"
	done
	ciph_arr+=("$sub_ciph")
done

# Now we find the key of the cipher
# For each ciphertext, find the caesar which makes e the most freq letter
for ciph in "${ciph_arr[@]}"
do
	# Get most frequent letter and add it to the key
	letter=$(echo $ciph | grep -o [A-Z] | sort | uniq -c | sort -n | tail -c -2 | head -c -1)
	key+=("${lowalph[$(( ($(posalph $letter) - $(posalph e)) % 26 ))]}")
done

echo "The Vignere key is: ${key[@]}"

# Now make the key numeric
declare -a key_nums
for subkey in "${key[@]}"
do
	key_nums+=($(posalph $subkey))
done

function decode {
	echo "The plaintext message is: "
	input=$1
	for (( i=0; i<"${#input}"; i++ ))
	do
		target_index=$(posalph "${input:$i:1}")
		key_index="${key_nums[$i % $key_length]}"
		plain_index=$(( ($target_index - $key_index + 26) % 26 ))
		echo -n "${lowalph[$plain_index]}"

		# Formatting
		if [[ "i % (5*$key_length)" == 0 && "$i" -ne 0 ]]
		then
			echo ""
		elif [[ "i % $key_length" -eq "$key_length-1" && "$i" -ne 0 ]]
		then
			echo -n " "
		fi
	done

	echo ""
}

echo $(decode $ciphertext)
echo $(decode $pwd_enc) 
