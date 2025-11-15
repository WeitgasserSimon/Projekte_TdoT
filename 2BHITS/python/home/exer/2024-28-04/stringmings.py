def main():
    # Teilstrings
    text = "Hallo, wie geht es dir?"

    # Teilstring von Index 7 bis Index 11 (Achtung: Python beginnt mit Index 0)
    teilstring1 = text[7:11]
    print("Teilstring 1:", teilstring1)  # Ausgabe: "wie "

    # Teilstring von Index 13 bis zum Ende
    teilstring2 = text[13:]
    print("Teilstring 2:", teilstring2)  # Ausgabe: "ht es dir?"

    # Teilstring mit Schrittweite 2 (jedes zweite Zeichen)
    teilstring3 = text[::2]
    print("Teilstring 3:", teilstring3)  # Ausgabe: "Hlo i ete i?"

    # Umwandlungen
    # String zu Ganzzahl umwandeln
    string_zahl = "123"
    zahl = int(string_zahl)
    print("Zahl:", zahl)  # Ausgabe: 123

    # Zahl zu String umwandeln
    zahl_string = str(zahl)
    print("Zahl als String:", zahl_string)  # Ausgabe: "123"

    # Großbuchstaben
    text_groß = "Hallo Welt".upper()
    print("Großbuchstaben:", text_groß)  # Ausgabe: "HALLO WELT"

    # Kleinbuchstaben
    text_klein = "Hallo Welt".lower()
    print("Kleinbuchstaben:", text_klein)  # Ausgabe: "hallo welt"


if __name__ == "__main__":
    main()
