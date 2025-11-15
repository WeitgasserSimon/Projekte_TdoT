from typing import List
from matplotlib import pyplot as plt
import os

print(os.getcwd())

ref_char_dist = {  
    'a': 0.0651, 'b': 0.0189, 'c': 0.0306, 'd': 0.0508, 'e': 0.1740, 'f': 0.0166,
    'g': 0.0301, 'h': 0.0476, 'i': 0.0755, 'j': 0.0027, 'k': 0.0121, 'l': 0.0344,
    'm': 0.0253, 'n': 0.0978, 'o': 0.0251, 'p': 0.0079, 'q': 0.0002, 'r': 0.0700,
    's': 0.0727, 't': 0.0615, 'u': 0.0435, 'v': 0.0067, 'w': 0.0189, 'x': 0.0003,
    'y': 0.0002, 'z': 0.0113
}
alphabet_size = len(ref_char_dist)


def encrypt(message: str, key: int) -> str:
    if key < 0 or key > alphabet_size:
        key = key % alphabet_size

    list_of_chars = list(message.lower())
    keys = list(ref_char_dist.keys())
    for i in range(len(message)):
        if list_of_chars[i] in keys:
            list_of_chars[i] = chr((ord(list_of_chars[i]) - ord('a') + key) % alphabet_size + ord('a'))
    return "".join(list_of_chars)


def decrypt(message:str, key:int) -> str:
    return encrypt(message,-key)

def calculate_key(statistic: List[float]) -> int:
    max_idx_cipher_text = 0
    for i in range(len(statistic)):
        if statistic[i] < statistic[max_idx_cipher_text]:
            max_idx_cipher_text = i

    max_idx_reference = 0
    ref = list(ref_char_dist.values())
    for i in range(len(ref)):
        if ref[i] > ref[max_idx_reference]:
            max_idx_reference = i

    key = max_idx_cipher_text - max_idx_reference
    print("Key:", key)
    return key

def analyze_ciphertext(ciphertext: str) -> List[float]:
    ciphertext = ciphertext.lower()
    liste = [0] * 26
    for c in ciphertext:
        if c in ref_char_dist:
            liste[ord(c) - ord("a")] += 1
    anzahl = sum(liste)
    for i in range(len(liste)):
        liste[i] = liste[i] / anzahl
    return liste


def print_character_distribution(char_dist: List[float]) -> None:
    plt.figure()
    plt.bar(range(alphabet_size), list(ref_char_dist.values()), width=0.8, align='center', color='r')
    plt.bar(range(alphabet_size), list(char_dist), width=0.5, align='center', color='b')
    plt.title("Character distribution for Caesar-Cipher")
    plt.xticks(range(alphabet_size), list(ref_char_dist.keys()))
    plt.show()


def main() -> None:
    plain_text: str
    with open("Message.txt") as file:
        plain_text = file.read()
    key = 3
    print(plain_text)
    cipher_text = encrypt(plain_text, key)
    print(cipher_text)
    statistics = analyze_ciphertext(cipher_text)
    print_character_distribution(statistics)

    # Entfernen Sie die Kommentare, wenn Sie den Bruteforce-Teil verwenden möchten
    # for key in range(alphabet_size):
    #     decrypted_text = decrypt(cipher_text, key)
    #     print(key, "-->", decrypted_text)
    calculate_key(statistics)
if __name__ == "__main__":
    print("*** Start ***")
    main()
    print("*** End ***")
