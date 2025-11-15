def rotate(text, n) -> str:
    return text[-n:] + text[:-n]  # die letzten zwei + alles bis zu den letzten zwei

def digi_char_counter(text) -> tuple:
    digi: int = 0
    char: int = 0

    c: str
    for c in text:
        if c.isalpha():
            char += 1
        elif c.isdigit():
            digi += 1
    return char, digi

def average(grades: dict) -> None:
    for key, value in grades.items():
        average:int = 0
        for x in value:
            average += x
        print(f"{key}: {average / len(value)}")
    


if __name__ == "__main__":
    text: str = "Programmieraufgabe" 
    print(rotate(text, 2)) # ausgabe soll "beProgrammieraufga" sein
    ### 

    text: str = "Habe zu viel cash 361"
    print(digi_char_counter(text))
    ###

    grades = {
        "Muje": [80, 88, 90, 74],
        "Ammar": [92, 30, 88, 100],
        "Jai": [96, 94, 98, 100],
        "Lukas": [100, 88, 82, 73]
    }
    average(grades)
    