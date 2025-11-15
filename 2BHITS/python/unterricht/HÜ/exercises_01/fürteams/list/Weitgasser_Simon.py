def main() -> None:
    # aufgabe1()
    # aufgabe2()
    # aufgabe3() 
    aufgabe4()
    aufgabe5()
    aufgabe6()
    aufgabe7()
    aufgabe8()
    aufgabe9()
    aufgabe10()

def aufgabe1() -> None:
    liste = []
    liste.append(*range(1,11))
    print(liste)

def aufgabe2() -> None:
    sum = 0
    liste = [1,2,3,4,5]
    for i in range(len(liste)):
        sum = liste[i] + sum
    print(f"summe: {sum}")

def aufgabe3() -> None:
    # max suche

    liste = [36,92,124,126,911,918,992]
    maxi = float("-inf")
    for i in range(len(liste)):
        if maxi < liste[i]:
            maxi = liste[i]
    print(f"max: {maxi}")

def aufgabe4() -> None:
    liste_d = [1,2,3,3,3,4,5,7,7,8,1,3,99]
    liste_wod = []
    for item in liste_d:
        if item not in liste_wod:
            liste_wod.append(item)
    print(f"liste ohne duplikate: {liste_wod}")

def aufgabe5() -> None:
    liste = [1, 2, 3, 3, 3, 4, 5, 7, 7, 8, 1, 3, 99]
    element = 3
    count = liste.count(element)
    print(f"Anzahl der Vorkommen von {element} in der Liste: {count}")

def aufgabe6() -> None:
    liste = [1, 2, 3]
    if not liste:
        print("Die Liste ist leer")
    else:
        print("Die Liste ist nicht leer")

def aufgabe7() -> None:
    liste = [1, 2, 3, 4, 5]
    reverse_list = liste[::-1]
    print(f"Umgekehrte Liste: {reverse_list}")

def aufgabe8() -> None:
    liste = [5, 2, 9, 1, 7, 6]
    sorted_list = sorted(liste)
    second_largest = sorted_list[-2]
    print(f"Der zweitgrößte Wert in der Liste ist: {second_largest}")

def aufgabe9() -> None:
    liste = [5, 2, 9, 1, 7, 6]
    sorted_list = sorted(liste)
    print(f"Aufsteigend sortierte Liste: {sorted_list}")

def aufgabe10() -> None:
    list1 = [1, 2, 3, 4, 5]
    list2 = [3, 4, 5, 6, 7]
    intersection = list(set(list1) & set(list2))
    print(f"Die Schnittmenge der beiden Listen ist: {intersection}")

if __name__ == "__main__":
    main()
