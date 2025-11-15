'''
file    .py
author  Weitgasser Simon
date    2024-04-15
brief   cesar chiffre en und dec
'''

def fill_alphabet() -> list:
    liste = []
    for i in range(26):
        liste.append(f"{chr(ord('A') + i)}")
    print(liste)

def caesar_cipher(plain_text: str, shift: int) -> str:
    cipher_text = ""
    for char in plain_text:
        if char.isalpha():
            shifted_char = chr(((ord(char.upper()) - ord('A') + shift) % 26) + ord('A'))
            cipher_text += shifted_char if char.isupper() else shifted_char.lower()
        else:
            cipher_text += char
    return cipher_text

def encode(plain:str, key:int) -> str:
    return caesar_cipher(plain, key)

def decode(encoded:str, key:int) -> str:
    return caesar_cipher(encoded, -key)  # Die Entschlüsselung erfolgt durch Verschiebung in die entgegengesetzte Richtung

if __name__ == "__main__":
    fill_alphabet()
    plain_text = "jai mag malai kofta "
    key = 3
    encrypted_text = encode(plain_text, key)
    print("Encrypted text:", encrypted_text)

    decrypted_text = decode(encrypted_text, key)
    print("Decrypted text:", decrypted_text)
