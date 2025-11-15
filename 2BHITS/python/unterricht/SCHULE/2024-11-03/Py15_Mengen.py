'''
File:    Py15_Mengen.py
Author:
Date:
Brief:   Mengen
'''

def mengen() -> None:
	erzeugen_einer_menge()
	befuellen_einer_menge()
	durchlaufen_einer_menge()
	zugriff_auf_elemente()
	sind_elemente_enthalten()

def erzeugen_einer_menge() -> None:
	print('\nErzeugen einer Menge:')
	print('---------------------')
	menge:set = set()
	print(menge)

def befuellen_einer_menge() -> None:
	print('\nBefüllen einer Menge:')
	print('---------------------')
	menge:set = set()
	menge.add(1)
	menge.add(2)
	menge.add(3)
	menge.add(4)
	menge.add(1)
	print(menge)

def durchlaufen_einer_menge() -> None:
	print('\nDurchlaufen einer Menge:')
	print('------------------------')
	menge:set = set()
	menge.add(1)
	menge.add(2)
	menge.add(3)
	menge.add(4)
	menge.add(1)
	for x in menge:
		print(x)

def zugriff_auf_elemente() -> None:
	print('\nZugriff auf Elemente einer Menge:')
	print('---------------------------------')

def sind_elemente_enthalten() -> None:
	print('\nSind Elemente enthalten:')
	print('------------------------')

if __name__  ==  '__main__':
	mengen()