

def encrypt(message:str, key:int) -> str:
    cipher:str = ""
    for char in message.upper():
        cipher += chr((ord(char) + key - ord("A")) % 26 + ord("A") ) # gegenfunktion von ord ist char

    return cipher


if __name__ == "__main__":
    message:str = "seas muje"
    key:int = 3
    cipher:str  = encrypt(message, key)
    print(cipher)
    