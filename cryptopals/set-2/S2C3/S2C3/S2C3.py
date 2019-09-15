import AESUtils
import os
from cryptography.hazmat.primitives.ciphers import modes

mode = modes.ECB()
message = b"YELLOW SUBMARINE"
key = os.urandom(32)
iv = os.urandom(16)

ciphertext = AESUtils.encrypt(
                key,
                iv,
                message)
print(
    "The encrypted message: " 
    + str(ciphertext)
    )

plaintext = AESUtils.decrypt(
                key,
                ciphertext)
print("The plaintext: " + str(plaintext))
