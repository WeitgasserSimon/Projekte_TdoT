'''
File:   Py04_Sichtbarkeit.py
Author: Weitgasser Simon
Date:   2024-02-26
Brief:  Variablensichtbarkeit (scope), lokale und globale Variablen
'''

def sichtbarkeit() -> None:
	lokale_variablen()
	globale_variablen_ausgeben()
	globale_variablen_aendern()
	globale_variablen_ausgeben()

g1:int = 1
g2:int = 2

def lokale_variablen() -> None:
	print('\nLokale Variablen 1:')
	print('-----------------')
	g1 = 3
	print(f'{g1=}, {g2=}')

def globale_variablen_ausgeben() -> None:
	print('\nGlobale Variablen 2:')
	print('-----------------')
	print(f'{g1=}, {g2=}')

def globale_variablen_aendern() -> None:
	print('\nGlobale Variablen:')
	print('-----------------')
	global g1, g2
	g1 = 5
	g2 = 4
	print(f'{g1=}, {g2=}')

if __name__ == '__main__':
	sichtbarkeit()
