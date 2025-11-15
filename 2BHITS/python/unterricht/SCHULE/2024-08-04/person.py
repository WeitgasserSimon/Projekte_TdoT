class Person:
    # Attributes
    name: str = "Jamal"
    farbe: str = "weiß"
    alter: int = 25

    # Methods
    # Setter methods
    def setName(self, name: str) -> None:
        self.name = name
    
    def setFarbe(self, farbe: str) -> None:
        self.farbe = farbe

    def setAlter(self, alter: int) -> None:
        self.alter = alter

    # Getter methods
    def getName(self) -> str:
        return self.name
    
    def getFarbe(self) -> str:
        return self.farbe
    
    def getAlter(self) -> int:
        return self.alter

if __name__ == "__main__":
    # Creating an instance of the class
    person_instance = Person()
    
    # Calling the setName method
    person_instance.setName("Stradaf")
    
    # Getting and printing the name using the getName method
    print("Name:", person_instance.getName())

    # Setting the color using the setFarbe method
    person_instance.setFarbe("blau")
    
    # Getting and printing the color using the getFarbe method
    print("Farbe:", person_instance.getFarbe())

    # Setting the age using the setAlter method
    person_instance.setAlter(30)
    
    # Getting and printing the age using the getAlter method
    print("Alter:", person_instance.getAlter())

    
