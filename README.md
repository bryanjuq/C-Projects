# Symmetric Encryption

This project implements the functionality of a One-Time Pad encryption
techniquie to encrypt and decrypt a text file. 

Usage: ./symetric_encrypt [seed] [read file] [write file]

Sample run to encrypt:

./symmetric_encrypt 324516 out.txt out.enc

Sample run to decrypt:

./symmetric_encrypt 324516 out.enc out.txt

Notice that I need to use the same used seed to decrypt.

Enjoy!

