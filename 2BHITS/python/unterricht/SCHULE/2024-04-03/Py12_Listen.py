'''
File:   Py12_Listen.py
Author: Weitgasser Simon
Date:   2024-02-29 & 2024-03-04
Brief:  Listen raw

Listen sind neben Dictionaries eine der bedeutensten Datentypen in Python. 
Der Umgang mit Listen ist besonders einfach und vielseitig.
'''

import random
 
def listen() -> None:
    erzeugen_einer_liste()
    befuellen_einer_liste()
    zugriff_auf_listenelemente()
    durchlaufen_einer_liste()
    listen_aus_ranges()
    listenabstraction()
    listen_aus_string()
    sind_elemente_enthalten()
    sortieren_einer_liste()
 
def erzeugen_einer_liste() -> None:
    liste:list = list()
    print(f'{liste = }')
    liste:list = []
    print(f'{liste = }')
    liste:list  = [1, 2, 3, 4]
    print(f'{liste = }')
    liste:list = 100*[0, 1]
    print(f'{liste = }')
 
def befuellen_einer_liste() -> None:
    liste:list = [0, 1]
    liste.append(2)
    liste.append('A')
    liste.append(True)
    print(f'{liste = }')
    print(f'{liste = }')
 
def zugriff_auf_listenelemente() -> None:
    liste:list = [0, 1, 2, 3, 4, 5, 6, 6, 7, 8, 9]
    print(liste[0])
    print(liste[1])
    print(liste[2:5])
    print(liste[5:10:2])
 
def durchlaufen_einer_liste() -> None:
    liste = [0, 1, 2, 3, 4, 5, 6, 6, 7, 8, 9]
    for x in liste:
        print(x, end=' ')
    print('')
    i = 0
    while i < len(liste):
        print(liste[i], end=' ')
        i += 1
    print('')
    for i in range(len(liste)):
        print(liste[i], end=' ')    
    print('')
    for i, x in enumerate(liste):
        print(f'{i = } {x = }', end=' ')
    print('')
 
def listen_aus_ranges() -> None:
    liste:list = list(range(10))
    print(f'{liste = }')
    liste:list = [range(10)]
    print(f'{liste = }')
    liste:list = [*range(10)]
    print(f'{liste = }')
    *liste, = range(10)
    print(f'{liste = }')
 
def listenabstraction() -> None:
    liste:list = [x**2 for x in range(10)]
    print(f'{liste = }')
    liste:list = [_**2 for _ in range(10)]
    print(f'{liste = }')
    binary:list[int] = [int(_) for _ in '1010110101']
    print(f'{binary = }')
 
def listen_aus_string() -> None:
    satz:str = 'The quick brown fox jumps over the lazy dog'
    liste:list = list(satz)
    liste:list = [*satz]
    print(f'{liste = }')
    liste:list = [str(_) for _ in satz]
    print(f'{liste = }')
    liste:list[int] = [ord(_) for _ in satz]
    print(f"{liste=}")
    liste:list[int] = list(map(ord, list(satz)))
    print(f"{liste=}")

def sind_elemente_enthalten() -> None:
    satz:str = "The quick brown fox jumps over the lazy dog"
    woerter = satz.split(" ")
    print(woerter)
    if "The" in woerter:
        print("Das wort 'The' ist im Satz enthalten.")

def sortieren_einer_liste() -> None:
    liste:list[int] = [random.randint(1,6)for _ in range(10)]
    print(f"{liste=}")
    liste.sort()
    print(f"{liste=}")
    list.sort(reverse=True)
    print(f"{liste=}")

if __name__ == '__main__':
    listen()