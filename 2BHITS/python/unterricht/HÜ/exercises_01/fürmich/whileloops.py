def main() -> None:
    # aufgabe1()
    # aufgabe2()
    # aufgabe3()  
    # aufgabe4()
    # aufgabe5()
    # aufgabe6()
    # aufgabe7()
    # num1 = int(input("Enter first number: "))
    # num2 = int(input("Enter second number: "))
    # result = lcm(num1, num2)
    # print("The least common multiple of", num1, "and", num2, "is:", result)
    # gcd(2, 4)
    atm()

def aufgabe1() -> None:
    i = 0
    while i < 10:
        i += 1
        print(i)
    
def aufgabe2() -> None:
    num = 5
    i = 1
    fak = 1
    while i <= num:
        fak *= i
        i += 1
    print(fak)
    
def aufgabe3() -> None:
    terms = int(input("Geben Sie die Anzahl der Begriffe an, die Sie in der Fibonacci-Sequenz sehen möchten: "))
    # Initialisiere die ersten beiden Zahlen der Fibonacci-Sequenz
    a, b = 0, 1
    count = 0

    # Überprüfe, ob die Anzahl der Begriffe kleiner oder gleich 0 ist
    if terms <= 0:
        print("Bitte geben Sie eine positive Zahl ein.")
    # Wenn terms = 1, drucke nur das erste Element
    elif terms == 1:
        print("Fibonacci-Sequenz bis zu", terms, "Begriff:")
        print(a)
    # Sonst drucke die Fibonacci-Sequenz
    else:
        print("Fibonacci-Sequenz bis zu", terms, "Begriffe:")
        while count < terms:
            print(a, end=' ')
            # Aktualisiere die Werte von a und b, um die nächste Zahl zu generieren
            temp = a + b
            a = b
            b = temp
            count += 1

def aufgabe4() -> None:
    # summe in einer liste
    l = [1, 2]
    i = 0
    sum = 0
    while i < len(l):  # Korrigierte Bedingung: < anstelle von <= und len(l) anstelle von range(list)
        sum += l[i]  # Korrekte Zuweisung: += anstelle von =
        i += 1
    print("Die Summe der Elemente in der Liste beträgt:", sum)  # Ausgabe der Summe

def aufgabe5() -> None:
    max_value = 0
    i = 0
    liste = [36, 92, 124, 911, 918, 992]
    while i < len(liste):
        if max_value < liste[i]:
            max_value = liste[i]
        i += 1
    print(max_value)

def aufgabe6() -> None:
    # Selbstlaute zählen
    s = "selbstlaute woow"
    counter = 0
    for char in s:
        if char in "aeiou":
            counter += 1
    print("Anzahl der Selbstlaute:", counter)

def aufgabe7() -> None:
    i = 1
    fak = 1
    while i <= 10:
        fak *= i
        print(f"{i}:{fak}")
        i += 1

def gcd(x, y):
    # Euklidischer Algorithmus zur Berechnung des GCD
    while y != 0:
        x, y = y, x % y
    print(f"gcd: {x}")
    return x

def lcm(x, y):
    # Berechnung des LCM unter Verwendung des GCD
    return (x * y) // gcd(x, y)

def atm() -> None:
    balance = 0

    while True:
        print("\nATM Simulator")
        print("1. Check Balance")
        print("2. Deposit")
        print("3. Withdraw")
        print("4. Exit")
        
        choice = input("Enter your choice (1-4): ")

        if choice == '1':
            print("Your balance is:", balance)
        elif choice == '2':
            amount = float(input("Enter the amount to deposit: "))
            balance += amount
            print(f"{amount} deposited successfully.")
        elif choice == '3':
            amount = float(input("Enter the amount to withdraw: "))
            if amount > balance:
                print("Insufficient funds!")
            else:
                balance -= amount
                print(f"{amount} withdrawn successfully.")
        elif choice == '4':
            print("Thank you for using the ATM. Seas!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 4.")


if __name__ == "__main__":
    main()
