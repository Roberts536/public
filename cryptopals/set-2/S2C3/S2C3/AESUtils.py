import os
from math import ceil
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend

AES_DEFAULT_KEY_LENGTH = 16
AES_BLOCK_SIZE = 16

def numBlocksRequired(message, blockSize):
    return 

def encrypt(mode, key, iv, inputBytes):

    backend = default_backend()
    encryptor = Cipher(
        algorithms.AES(key),
        mode,
        backend=backend
        ).encryptor()

    buf = bytearray(len(inputBytes) + AES_BLOCK_SIZE - 1)
    lenEncrypted = encryptor.update_into(inputBytes, buf)
    ct = bytes(buf[:lenEncrypted]) + encryptor.finalize()
    return ct

def decrypt(key, ct):
    backend = default_backend()
    decryptor = Cipher(
        algorithms.AES(key),
        modes.ECB(),
        backend=backend
        ).decryptor()
    return decryptor.update(ct) + decryptor.finalize()
