'''
File:    Py14_Dictionaries.py
Author:
Date:
Brief:   Dictionaries (Wörterbuch)
{
	"A":65,
	"B":66,
	97:"a"
}
'''

def dictionaries() -> None:
	erzeugen_eines_dictionaries()
	befuellen_eines_dictionaries()
	durchlaufen_eines_dictionaries()
	sortieren_eines_dictionaries()
	zugriff_auf_elemente()
	sind_elemente_enthalten()

def erzeugen_eines_dictionaries() -> None:
	print('\nErzeugen eines Dictionaries:')
	print('----------------------------')
	wb:dict = dict()
	wb:dict = {}
	wb:dict = { "A":65, "B":66, "C":67}

def befuellen_eines_dictionaries() -> None:
	print('\nBefüllen eines Dictionaries:')
	print('----------------------------')
	wb:dict = {}
	wb["A"] = 65
	wb["A"] = 66
	wb["A"] = [ 65 ]
	wb["A"].append(66)
	wb[(2, 3)] = "red"
	print(wb)

def durchlaufen_eines_dictionaries() -> None:
	print('\nDurchlaufen eines Dictionaries:')
	print('-------------------------------')
	wb:dict = { "A":65, "B":66, "C":67 }
	for key in wb:
		print(f"{key} => {wb[key]}")
	for key, value in wb.items():
		print(f"{key} => {value}")
	for key in wb.keys():
		print(key)
	for value in wb.values():
		print(value)

def sortieren_eines_dictionaries() -> None:
	print('\nSortieren eines Dictionaries:')
	print('-----------------------------')
	wb:dict = { "A":ord("A"), "Z":ord("Z"), "H":ord("H")}
	wb_sorted = sorted(wb, reverse=False)
	print(wb_sorted)

def zugriff_auf_elemente() -> None:
	print('\nZugriff auf Elemente:')
	print('---------------------')
	wb:dict = { "A":ord("A"), "Z":ord("Z"), "H":ord("H")}
	print(wb["A"])
	print(wb.get("D", []))


def sind_elemente_enthalten() -> None:
	print('\nSind Elemente enthalten:')
	print('------------------------')
	wb:dict = { "A":ord("A"), "Z":ord("Z"), "H":ord("H")}
	if "A" in wb:
		print("A ist im wb enthalten")

if __name__ == '__main__':
	dictionaries()