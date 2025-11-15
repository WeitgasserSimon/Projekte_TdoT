'''
File: 2024-04-03_LZK02.py
Author: Weitgasser Simon
Date: 2024-04-03
Brief: 
'''

def main() -> None:
    # Einlesen des Namens
    print("Wie lautet ihr Name?")
    name:str = input("Name = ")

    vorname = ""
    nachname = ""
    vlesen = True
    for buchstabe in name:
        if buchstabe == " ":
            vlesen = False
        if vlesen:
            vorname = buchstabe + vorname
        else: 
            nachname = buchstabe + nachname

    # Position des Leerzeichens ermitteln
    pos:int = name.find(" ")
    # Zerlegen in Vor- und Nachname
    vorname:str = name[:pos]
    nachname:str = name[pos+1:]
    # Ausgabe von Vor- und Nachname in invertierter Ordnung
    print(f"Vorname = {vorname[::-1]}")
    print(f"Nachname = {nachname[::-1].upper()}")

    # Zerlegen in Vor- und Nachname
    # vorname, nachname = name.split(" ")


if __name__ == "__main__":
    main()
