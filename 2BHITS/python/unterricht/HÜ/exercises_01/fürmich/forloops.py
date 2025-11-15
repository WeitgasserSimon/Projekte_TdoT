def main() -> None:
    # aufgabe1()
    # aufgabe2()
    # fibonacci()  
    # print_primes()
    # aufgabe5()
    # aufgabe6()
    # aufgabe7()
    # aufgabe8()
    # aufgabe9()
    aufgabe10()

def aufgabe1() -> None:
    # 1 bis 10 ausgeben
    for i in range(1, 11):
        print(i)

def aufgabe2() -> None:
    zahl = 102
    fak = 1
    for i in range(1, zahl + 1): 
        fak = i * fak
    print(fak)

def fibonacci():
    limit = 200
    fib_sequence = [0, 1]
    while fib_sequence[-1] + fib_sequence[-2] <= limit:
        fib_sequence.append(fib_sequence[-1] + fib_sequence[-2])
    print(fib_sequence)  # Print the sequence before returning
    return fib_sequence

def is_prime(n):
    """Check if a number is prime."""
    if n <= 1:
        return False
    elif n <= 3:
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def print_primes():
    """Print prime numbers from 1 to 100."""
    for num in range(1, 101):
        if is_prime(num):
            print(num)

def aufgabe5() -> None:
    liste:list = [1,2,4,8]
    sum:int = 0
    for i in range(len(liste)):
        sum = sum + liste[i]

    print(sum)

def aufgabe6() -> None:
    # max suche
    max:int = float('-inf')
    liste:list = [-31313123123,1,2,4,8,16,32]
    for i in range(len(liste)):
        if max < liste[i]:
            max = liste[i]
    print(max)

def aufgabe7() -> None:
    # Selbstlaute zähler für einen string
    s:str = "fortnite ist supi"
    counter:int = 0
    for char in s:
        if char in "aeiou":
            counter += 1
    print(counter)

def aufgabe8() -> None:
    for num in range(1, 11):
        fak = 1
        for j in range(1, num + 1):
            fak *= j
        print(f"{num}: {fak}")

def aufgabe9() -> None:
    d:dict = {"Name": "jai", "Alter": "alt", "Lowkicks": "gottlos"}

    for key, value in d.items():
        print(f"{key}: {value}")

def aufgabe10() -> None:
    number = 9139013193
    print(f"Multiplication table for {number}:")
    for i in range(1, 11):
        print(f"{number} x {i} = {number * i}")

if __name__ == "__main__":
    main()
