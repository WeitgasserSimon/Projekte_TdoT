'''
File:   Py11_Schleifen_mit_while.py
Author: Weitgasser Simon
Date:   2024-02-29
Brief:  while-Schleifen
'''

def schleife_mit_while() -> None:
    klassische_for_schleife()

def klassische_for_schleife() -> None:
    i = 0
    while i < 10:
        print(i, end=" ")
        i += 1
    print(" ")

# Auch in der while-Schleife gibt es das break, continue und else

if __name__ == "__main__":
    schleife_mit_while()