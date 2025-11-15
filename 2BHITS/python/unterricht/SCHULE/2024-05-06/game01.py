import sys
import pygame

pygame.init()

# Farben definieren
black = (0, 0, 0)
red = (255, 0, 0)
blue = (0, 0, 255)
white = (255, 255, 255)

# Geschwindigkeit
speed = 0.1

# Bildschirmgröße
size = width, height = 480, 300
screen = pygame.display.set_mode(size)

# Rechteck 1 Eigenschaften (mit den Pfeiltasten steuerbar)
rect1_width = 20
rect1_height = 20
rect1_x = 100
rect1_y = 100


# Rechteck 2 Eigenschaften (mit den WASD-Tasten steuerbar)
rect2_width = 20
rect2_height = 20
rect2_x = 300
rect2_y = 100

# Rechteck 3 Eigenschaften (mit den WASD-Tasten steuerbar)
rect3_width = 20
rect3_height = 20
rect3_x = 300
rect3_y = 100



# Schleife für das Hauptprogramm
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False 

    # Hintergrund löschen
    screen.fill(black)

    # Rechteck 1 zeichnen (mit den Pfeiltasten steuerbar)
    rect1 = pygame.draw.rect(screen, blue, (rect1_x, rect1_y, rect1_width, rect1_height))

    # Rechteck 2 zeichnen (mit den WASD-Tasten steuerbar)
    rect2 = pygame.draw.rect(screen, red, (rect2_x, rect2_y, rect2_width, rect2_height))

    # Rechteck 3 zeichnen (mit den WASD-Tasten steuerbar)
    rect3 = pygame.draw.rect(screen, white, (rect3_x, rect3_y, rect3_width, rect3_height))
    
    # Tastaturabfrage für Rechteck 1 (Pfeiltasten)
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and rect1_x > 0:
        rect1_x -= speed
    if keys[pygame.K_RIGHT] and rect1_x < width - rect1_width:
        rect1_x += speed
    if keys[pygame.K_UP] and rect1_y > 0:
        rect1_y -= speed
    if keys[pygame.K_DOWN] and rect1_y < height - rect1_height:
        rect1_y += speed

    # Tastaturabfrage für Rechteck 2 (WASD-Tasten)
    if keys[pygame.K_a] and rect2_x > 0:
        rect2_x -= speed
    if keys[pygame.K_d] and rect2_x < width - rect2_width:
        rect2_x += speed
    if keys[pygame.K_w] and rect2_y > 0:
        rect2_y -= speed
    if keys[pygame.K_s] and rect2_y < height - rect2_height:
        rect2_y += speed


    # Bildschirm aktualisieren
    pygame.display.flip() 

pygame.quit()
sys.exit()
