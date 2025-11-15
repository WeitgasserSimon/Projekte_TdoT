def main() -> None:
    my_dict = {"spiel": "fortnite", "farbe": "schwarz", "book": "buch"}

    # 1. Neues Wort hinzufügen
    my_dict["computer"] = "3090"

    # 2. Überprüfen, ob das Wort "book" im Wörterbuch enthalten ist
    is_book_present = "book" in my_dict
    print("Ist 'book' im Wörterbuch enthalten?", is_book_present)

    # 3. Anzahl der Einträge im Wörterbuch
    num_entries = len(my_dict)
    print("Anzahl der Einträge im Wörterbuch:", num_entries)

    # 4. Durchlaufen und Ausgabe aller Einträge
    print("Alle Einträge im Wörterbuch:")
    for eng_word, ger_word in my_dict.items():
        print(f"{eng_word}: {ger_word}")

if __name__ == "__main__":
    main()
