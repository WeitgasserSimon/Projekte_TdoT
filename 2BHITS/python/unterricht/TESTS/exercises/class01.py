class Fahrzeug:
    def __init__(self) -> None:
        self._gewicht: float = 10.0
        self._farbe: str = "weiß"
    
    def __str__(self) -> str:
        return f"Das Fahrzeug wiegt {self._gewicht}kg und hat die Farbe {self._farbe}"

    @property
    def gewicht(self) -> float:
        return self._gewicht
    @gewicht.setter
    def gewicht(self, g) -> None:
        self._gewicht = g

    @property
    def farbe(self) -> str:
        return self._farbe
    @farbe.setter
    def farbe(self, f) -> None:
        self._farbe = f"{f}!"

class Kraftfahrzeug(Fahrzeug):
    def __init__(self) -> None:
        super().__init__()
        self._leistung: float = 60.0
        self._hubraum: float = 1.4
    
    def __str__(self) -> str:
        return f"Das Kraftfahrzeug hat {self._leistung}PS, {self._hubraum}l Hubraum, wiegt {self._gewicht}kg und hat die Farbe {self._farbe}"
    
    @property
    def leistung(self) -> float:
        return self._leistung
    @leistung.setter
    def leistung(self, l) -> float:
        self._leistung = l

    @property
    def hubraum(self) -> float:
        return self._hubraum
    @leistung.setter
    def hubraum(self, h) -> float:
        self._hubraum = h   
    

    
if __name__ == "__main__":
    f1 = Fahrzeug()
    print(f1)
    f1.farbe = "schwarz" # zugriff auf setter
    # f1._farbe = "schwarz" # direkter zugriff durch _
    print(f1)

    kfz1 = Kraftfahrzeug()
    kfz1.gewicht = 1655
    kfz1.leistung = 420
    kfz1.hubraum = 3.999
    kfz1.farbe = "black on black"
    print(kfz1)


