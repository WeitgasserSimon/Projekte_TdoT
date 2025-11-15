'''
File:   scopeAndVisibility.py
Author: Weitgasser Simon
Date:   2024-03-04
Brief:  übungen von der pdf

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
    x = int(input("Geben Sie eine Zahl ein: "))
    if x > 0:
        print(f"{x} ist positiv")
    elif x < 0:
        print(f"{x} ist negativ")
    else:
        print(f"{x} ist null")

def aufgabe2() -> None:
    x = int(input("Geben Sie Ihr Alter ein:"))
    if x < 18:
        print("you are a minor!")
    else:
        print("you are an adultcens")

def aufgabe3() -> None:
    x = int(input("Geben Sie bitte eine ungerade oder gerade Zahl ein:"))
    if x % 2 == 0: # gerade
        print(f"{x} is even")
    else:
        print(f"{x} is odd")

def aufgabe4() -> None:
    x = float(input("Gebe deine Note in Prozent [x.yz] an:"))
    if x >= 0.6:
        print("you passed! :)")
    else:
        print("you failed!")

def aufgabe5() -> None:
    x = int(input("Geben Sie Ihr Jahr ein"))
    if (x % 4 == 0 and x % 100 != 0) or (x % 400 == 0):
        print("Leap")
    else:
        print("not leap")
 
def aufgabe6() -> None:
    x = int(input("Geben Sie Ihre 1. Zahl ein: "))
    y = int(input("Geben Sie Ihre 2. Zahl ein: "))

    if x > y:
        print(x)
    if x < y:
        print(y)
    else:
        print("Beide gleich groß")

def aufgabe7() -> None:
    x = str(input("Please type in one char: "))
    if x == "a" or "e" or "i"or "o" or "u":
        print(f"{x} ist ein Vokal")
    else:
        print(f"{x} ist ein Konsonant")

def aufgabe8() -> None:
    x = int(input("Geben Sie Ihre 1. Zahl ein: "))
    y = int(input("Geben Sie Ihre 2. Zahl ein: "))
    z = int(input("Geben Sie Ihre 3. Zahl ein: "))
    if x > y:
        if x > z:
            print(f"x{x}")
        else:
            print(f"z{z}")
    else:
        if y > z:
            print(f"y{y}")
        else:
            print(f"z{z}")

def aufgabe9() -> None: 
    age = int(input("Ihr Alter [x] = "))
    staatsbürgerschaft = str(input("Haben Sie den österreichischen Pass? [y][n]"))
    if age >= 18 and staatsbürgerschaft == "y":
        print("Sie können wählen")
    else:
        print("Leider können Sie nicht wählen")

def aufgabe10() -> None:
    century = int(input("Geben Sie ein beliebiges Jahr ein"))
    if century % 100 == 0:
        print("CENTURYY")
    else:
        print("no century :(")

if __name__ == '__main__':
    main()
