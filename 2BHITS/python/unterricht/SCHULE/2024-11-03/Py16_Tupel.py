'''
File:    Py16_Tupel.py
Author:
Date:
Brief:   Tupel
'''

def tupel() -> None:
	erzeugen_eines_tupels()
	zugriff_auf_elemente()
	sind_elemente_enthalten()

def erzeugen_eines_tupels() -> None:
	print('\nErzeugen eines Tupels:')
	print('----------------------')
	paar:tuple = tuple()
	paar:tuple = (1, 2)
	paar[0] = 3
	print(paar, paar[0], paar[1])

def zugriff_auf_elemente() -> None:
	print('\nZugriff auf Elemente:')
	print('---------------------')


def sind_elemente_enthalten() -> None:
	print('\nSind Elemente enthalten:')
	print('------------------------')


if __name__ is '__main__':
	tupel()