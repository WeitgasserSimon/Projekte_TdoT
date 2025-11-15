'''
File: Py03_Eingaben.py
Author: Weitgasser Simon 
Date: 2024-19-02
Brief: Eingaben mit Input
'''

def eingaben():
    eingaben_mit_input()
    formatierte_wertzuweisungen()

def eingaben_mit_input():
    print('\n Eingaben mit Input:')
    print('-------------------')
    print('Bitte geben Sie eine Ganzzahl x ein:')
    try:
        x = input('x = ')
        print(x, type(x))
    except:
        print('Die Eingabe war keine Ganzzahl')
    


def formatierte_wertzuweisungen():
    print('\n Formatierte Wertzuweisungen:')
    print('-------------------')
    a  = 1_000_000_000
    print(f'{a=:_}')
    b:int = int(1e9)    #typecast mit int(), ! typehint ist keine Deklaration !
    print(b, type(b), id(b))    # id für die adresse, type für den datentyp

if __name__ == '__main__':
    eingaben()