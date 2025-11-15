'''
brief Vererbung

'''
class fahrzeug: 
    def __init__(self) -> None:
        self._Gewicht:float = 0.0
        self._Geschwindigkeit = 0.0
        self._Position = 0.0
        self._Zeit = 0.0

    def __str__(self) -> str:
        return f"Das Fahrzeug hat ein Gewicht von {self._Gewicht}"
    
    def fahre(self, zeit:float) -> None:
        self._Position = self._Geschwindigkeit * zeit
        self._Zeit += zeit

    @property
    def Gewicht(self) -> float:
        return fahrzeug._Gewicht

    @Gewicht.setter
    def Gewicht(self, gewicht:float):
        self._Gewicht = gewicht

class auto(fahrzeug):   # in der klammer == klasse von der geerbt wird

    def __init__(self) -> None:
        super().__init__()
        self._Personen = 0

    def __str__(self) -> str:
        return f"Das Auto hat ein Gewicht von {self._Gewicht}"
    
    @property

    def Personen(self) -> int:
        return self._Personen
    
    @Personen.setter
    def Personen(self, personen:int) -> None:
        self._Personen = personen 

class flugzeug(fahrzeug):
    
    def __init__(self) -> None:
        fahrzeug.__init__()
        self._Passagiere:int = 0


if __name__ == "__main__":
    f = fahrzeug()
    f.Gewicht = 1000
    a = auto()
    a.Gewicht = 2500
    a.Personen = 1
    p = flugzeug()
    
