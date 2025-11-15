# Klassendiagramme
Ein Klassendiagramm ist ein bestimmtes Diagramm aus der Familie der UML-Diagramme (UnifiedModelingLanguage).

In einem Klassendiagramm lassen sich die Attribute und Methoden von Klassen darstellen. Dabei werden folgende Symbole für die Kapselung der Attribute oder Methoden verwendet.
- public wird mit + dargestellt
- private wird mit - dargestellt 
- protected wird mit # dargestellt

Weiters können in einem Klassendiagramm auch Abhängigkeiten zwischen Klassen modeliert werden.

Ein Klassendiagramm kann besonders einfach mit
z.B. https://mermaid.live/ erzeugt werden.

```mermaid
classDiagram
Dreieck <|-- Kreis
Dreieck <|-- Rechteck
Dreieck : +float Fläche
Dreieck : +float Umfang
Dreieck: +getFläche()
Dreieck: +getUmfang()
class Kreis{
    -float radius
    +setRadius()
    +getRadius()
}
class Rechteck{
    -float Breite
    -float Höhe
    +setBreite()
    +getBreite()
    +setHöhe()
    +getHöhe()
}

```

## Konzepte des objektorientierten Programmierens

- Abstraktion (abstraction)
<br>Klassen repräsentieren reale Dinge in abstrahierter Form.
- Kapselung (encapsulation)
<br>Zuweisung von public, protected und private an die Attribute und Methoden.
- Vererbung (inheritance)
<br> Die Kindklasse erbt alle Methoden und Attribute der Elternklasse.
- Polymorphismus (polymorphism)
<br>Durch Überschreiben von Methoden ergibt sich unterschiedliches Verhalten der Objekte.