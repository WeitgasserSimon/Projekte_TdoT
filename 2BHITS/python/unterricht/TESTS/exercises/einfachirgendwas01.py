def liste() -> None:
    liste = [1, 2, 3, "vier"]
    # print(liste)
    i: int = 0
    for x in liste:
        print(liste[i])
        i += 1

class Fahrzeug:
    def __init__(self) -> None:
        self._gewicht: float = 0
    
    def __str__(self) -> str:
        return f"Das Fahrzeug wiegt {self._gewicht}"
    
class Kraftfahrzeug(Fahrzeug):
    def __init__(self) -> None:
        super().__init__()

 if __name__ =="__main__":
    liste()