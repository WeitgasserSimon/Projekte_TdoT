'''
File:    Py13_Listen_als_Arrays.py
Author:	 Weitgasser Simon
Date:
Brief:   Listen_als_Arrays
'''

def listen_als_arrays() -> None:
	erzeugen_einer_gemischten_liste()
	erzeugen_eines_mehrdimensionalen_arrays()
	aendern_der_werte_in_einem_mehrdimensionalen_array()

def erzeugen_einer_gemischten_liste() -> None:
	print('\nErzeugen einer gemischten Liste:')
	print('--------------------------------')
	mliste:list = []
	mliste.append([0,2,4])
	mliste.append([3,5])
	mliste.append([7,8])
	mliste.append([9,10,11,23])
	print(mliste)
	print(mliste[0][2]) # liefer 4
	print(mliste[2][1]) # liefert 8 nimm aus der liste mit index 2 das element mit index 1

def erzeugen_eines_mehrdimensionalen_arrays() -> None:
	print('\nErzeugen eines mehrdimensionalen Arrays:')
	print('----------------------------------------')
	nullen:list = [0, 0, 0, 0, 0]
	nullen:list = 5*[0]
	marray:list = []
	marray.append(nullen)
	marray.append(nullen)
	marray.append(nullen)
	marray[1][2] = 1	# es steht überall eien 1 weil es nur kopien sind und keine eigenständigene arrays
	print(marray)

	rows:int = 3
	cols:int = 5
	marray = rows*[cols*[0]]
	marray[1][2] = 1	# es steht überall eien 1 weil es nur kopien sind und keine eigenständigene arrays
	print(marray)

	rows:int = 3
	cols:int = 5
	marray = [[0 for col in range(cols)]for row in range(rows)] # !für multidimensionale array!
	marray[1][2] = 1
	print(marray)
	print("rows = ", len(marray)) # Anzahl der Zeilen
	print("cols = ", len(marray[0])) # Anzahl der Spalten


def aendern_der_werte_in_einem_mehrdimensionalen_array() -> None:
	print('\nÄndern der Werte in einem mehrdimensionalen Array:')
	print('--------------------------------------------------')


if __name__ == '__main__':
	listen_als_arrays()