class Player:
    def __init__(self) -> None:
        self._time: float = 0.0
        self._speed: float = 0.0
        self._position: list[float] = [0.0, 0.0]
        self._color: str = ""
        self._size: float = ""

    def __str__(self) -> str:
        return f"Der Spieler ist {self._speed} m/s schnell"
    
    def move_x(self, t):
        self._position[0] += self._speed * t
        self._time += t

    def move_y(self, t):
        self._position[1] += self._speed * t
        self._time += t
    
    @property
    def position(self) -> list:
        return self._position
    @position.setter
    def position(self, p) -> None:
        self._position = p

    @property
    def speed(self) -> float:
        return self._speed * 3.6
    @speed.setter
    def speed(self, s) -> None:
        self._speed = s

    @property
    def color(self) -> str:
        return self._color 
    @color.setter
    def color(self, c) -> None:
        self._color = c

    @property
    def size(self) -> float:
        return self._size
    @size.setter
    def size(self, s) -> None:
        self._size = s

class blacky(Player):
    def __init__(self) -> None:
        super().__init__()
        self._color = "black"
        self._size = 202
        self._game: str = "csgoo"
    def __str__(self) -> str:
        return f"der blacky ist {self._size}cm groß und hat die farbe {self._color}"

    @property
    def game(self) -> str:
        return self._game
    @game.setter
    def game(self, g) -> None:
        self._game = g

if __name__ == "__main__":
    # p1 = Player()
    # p1.speed = 4
    # p1.color = "rot"  # Verwenden des Setters für die Farbe
    # p1.move_x(3)
    # print(p1._position)
    # print(f"{p1.speed} km/h oder {p1._speed} m/s")  # ohne _ wird die Getter-Methode AUFGERUFEN
    # p1.move_y(1)
    # print(p1._position)
    # print(p1)  # Aufruf der __str__-Methode
    # print(p1.color)  # Verwenden des Getters für die Farbe
    b1 = blacky()
    print(b1)
    print(b1.game)
    blacky.game = "fornät"
    print(b1.game)
    
