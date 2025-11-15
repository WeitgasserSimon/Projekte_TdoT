'''
File:    Py17_oop.py
Author:
Date:   08.04.2024 
Brief:  OOP
Details:   Das objektorientierte Programmieren hat  seinen Ursprung 1967 in der Programmiersprache Simula.
         Die Grundpfeiler des OOP sind:
            - Abstraktion
            - Kapselung
            - Vererbung
            - Polymorphismus
Dabei werden reale Akteuere (Personen, Tiere, Planeten, etc. ) durch Abstraktion auf die wesentlichsten 
Eigenschaften und Methoden zu Objekten reduziert. In Python werden dazu Klassen erzeugt und durch 
Instanziierung der Klasse Objekte generiert.
'''

class Fahrzeug:
    Farbe:str = "rot" # Definition einer Klassenvariable

    # Konstruktor für die Klasse Fahrzeug
    def __init__(self, raeder:int) -> None:
        '''
        Konstruktor für die Klasse Fahrzeug
        Param raeder Die Anzahl der Räder
        '''
        self._Raeder = raeder # Definition einer öffentlichen/public Instanzvariable
        self._Sitzplaetze = 2 # Definition einer geschützten/protected Instanzvariable
        self.__Gewicht = 10 # Definition einer privaten/private Instanzvariable

    # Settermethode
    def setGewicht(self, gewicht:int) -> None:
        '''
        Diese Methode setzt das Gewicht des Fahrzeugs 
        param gewicht Das Gewicht in Kilogramm
        '''
        self.__Gewicht = gewicht

    # Gettermethode
    def getGewicht(self) -> int:
        '''
        Diese Methode liefert das Gewicht des Fahrzeugs
        return gewicht
        '''
        return self.__Gewicht
    
    # Python'sche Variante der Getter- und Settermethoden
    @property
    def Raeder(self) -> int:
        return self._Raeder
        
    @Raeder.setter
    def Raeder(self, raeder) -> None:
        self._Raeder = raeder

    # Magic method str eif 1 zu 1 wie es im code steht und wie es zrk gegeben wird
    def __str__(self) -> str:
        '''
        Gibt die String Repräsentation des Objekts zurück
        '''
        return f"Das Fahrzeug hat die Farbe {self.Farbe}, {self._Sitzplaetze} Sitzplätze und das Gewicht {self.__Gewicht}"

if __name__ == "__main__":
    Fahrzeug.Farbe = "pynk"
    print("Das Fahrzeug hat die Farbe", Fahrzeug.Farbe) # Verwendung der Klasse und deren Attribut namens "Farbe"

    # Erzeugen eines Objekts (Instanz) abgeleitet von der Klasse
    Fahrrad:Fahrzeug = Fahrzeug(2)
    Fahrrad.setGewicht(14)
    print("Das Fahrrad hat die Farbe", Fahrrad.Farbe)
    print(f"Das Fahrrad hat {Fahrrad._Raeder} Räder")
    print(Fahrrad)

    auto:Fahrzeug = Fahrzeug(4)
    auto.Raeder = 4
    auto.setGewicht(3500)
    print(auto)
