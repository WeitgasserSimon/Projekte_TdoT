class robot:
    def __init__(self, akku, farbe) -> None:
        self._akku = akku
        self._farbe = farbe
    
    def __str__(self) -> str:
        return f"Der Roboter hat die Farbe {self._farbe} und den Akkustand {self._akku} %  "

class robot_household(robot):
    def __init__(self, akku, farbe) -> None:
        super().__init__(akku, farbe)
        self._duty = "cleaning"

class robot_industry(robot):
    def __init__(self, akku, farbe) -> None:
        super().__init__(akku, farbe)
        self._payload = 0 

class robot_outdoor(robot):
    def __init__(self, akku, farbe) -> None:
        super().__init__(akku, farbe)
        self._offroad = ""

if __name__ == '__main__':
    r = robot(75, "rot")
    print(r._akku)
    print(r)
