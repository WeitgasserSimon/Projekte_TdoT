'''
File:   Py08_Verzweigungen.py
Author: Weitgasser Simon
Date:   2024-02-26
Brief:  Verzweigungen
'''

def verzweigungen() -> None:
    fallunterscheidung()
    ternaerer_operator()

def fallunterscheidung() -> None:
    x:int = 2
    y:int = 10
    if x < y:
        print("x < y")
    elif x > y:
        print("x > y")
    else:
        print(f"{x} == {y}")

def ternaerer_operator() -> None:
    a:int = 10
    b = 20 if a < 15 else -15

if __name__ == "__main__":
    verzweigungen()