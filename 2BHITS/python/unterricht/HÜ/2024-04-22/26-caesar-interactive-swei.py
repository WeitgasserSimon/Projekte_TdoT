'''
author: Weitgasser Simon
date: 22.04.2024
brief: einfache cäsar verschlüsselung ausprogrammiert
'''
class CaesarCipher:
    def __init__(self, shift: int = None) -> None:
        self._shift: int = shift

    @property
    def shift(self) -> int:
        return self._shift

    @shift.setter
    def shift(self, shift: int) -> None:
        self._shift = shift

    def encrypt_decrypt(self, text: str, shift: int) -> str:
        result = ""
        for char in text.lower():
            if char.isdigit() or char == " ":
                result += char
            elif char.isalpha():
                result += chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
        return result


if __name__ == "__main__":
    # Displaying the logo
    logo = """
    ,adPPYba, ,adPPYYba,  ,adPPYba, ,adPPYba, ,adPPYYba, 8b,dPPYba,  
    a8"     "" ""     `Y8 a8P_____88 I8[    "" ""     `Y8 88P'   "Y8  
    8b         ,adPPPPP88 8PP"""""""  `"Y8ba,  ,adPPPPP88 88          
    "8a,   ,aa 88,    ,88 "8b,   ,aa aa    ]8I 88,    ,88 88          
     `"Ybbd8"' `"8bbdP"Y8  `"Ybbd8"' `"YbbdP"' `"8bbdP"Y8 88   
            88             88                                 
           ""             88                                 
                          88                                 
     ,adPPYba, 88 8b,dPPYba,  88,dPPYba,   ,adPPYba, 8b,dPPYba,  
    a8"     "" 88 88P'    "8a 88P'    "8a a8P_____88 88P'   "Y8  
    8b         88 88       d8 88       88 8PP""""""" 88          
    "8a,   ,aa 88 88b,   ,a8" 88       88 "8b,   ,aa 88          
     `"Ybbd8"' 88 88`YbbdP"'  88       88  `"Ybbd8"' 88          
                  88                                             
                  88  
    """
    print(logo.strip())  # Mit strip() werden führende und abschließende Leerzeichen entfernt

    caesar_cipher = CaesarCipher()
    quit_program = False

    while not quit_program:
        print('Type "encode" to encrypt or "decode" to decrypt:')
        action = input().lower()

        print("Type your message:")
        message = input()

        print("Type the shift number:")
        shift = int(input())

        if action == "encode":
            print("Here's the encoded result: " + caesar_cipher.encrypt_decrypt(message, shift))
        elif action == "decode":
            print("Here's the decoded result: " + caesar_cipher.encrypt_decrypt(message, -1 * shift))
        else:
            print("Invalid action. Choose between 'encode' and 'decode'.")

        print('Type "yes" if you want to go again. Otherwise type "no".')
        decision_quit = input().lower()
        if decision_quit == "no":
            print("Goodbye!")
            quit_program = True
