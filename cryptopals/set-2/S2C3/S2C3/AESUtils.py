import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend

def encrypt(key, iv, inputBytes):
    backend = default_backend()
    encryptor = Cipher(
        algorithms.AES(key),
        modes.ECB(),
        backend=backend
        ).encryptor()
    # the buffer needs to be at least len(data) + n - 1 where n is 
    # cipher/mode block size in bytes
    buf = bytearray(31)
    len_encrypted = encryptor.update_into(inputBytes, buf)
    # get the ciphertext from the buffer reading only the bytes 
    # written to it (len_encrypted)
    ct = bytes(buf[:len_encrypted]) + encryptor.finalize()
    return ct

def decrypt(key, ct):
    backend = default_backend()
    decryptor = Cipher(
        algorithms.AES(key),
        modes.ECB(),
        backend=backend
        ).decryptor()
    return decryptor.update(ct) + decryptor.finalize()