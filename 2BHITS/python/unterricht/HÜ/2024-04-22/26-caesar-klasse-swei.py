# https://de.wikipedia.org/wiki/Caesar-Verschl%C3%BCsselung
# encrypt/decrypt funktion mit 2 parametern: text, shift

class Caesar:
    def __init__ (self) -> None:
        pass

    def encode(self, plain_text:str, shift:int) -> str:
        cipher_text = ""
        for element in plain_text.lower():
            cipher_text += chr((ord(element) - ord('a') + shift) % 26 + ord('a'))
        return cipher_text

    def decode(self, cipher_text:str, shift:int) -> str:
        message = ""
        for element in cipher_text.lower():
            message += chr((ord(element) - ord('a') - shift) % 26 + ord('a'))
        return message

caesar:Caesar = Caesar()
cipher_text = caesar.encode("Hallo", 3)
print(cipher_text)
plain_text = caesar.decode(cipher_text, 3)
print(plain_text)