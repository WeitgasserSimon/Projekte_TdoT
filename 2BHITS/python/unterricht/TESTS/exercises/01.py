def rotate(text: str, n: int) -> str:
    return text[-2:] + text[:-2] #pamemsistsu 

def grade(grades: dict) -> None:
    for key, values in grades.items():
        average: int = 0
        for x in values:
            average += x
        print(f"{key}: {average / len(values)}")
    
def counter(text: str) -> tuple: 
    d: int = 0
    c: int = 0
    for i in range(len(text)):
        if text[i].isalpha():
            c += 1
        if text[i].isdigit():
            d += 1
        else:
            continue
    return d, c


if __name__ == "__main__":
    text: str = "memsistsupa"
    print(rotate(text, 2))
    ###

    grades = {
        "Alice": [85, 90, 92],
        "Bob": [87, 85, 89],
        "Charlie": [77,92,95],
        "David": [70, 94, 80]
    }
    grade(grades)
    ###
    text: str = "Mein Kontostand beträgt 3184,43 Euro"
    print(counter(text))

class Fahrzeug: 
    def __init__(self) -> None:
        self._gewicht: float = 0.0 # in kg
    @property
    def gewicht(self) -> float:
        return self._gewicht * 2.5 # in lbs
    def gewicht(self, g) -> None:
        self._gewicht = g
    
    def __str__(self) -> str:
        return f"Das Fahrzeug wiegt {self._gewicht}"
    
class Kraftfahrzeug: 
    def __init__(self) -> None:
        super().__init__
        self._Leistung: float = 0
    # der rest ist 1 zu 1 der gleiche drckkkk
        