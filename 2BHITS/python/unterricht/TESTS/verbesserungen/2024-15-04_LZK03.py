'''
File:    
Author:
Date:   15.04.2024 
Brief:  LZK 3

'''
class Monitor:
    # etwaige Klassenvariablen....

    #Attribut
    def __init__(self, hersteller) -> None:
        self._Hersteller:str = hersteller
        self._Farbe:str = ""

    @property
    def Farbe(self) -> str: # self ist die instanz/ das objekt
        return self._Farbe
    
    @Farbe.setter
    def Farbe(self, farbe:str) -> None:         # das hellblaue Farbe damit wird es aufgerufen
        self._Farbe = farbe
    
    def __str__(self) -> str:
        return f"{self._Farbe} {self._Hersteller} Monitor"

    def __repr__(self) -> str:
        return f"{id(self)}{self._Hersteller} Monitor, {self._Farbe}"

if __name__ == "__main__":
    monitor1 = Monitor("Lenovo")
    monitor1.Farbe = "schwarz"
    print(monitor1)
    


