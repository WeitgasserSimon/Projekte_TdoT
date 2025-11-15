class Planet:
    def __init__(self) -> None:
        self._radius: float = 0.0
        self._mass: float = 0.0
        self._name: str = "n/a"
        self._color: str = "n/a"
        self._xy: tuple[float, float] = (0.0, 0.0)
        self._speed: float = 0.0
        self._time: float = 0.0

    def move_x(self, time: float) -> None:
        self._xy = (self._xy[0] + self._speed * time, self._xy[1])
        self._time += time

    def move_y(self, time: float) -> None:
        self._xy = (self._xy[0], self._xy[1] + self._speed * time)
        self._time += time

    @property
    def radius(self) -> float:
        return self._radius

    @radius.setter
    def radius(self, radius: float) -> None:
        self._radius = radius

    @property
    def speed(self) -> float:
        return self._speed

    @speed.setter
    def speed(self, speed: float) -> None:
        self._speed = speed


if __name__ == "__main__":
    f = Planet()
    f.radius = 9.92
    f.speed = 5.5
    f.move_x(5)
    f.move_y(7)
    print(f"( {f._xy[0]} | {f._xy[1]} )")
    f.move_x(2)
    print(f"( {f._xy[0]} | {f._xy[1]} )")