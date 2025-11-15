class vector:
    def __init__(self, vx:int, vy:int) -> None:
        self._vx:int = vx
        self._v:int = vy

    def __str__(self) -> str:
        return f"({self._vx, {self._vy}})"
    
    def __add__(self, other) -> vector:
        return vector(self._vx+other._vx, self.vy+other.vy)
    
    def __mul__(self, other) -> int:
        return self._vx*other._vx + self._vy * other._vy
    
if __name__ == "__main__":
    v1 = vector(2, 3)
    v2 = vector(2, 1)
    print(f"v1 = {v1}")
    print(f"v1 = {v2}")
