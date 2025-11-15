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
    # Leeres Wörterbuch erstellen und Schlüssel-Wert-Paare hinzufügen
    students = {}
    students["Alice"] = 85
    students["Bob"] = 90
    students["Charlie"] = 75
    print("Dictionary mit Schülern und Noten:", students)

def aufgabe2() -> None:
    # Über ein Wörterbuch iterieren und Schlüssel-Wert-Paare drucken
    students = {"Alice": 85, "Bob": 90, "Charlie": 75}
    for name, grade in students.items():
        print(f"Schüler: {name}, Note: {grade}")

def aufgabe3() -> None:
    # Überprüfen, ob ein Schlüssel in einem Wörterbuch vorhanden ist
    students = {"Alice": 85, "Bob": 90, "Charlie": 75}
    key_to_check = "Alice"
    if key_to_check in students:
        print(f"Der Schlüssel {key_to_check} existiert im Wörterbuch.")
    else:
        print(f"Der Schlüssel {key_to_check} existiert nicht im Wörterbuch.")

def aufgabe4() -> None:
    # Die Länge eines Wörterbuchs finden
    students = {"Alice": 85, "Bob": 90, "Charlie": 75}
    length = len(students)
    print(f"Die Länge des Wörterbuchs beträgt: {length}")

def aufgabe5() -> None:
    # Ein Schlüssel-Wert-Paar aus einem Wörterbuch entfernen
    students = {"Alice": 85, "Bob": 90, "Charlie": 75}
    key_to_remove = "Bob"
    if key_to_remove in students:
        del students[key_to_remove]
        print(f"Das Schlüssel-Wert-Paar {key_to_remove} wurde aus dem Wörterbuch entfernt.")
    else:
        print(f"Der Schlüssel {key_to_remove} existiert nicht im Wörterbuch.")

def aufgabe6() -> None:
    # Ein Wörterbuch nach seinen Schlüsseln sortieren
    students = {"Alice": 85, "Bob": 90, "Charlie": 75}
    sorted_students = dict(sorted(students.items()))
    print(f"Das sortierte Wörterbuch nach Schlüsseln: {sorted_students}")

def aufgabe7() -> None:
    # Ein Wörterbuch nach seinen Werten sortieren
    students = {"Alice": 85, "Bob": 90, "Charlie": 75}
    sorted_students = dict(sorted(students.items(), key=lambda item: item[1]))
    print(f"Das sortierte Wörterbuch nach Werten: {sorted_students}")

def aufgabe8() -> None:
    # Zwei Wörterbücher zusammenführen
    students1 = {"Alice": 85, "Bob": 90}
    students2 = {"Charlie": 75, "David": 88}
    merged_students = {**students1, **students2}
    print(f"Das zusammengeführte Wörterbuch: {merged_students}")

def aufgabe9() -> None:
    # Die höchsten 3 Werte in einem Wörterbuch finden
    students = {"Alice": 85, "Bob": 90, "Charlie": 75, "David": 88, "Eve": 92}
    sorted_students = sorted(students.items(), key=lambda item: item[1], reverse=True)
    highest_3 = sorted_students[:3]
    print(f"Die höchsten 3 Werte im Wörterbuch: {highest_3}")

def aufgabe10() -> None:
    # Die Häufigkeit jedes Zeichens in einem gegebenen String zählen und die Ergebnisse in einem Wörterbuch speichern
    string = "hello"
    frequency = {}
    for char in string:
        if char in frequency:
            frequency[char] += 1
        else:
            frequency[char] = 1
    print(f"Die Häufigkeit jedes Zeichens im String: {frequency}")

if __name__ == "__main__":
    main()
