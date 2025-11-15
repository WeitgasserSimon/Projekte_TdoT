'''
File:   Py09_Strings.py
Author: Weitgasser Simon
Date:   2024-02-26
Brief:  Strings
'''

def strings() -> None:
    kontatenation()
    mehrzeilige_strings()
    suchen_in_strings()
    ersetzen_in_strings() 
    teilen_von_strings()

def kontatenation() -> None: # Zeichenketten verketten, auf gut deutsch Text zsm kleben
    text1:str = "jai"
    text2:str = "ist mein Lieblingsinder"
    text:str = text1 + " " + text2 + "!"
    print(f"{text}")

def mehrzeilige_strings() -> None:
    text1:str = '''
    Hallo
    2BHITS!
    '''
    print(text1)
    text2:str = "Hallo" + \
                '' + \
                '2Bhits' + \
                '!'
    print(text2)

def teilstrings() -> None:
    text:str = "ich liebe meinen lieblingsinder"
    print(text[0])
    print(text[0:4])
    print(text[2:4])
    print(text[:5])
    print(text[:6])
    print(text[-2])
    print(text[-1])
    print(text[-6:-1])
    print(text[0:6:2])
    print(text[::-1])
    print(text[::-2])
    
def suchen_in_strings() -> None:
    text:str = "Hallo 2BHITS!"
    pos:int = text.find(" ")
    print(text[:pos])
    print(text[pos+1:])

def ersetzen_in_strings() -> None:
    text:str = "Hallo 2BHITS!"
    text = text.replace("Hallo", "Fick")
    print(text)

def teilen_von_strings() -> None:
    text:str = "Hallo 2BHITS!"
    liste = text.split(" ")
    print(liste)


if __name__ == "__main__":
    strings()