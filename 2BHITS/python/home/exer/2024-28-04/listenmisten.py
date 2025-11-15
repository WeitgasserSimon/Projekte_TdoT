def liste() -> None:
    liste:list = [1, "zwei", 3.3, 4, 4]
    print(f"Liste: {liste}")

def menge() -> None:  
    menge: set = {1 , 2, 2, 3, 4, "fünf", 5.4}  
    print(f"Menge: {menge}")

def dictionary() -> None:
    dictionary: dict = {1: "eins", 2: "zwei", 3: "drei", 4: 3.3}
    print({f"Wörterbuch: {dictionary}"})

def tuple() -> None:
    t: tuple = (3, 3, 3, "drei")
    print(f"Tupel: {t}")



if __name__ == "__main__":
    liste()
    menge()
    dictionary()
    tuple()