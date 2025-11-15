class Robot:
    def __init__(self):
        self._color = None
        self._size = None
        self._weight = None
        self._velocity = None
        self._duration = None

    # Getter und Setter für Farbe
    @property
    def getColor(self):
        return self._color

    @getColor.setter
    def setColor(self, color):
        colors = ['red', 'green', 'blue', 'yellow', 'white', 'black']
        if color.lower() in colors:
            self._color = color.lower()
        else:
            raise ValueError("Invalid color")

    # Getter und Setter für Größe
    @property
    def getSize(self):
        return self._size

    @getSize.setter
    def setSize(self, size):
        self._size = size * 2.54  # Umrechnung von Inch in cm

    # Getter und Setter für Gewicht
    @property
    def getWeight(self):
        return self._weight

    @getWeight.setter
    def setWeight(self, weight):
        self._weight = weight * 0.453592  # Umrechnung von Pfund in kg

    # Getter und Setter für Geschwindigkeit
    @property
    def getVelocity(self):
        return self._velocity

    @getVelocity.setter
    def setVelocity(self, velocity):
        self._velocity = velocity * 0.9144  # Umrechnung von Yards/s in m/s

    # Getter und Setter für Einsatzdauer
    @property
    def getDuration(self):
        return self._duration

    @getDuration.setter
    def setDuration(self, duration):
        self._duration = duration

    # Methode zum Abrufen von Gegenständen
    def getStuff(self, item):
        print(f"Getting {item}...")

    # Methode zum Ablegen von Gegenständen
    def putStuff(self, item):
        print(f"Putting {item}...")

    # Magic-Methode für die Darstellung
    def __str__(self):
        return f"Robot: Color={self._color}, Size={self._size}cm, Weight={self._weight}kg, Velocity={self._velocity}m/s, Duration={self._duration}min"


# Test des Roboters
if __name__ == "__main__":
    r = Robot()
    r.setColor = 'red'
    r.setSize = 61  
    r.setWeight = 50
    r.setVelocity = 0.5
    r.setDuration = 45
    print(r)
    r.getStuff('Hammer')
    r.putStuff('Werkzeugkoffer')
