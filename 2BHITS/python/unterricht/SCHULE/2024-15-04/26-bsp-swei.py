'''
file    bsp.py
author  Weitgasser Simon
date    2024-04-15
brief   ezz beispiiel
'''

def main() -> None:
    liste = []
    liste.append("Heute")
    liste.append("ist")
    liste.append("ein")
    liste.append("schoener")
    liste.append("Tag")
    liste.append("ist")
    wb: dict = {}

    for wort in liste:
        if wort in wb.keys():
            wb[wort] += 1
        else:
            wb[wort] = 1
        print(wort)


if __name__ == '__main__':
    main()
