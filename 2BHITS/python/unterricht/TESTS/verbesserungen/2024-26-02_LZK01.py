'''
File: Py05_LZK.py
Author: Weitgasser Simon
Date: 2024-26-02
Brief: LZK
'''

def getNumber(name:str) -> None:
    while (True):
        print(f"Gib die Länge {name} ein:")
        try: 
            x = int(input(f"{name} = "))
            return x

        except:
            print("Die Eingabe war falsch, bitte noch einmal eingeben")
    
def area2(a, b) -> int:
    return a * b

if __name__ == "__main__":
    a = getNumber("a")
    b = getNumber("b")
    print(f"A = {area2(a, b)}")