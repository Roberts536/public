import AESUtils
import os
from cryptography.hazmat.primitives.ciphers import modes

mode = modes.ECB()
message = "YELLOW SUBMARINE".encode('utf-8')
key = os.urandom(AESUtils.AES_DEFAULT_KEY_LENGTH)
iv = os.urandom(AESUtils.AES_BLOCK_SIZE)

ciphertext = AESUtils.encrypt(
    mode, key, iv, message)
print("The encrypted message: " + str(ciphertext))

plaintext = AESUtils.decrypt(key, ciphertext)
print("The plaintext: " + plaintext.decode('utf-8'))
