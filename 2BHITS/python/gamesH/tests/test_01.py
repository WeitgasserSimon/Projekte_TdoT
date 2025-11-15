import pygame
import sys

# Initialisierung von Pygame
pygame.init()

# Definiere die Farben
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)

# Definiere die Bildschirmgröße
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Definiere die Größe des Quadrats
SQUARE_SIZE = 50

# Erstelle ein Fenster
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Bewegliches Quadrat")

# Definiere die Startposition des Quadrats
square_x = (SCREEN_WIDTH - SQUARE_SIZE) // 2
square_y = (SCREEN_HEIGHT - SQUARE_SIZE) // 2

# Bewegungsgeschwindigkeit des Quadrats
speed = 0.4
# Schleife für das Hauptprogramm
running = True
while running:
    # Überprüfe Ereignisse
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Überprüfe Tastatureingaben
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
        square_y -= speed
    if keys[pygame.K_s]:
        square_y += speed
    if keys[pygame.K_a]:
        square_x -= speed
    if keys[pygame.K_d]:
        square_x += speed

    # Begrenze die Position des Quadrats innerhalb des Bildschirms
    square_x = max(0, min(square_x, SCREEN_WIDTH - SQUARE_SIZE))
    square_y = max(0, min(square_y, SCREEN_HEIGHT - SQUARE_SIZE))

    # Fülle den Bildschirm mit Weiß
    screen.fill(WHITE)

    # Zeichne das Quadrat
    pygame.draw.rect(screen, RED, (square_x, square_y, SQUARE_SIZE, SQUARE_SIZE))

    # Aktualisiere den Bildschirm
    pygame.display.flip()

# Beende Pygame
pygame.quit()
sys.exit()
