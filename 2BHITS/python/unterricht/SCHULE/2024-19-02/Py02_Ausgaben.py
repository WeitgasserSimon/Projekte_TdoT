'''
File: Py02_Ausgaben.py
Author: Weitgasser Simon
Date: 2024-19-02
Brief: Ausgaben mit print()
'''

def ausgaben() -> None:
    eine_variable()
    mehrere_variablen()
    formatspezifikationen()
    raw_strings()

def eine_variable() -> None:
    print('\n Eine Variable:')
    print('--------------------')
    i:int = 1
    print(i)
    print('i =', i)
    print('i = ' + str(i))
    print('i = {}'.format(i))
    print(f'i = {i}')           # f für formated string
    print(f'{i=}')              # Wert und Name der Variable

def mehrere_variablen() -> None:
    print('\n Mehrere Variablen:')
    print('--------------------')
    i:int = 1
    j:int = 2
    print(i,j)
    print('i = ', i, 'j = ', j)
    print('i = {}, j = {}'.format(i,j))
    print('i = {1}, j = {0}'.format(j,i))   
    print(f'{i=}, {j=}')

def formatspezifikationen() -> None:
    print('\n Formatspezifikatoren:')
    print('-------------------')
    i:int = 7
    print('i = {:3d}'.format(i))   #3d für "three digits"
    print('i = {:03d}'.format(i)) 
    print(f'i = {i:03d}')
    print(f'{i=:03d}')

def raw_strings() -> None:
    print('\n Raw strings:')
    print('-------------------')
    file = 'Py02.py'
    print(f'C:\path\{file}')
    print(r'C:\path\{file}')
    print(fr'C:\\path\\{file}')

if __name__ == '__main__':
    ausgaben()
