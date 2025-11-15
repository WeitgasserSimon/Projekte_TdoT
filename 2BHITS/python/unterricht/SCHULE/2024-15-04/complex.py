import math
import numpy

class MyComplex:

    def __init__(self, real: float, imag: float, r=None, phi=None) -> None:
        self._real: float = real
        self._imag: float = imag
        self._r: float = math.sqrt(real**2 + imag**2)
        self._phi: float = numpy.arctan(imag/real)*2*math.pi

    def __str__(self) -> str:
        return f'{self._real} + {self._imag}i'

    def __add__(self, other) -> 'MyComplex':
        real = self._real + other._real
        imag = self._imag + other._imag
        return MyComplex(real, imag)

    def __sub__(self, other) -> 'MyComplex':
        real = self._real - other._real
        imag = self._imag - other._imag
        return MyComplex(real, imag)

    def __mul__(self, other) -> 'MyComplex':
        real = self._real * other._real - self._imag * other._imag
        imag = self._real * other._imag + self._imag * other._real
        return MyComplex(real, imag)

    def __truediv__(self, other) -> 'MyComplex':
        real = (self._real * other._real + self._imag * other._imag) / (other._real**2 + other._imag**2)
        imag = (self._imag * other._real - self._real * other._imag) / (other._real**2 + other._imag**2)
        return MyComplex(real, imag)

    @property
    def Re(self) -> float:
        return self._real

    @Re.setter
    def Re(self, real) -> None:
        self._real = real

    @property
    def Im(self) -> float:
        return self._imag

    @Im.setter
    def Im(self, imag) -> None:
        self._imag = imag

    @property
    def r(self) -> float:
        return self._r

    @r.setter
    def r(self, r) -> None:
        self._r = r

    @property
    def phi(self) -> float:
        return self._phi

    @phi.setter
    def phi(self, phi) -> None:
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
    print(f"phi: {z1.phi}")
	
