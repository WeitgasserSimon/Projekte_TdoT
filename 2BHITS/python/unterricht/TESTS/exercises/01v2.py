def rotate(text, n) -> str:
    return text[-n:] + text[:-n]

def char_digi_counter(text) -> tuple:
    char: int = 0
    digi:int = 0
    c: str

    for c in text:
        if c.isalpha():
            char += 1
        elif c.isdigit():
            digi += 1
    return char, digi


    

if __name__ == "__main__":
    text = "Programmieraufgabe" 
    print(rotate(text, 2))    # Ausgabe "beProgrammieraufga"
    ###

    text = "UFO 361"
    print(char_digi_counter(text))
    ###
    grades = {
        "Jai": [100, 100, 100, 90],
        "muje": [90, 90, 90, 100]
    }
