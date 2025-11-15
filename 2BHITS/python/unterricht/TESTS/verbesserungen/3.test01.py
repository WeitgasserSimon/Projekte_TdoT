def count_letters_and_digits(text:str) -> tuple:
    letter_counter: int = 0
    digit_counter: int = 0
    # for c in text:
    #     if ord("a") <= ord(c) and ord(c) <=("z"):
    #         letter_counter+=1
    #     elif ord("A") <= ord(c) and ord(c) <=("Z"):
    #         letter_counter+=1
    #     elif ord("0") <= ord(c) and ord(c) <=("9"):
    #         digit_counter+=1
    c: str

    for c in text:
        if c.isalpha():
            letter_counter+=1
        elif c.isdigit():
            wwdigit_counter+=1

    return letter_counter, digit_counter

def grade_students(grades: dict) -> None:
    # for key in grades:
        # print(key, grades[key])

    for key, values in grades.items():
        # print(key, values)
        average_grade: int = 0
        for x in values:
            average_grade += x
        print(f"{key}: {average_grade / len(values)}")
        
def rotate(text: str, n:int) -> str:
    return text[-n:] + text[:-n]

def main():
    text: str = "Der 3. POS-Test ist am 29.04.2024"
    print(count_letters_and_digits(text))

    grades = {
        "Alice": [85, 90, 92],
        "Bob": [87, 85, 89],
        "Charlie": [77,92,95],
        "David": [70, 94, 80]
    }
    grade_students(grades)

    text = "Programmieraufgabe"
    print(rotate(text, 2))
if __name__ == "__main__":
    main()

class Fahrzeug:

    def __init__(self) -> None:
        self._Gewicht: float #protected

    @property
    def Gewicht(self) -> float:
        return self._Gewicht

    @Gewicht.setter
    def Gewicht(self,gewicht) -> None:
        self._Gewicht = gewicht

    def __str__(self) -> str:
        print(f"Fahrzeug mit Gewicht {self._Gewicht}")
    
class Kraftfahrzeug(Fahrzeug):
    def __init__(self) -> None:
        super().__init__()
        self._Leistung: float
    # der rest ist 1 zu 1 der gleiche dreck
    
    
