'''
File: Hy01_.py
Author: Weitgasser Simon
Date: 2024-19-02
Brief: übungen der 1. seite vom arbeitsblatt auf teams
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
    a, b = '5', '3'
    a = int(a)
    b = int(b)
    print("a+b")

def aufgabe2() -> None:
    name = "lukas abi"
    print(f"Was geht {name}?")  	# f nd vergessen

def aufgabe3() -> None:
    x, y, z = 10, 20, 30
    x, y = y, x
    print(x, y, z)

def aufgabe4() -> None:
    radius = 31
    pi = 3.14159265358979323846
    print(radius * pi)

def aufgabe5() -> None:
    sentence = "ist es kalt, weil es nachts ist oder ist es nachts, weil es draußen kalt ist?"
    print(len(sentence))

def aufgabe6() -> None:
    numero1 = 31
    numero2 = 187
    numero1, numero2 = numero2, numero1
    print(numero1, numero2)

def aufgabe7() -> None:
    blowivonjai  = 50
    print(f"mit freundesrabatt gibt jai dir einen blowi für {blowivonjai*9/10}")

def aufgabe8() -> None:
    temp = 61
    print(f"{temp} grad celsius sind {temp*9/5+32} grad fahrenheit")

def aufgabe9() -> None:
    h = 187
    b = 61

    print(f"die fläche ihres dreiecks mit der basis {b} und der höhe {h} beträgt {h*b}")

def aufgabe10() -> None:
    age:int = 17.673721183910
    
    print(f"sham ist mit {age:03} schon echt alt")
    
if __name__ == '__main__' :
    main()