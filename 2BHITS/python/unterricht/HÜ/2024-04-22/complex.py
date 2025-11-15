import math
import numpy

class MyComplex:
    """
    Eine Klasse zur Darstellung komplexer Zahlen und deren Operationen.
    """

    def __init__(self, real: float, imag: float, r=None, phi=None) -> None:
        """
        Initialisiert eine komplexe Zahl.

        Parameter:
        real (float): Der Realteil der komplexen Zahl.
        imag (float): Der Imaginärteil der komplexen Zahl.
        r (float, optional): Der Betrag der komplexen Zahl (automatisch berechnet, wenn nicht angegeben).
        phi (float, optional): Der Winkel (Argument) der komplexen Zahl in Radiant (automatisch berechnet, wenn nicht angegeben).
        """
        self._real: float = real
        self._imag: float = imag
        self._r: float = math.sqrt(real**2 + imag**2) if r is None else r
        self._phi: float = numpy.arctan2(imag, real) if phi is None else phi

    
    def __str__(self) -> str:
        """
        Gibt die komplexe Zahl als Zeichenkette in der Form "real + imagi" zurück.

        Rückgabewert:
        str: Die Zeichenkette, die die komplexe Zahl repräsentiert.
        """
        return f'{self._real} + {self._imag}i'

    def __add__(self, other) -> 'MyComplex':
        """
        Fügt zwei komplexe Zahlen zusammen.

        Parameter:
        other (MyComplex): Die andere komplexe Zahl.

        Rückgabewert:
        MyComplex: Die Summe der beiden komplexen Zahlen.
        """
        real = self._real + other._real
        imag = self._imag + other._imag
        return MyComplex(real, imag)

    def __sub__(self, other) -> 'MyComplex':
        """
        Subtrahiert eine komplexe Zahl von einer anderen.

        Parameter:
        other (MyComplex): Die zu subtrahierende komplexe Zahl.

        Rückgabewert:
        MyComplex: Die Differenz der beiden komplexen Zahlen.
        """
        real = self._real - other._real
        imag = self._imag - other._imag
        return MyComplex(real, imag)

    def __mul__(self, other) -> 'MyComplex':
        """
        Multipliziert zwei komplexe Zahlen.

        Parameter:
        other (MyComplex): Die andere komplexe Zahl.

        Rückgabewert:
        MyComplex: Das Produkt der beiden komplexen Zahlen.
        """
        real = self._real * other._real - self._imag * other._imag
        imag = self._real * other._imag + self._imag * other._real
        return MyComplex(real, imag)

    def __truediv__(self, other) -> 'MyComplex':
        """
        Dividiert eine komplexe Zahl durch eine andere.

        Parameter:
        other (MyComplex): Die zu teilende komplexe Zahl.

        Rückgabewert:
        MyComplex: Der Quotient der beiden komplexen Zahlen.
        """
        denominator = other._real**2 + other._imag**2
        real = (self._real * other._real + self._imag * other._imag) / denominator
        imag = (self._imag * other._real - self._real * other._imag) / denominator
        return MyComplex(real, imag)

    def asPair(self) -> tuple:
        """
        Gibt die komplexe Zahl als Zahlenpaar (a, b) zurück.

        Rückgabewert:
        tuple: Das Zahlenpaar (a, b), wobei a der Realteil und b der Imaginärteil der komplexen Zahl ist.
        """
        return (self._real, self._imag)

    def asVersor(self) -> str:
        """
        Gibt die komplexe Zahl als Versor r < phi in Stringform zurück.

        Rückgabewert:
        str: Die komplexe Zahl als Versor r < phi.
        """
        return f"{self._r} < {self._phi}"

    @property
    def Re(self) -> float:
        """
        Getter-Methode für den Realteil der komplexen Zahl.

        Rückgabewert:
        float: Der Realteil der komplexen Zahl.
        """
        return self._real

    @Re.setter
    def Re(self, real) -> None:
        """
        Setter-Methode für den Realteil der komplexen Zahl.

        Parameter:
        real (float): Der neue Wert für den Realteil.
        """
        self._real = real

    @property
    def Im(self) -> float:
        """
        Getter-Methode für den Imaginärteil der komplexen Zahl.

        Rückgabewert:
        float: Der Imaginärteil der komplexen Zahl.
        """
        return self._imag

    @Im.setter
    def Im(self, imag) -> None:
        """
        Setter-Methode für den Imaginärteil der komplexen Zahl.

        Parameter:
        imag (float): Der neue Wert für den Imaginärteil.
        """
        self._imag = imag

    @property
    def r(self) -> float:
        """
        Getter-Methode für den Betrag (Radius) der komplexen Zahl.

        Rückgabewert:
        float: Der Betrag (Radius) der komplexen Zahl.
        """
        return self._r

    @r.setter
    def r(self, r) -> None:
        """
        Setter-Methode für den Betrag (Radius) der komplexen Zahl.

        Parameter:
        r (float): Der neue Wert für den Betrag (Radius).
        """
        self._r = r

    @property
    def phi(self) -> float:
        """
        Getter-Methode für den Winkel (Argument) der komplexen Zahl.

        Rückgabewert:
        float: Der Winkel (Argument) der komplexen Zahl in Radiant.
        """
        return self._phi

    @phi.setter
    def phi(self, phi) -> None:
        """
        Setter-Methode für den Winkel (Argument) der komplexen Zahl.

        Parameter:
        phi (float): Der neue Wert für den Winkel (Argument) in Radiant.
        """
        self._phi = phi 


if __name__ == '__main__':
    z1 = MyComplex(2, 3)
    z2 = MyComplex(3, 4)
    print(f'{z1}, {z2}')
    print(f"z1 + z2: {z1 + z2}")
    print(f"z1 - z2: {z1 - z2}")
    print(f"z1 * z1: {z1 * z2}")
    print(f"z1 / z2: {z1 / z2}")
    print(f"r: {z1.r}")  # Hier wird die r-Eigenschaft der Instanz z1 aufgerufen
    print(f"phi: {z1.phi * 57.295779513} in grad")
    
    # Aufruf der Funktionen asPair und asVersor
    print(f"Z1 als Zahlenpaar: {z1.asPair()}")
    print(f"Z1 als Versor: {z1.asVersor()}")
