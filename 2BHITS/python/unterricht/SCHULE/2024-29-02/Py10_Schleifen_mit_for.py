'''
File:   Py10_Schleifen_mit_for.py
Author: Weitgasser Simon
Date:   2024-02-29
Brief:  for-Schleifen
'''

def schleife_mit_for() -> None:
    for_mit_strings()
    ranges()
    break_in_for()
    continue_in_for()
    else_in_for()

def for_mit_strings() -> None:
    satz:str = "The quick brown fox jumps over the lazy dog"
    print(satz)
    for buchstabe in satz:
        print(buchstabe, end="")
    print("")

def ranges() -> None:
    # Ranges sind Generatorenobjekte
    # d.h. sie generieren auf Verlangen nacheinander Zahlen
    r = range(10) # Bereich der Zahlen 0 bis 9 (10 Zahlen)
    print(r, type(r))
    for i in range(10):
        print(i)
    # unpack Operator
    print(*range(10))
    print(*range(1,10))
    print(*range(1,10,2))
    print(*range(9,-1,-2))
    for i in range(10):
        i += 2 # Vorsicht!
        print(i)

def break_in_for() -> None:
    for i in range(10):
        if i == 4:
            break
        print(i, end="")
    print("")

def continue_in_for() -> None:
    for i in range(10):
        if i % 2 == 0:
            continue
        print(i, end=" ")
    print(" ")
def else_in_for() -> None:
    for i in range(10):
        print(i, end=",")
        # if i == 4:
        #     break
    else: 
        print("BACKSPACE")
    print(" ")


if __name__ == "__main__":
    schleife_mit_for()