from collections import Counter

def main() -> None:
    # aufgabe1()  
    # aufgabe2()
    # aufgabe3()
    # aufgabe4()
    # aufgabe5()
    # aufgabe6()
    # aufgabe7()
    # remove_nth_character_demo()
    # aufgabe9()
    aufgabe10()

def aufgabe1() -> None:
    string = "The quick brown fox jumps over the lazy dog"
    prep_string = string.replace(" ", "") 
    buchstaben_zähler = Counter(prep_string)
    print(buchstaben_zähler)
    for buchstabe, anzahl in buchstaben_zähler.items():
        print(f"Anzahl von '{buchstabe}': {anzahl}")

def aufgabe2() -> None:
    text = "The quick brown fox jumps over the lazy dog"
    bereinigter_text = text.replace(" ", "")
    buchstaben_zähler = Counter(bereinigter_text)
    gesuchter_buchstabe = "a"
    if gesuchter_buchstabe in buchstaben_zähler:
        anzahl_von_buchstabe = buchstaben_zähler[gesuchter_buchstabe]
        print(f"Anzahl von '{gesuchter_buchstabe}': {anzahl_von_buchstabe}")
    else:
        print(f"Anzahl von '{gesuchter_buchstabe}': 0")

def aufgabe3() -> None:
    string = "canel"
    if len(string) >= 2:
        first_two = string[:2]
        last_two = string[-2:]
        print(first_two + last_two)
    else:
        print("")

def aufgabe4() -> None:
    s = "Ich bins der canel und jai ist mein lieblingsinder"
    if len(s) == 0:
        return s
    first_char = s[0]
    modified_chars = [first_char]  # Die erste Stelle wird automatisch hinzugefügt
    for char in s[1:]:
        if char == first_char:
            modified_chars.append('$')
        else:
            modified_chars.append(char)
    modified_string = ''.join(modified_chars)
    print("Modified string:", modified_string)

def aufgabe5() -> None:
    # Schreiben Sie eine Python-Funktion, die eine Liste von Wörtern erhält und die Länge des längsten Wortes zurückgibt
    liste = ["Jai", "ist", "mein", "Lieblingsinder"]
    
    l_word = liste[0]
    for word in liste:
        if len(word) > len(l_word):
            l_word = word
    
    print(f"Längstes Wort: {l_word}")

def aufgabe6() -> None:
    string:str = "Jai ist mein Lieblingsinder"
    string = string[::-1]
    print(string)

def aufgabe7() -> None:
    # palindrome check
    string = "waw waw"
    if string == string[::-1]:
        print("palindrome!")
    else:
        print("no palindrome!")

def remove_nth_character_demo() -> None:
    string_input = input("Enter a non-empty string: ")
    index_input = int(input("Enter the index of the character to remove: "))

    result = remove_nth_character(string_input, index_input)
    print("Result:", result)

def remove_nth_character(s: str, n: int) -> str:
    if not s or n < 0 or n >= len(s):
        return "Invalid input"

    return s[:n] + s[n+1:]

def aufgabe9() -> None:
    # Find and replace 'not...poor' with 'good' if 'poor' follows 'not'
    string = "The weather is that not poor today."
    index_not = string.find('not')
    index_poor = string.find('poor')

    if index_not != -1 and index_poor != -1 and index_not < index_poor:
        string = string[:index_not] + 'good' + string[index_poor + 4:]

    print("Result:", string)

def aufgabe10() -> None:
    # bei einem string: char, mit ungeradem index, entfernen
    string:str = "fortnite ist das beste spiel"
    new_string = ""
    for i in range(len(string)):
        if i % 2 == 0:
            new_string += string[i]
    print(new_string)



if __name__ == "__main__":
    main()
