'''
File: Py01_Variablen.py
Author: Weitgasser Simon
Date: 2024-19-02
Brief: Variablen und Datentypen
'''

def main() -> None:
    aufgabe1()
    aufgabe2()
    aufgabe3()
    aufgabe4()
    aufgabe5()
    aufgabe6()
    aufgabe7()
    aufgabe8()
    aufgabe9()
    aufgabe10()
    
def aufgabe1() -> None:
    a, b = '5', '3'  # Achtung: Wir benutzen Strings, da wir diese in Ganzzahlen umwandeln wollen
    a = int(a)
    b = int(b)
    print("a + b")

def aufgabe2() -> None:
    name = 'Lukas abi'
    print(f'Was geht {name}?')

def aufgabe3() -> None:
    x,y,z = '10', '20', '30'
    x, y = y, x
    print(x,y,z)

def aufgabe4() -> None:
    radius = 1234567
    pi = 3.14159265358979323846
    print(radius*pi)

def aufgabe5() -> None:
    sentence = 'Mujkic x Ammar'
    print(len(sentence))

def aufgabe6() -> None:
    a = 'LS'
    b = 'LW'
    a, b = b, a 
    print(a, b)

def aufgabe7() -> None:
    preisfürblowivonjai = 20
    print(f'Jai gibt blowi für {preisfürblowivonjai*0.9}')

def aufgabe8() -> None:
    temperatur = 22
    print(f'temperatur = {temperatur*1.8+32}')

def aufgabe9() -> None:
    base = 34
    h = 6.9
    print(f'{base*h}')

def aufgabe10() -> None:
    age = 17
    print(f"sham ist mit {age} schon echt alt")



if __name__ == '__main__':
    main()
