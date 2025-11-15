import pygame
import sys
import random

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

# Definiere die Geschwindigkeit der Balken
BAR_SPEED = 5

# Erstelle ein Fenster
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Dodge the Bars")

clock = pygame.time.Clock()

# Definiere die Startposition des Quadrats
square_x = (SCREEN_WIDTH - SQUARE_SIZE) // 2
square_y = SCREEN_HEIGHT - SQUARE_SIZE - 50  # untere Position

# Definiere die Anfangsposition des ersten Balkens
bar_x = SCREEN_WIDTH
bar_width = 20
bar_height = 400
bar_gap = 5
bar_y = random.randint(0, SCREEN_HEIGHT - bar_height)

# Spielzustand
game_over = False

def show_menu():
    menu_font = pygame.font.Font(None, 36)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    return

        screen.fill(WHITE)
        menu_text = menu_font.render("Press ENTER to start", True, BLACK)
        menu_rect = menu_text.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2))
        screen.blit(menu_text, menu_rect)

        pygame.display.flip()
        clock.tick(60)

def main():
    global game_over

    while True:
        show_menu()

        # Spielzustand zurücksetzen
        game_over = False

        # Schleife für das Hauptprogramm
        while not game_over:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    game_over = True

            keys = pygame.key.get_pressed()
            if keys[pygame.K_w]:
                square_y -= 5
            if keys[pygame.K_s]:
                square_y += 5
            if keys[pygame.K_a]:
                square_x -= 5
            if keys[pygame.K_d]:
                square_x += 5

            # Begrenze die Position des Quadrats innerhalb des Bildschirms
            square_x = max(0, min(square_x, SCREEN_WIDTH - SQUARE_SIZE))
            square_y = max(0, min(square_y, SCREEN_HEIGHT - SQUARE_SIZE))

            # Bewege den Balken von rechts nach links
            bar_x -= BAR_SPEED

            # Überprüfe Kollision
            square_rect = pygame.Rect(square_x, square_y, SQUARE_SIZE, SQUARE_SIZE)
            bar_rect = pygame.Rect(bar_x, bar_y, bar_width, bar_height)

            if square_rect.colliderect(bar_rect):
                game_over = True

            # Fülle den Bildschirm mit Weiß
            screen.fill(WHITE)

            # Zeichne das Quadrat
            pygame.draw.rect(screen, RED, (square_x, square_y, SQUARE_SIZE, SQUARE_SIZE))

            # Zeichne den Balken
            pygame.draw.rect(screen, BLACK, (bar_x, bar_y, bar_width, bar_height))

            # Überprüfe, ob der Balken den Bildschirm verlassen hat und erzeuge einen neuen Balken
            if bar_x + bar_width < 0:
                bar_x = SCREEN_WIDTH
                bar_y = random.randint(0, SCREEN_HEIGHT - bar_height)

            # Aktualisiere den Bildschirm
            pygame.display.flip()

            # Begrenze die Aktualisierungsrate auf 120 FPS
            clock.tick(120)

        # Game Over Anzeige
        while game_over:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    game_over = False

            screen.fill(WHITE)
            font = pygame.font.Font(None, 36)
            text = font.render("Game Over", 1, BLACK)
            textpos = text.get_rect(centerx=screen.get_width() / 2, centery=screen.get_height() / 2)
            screen.blit(text, textpos)
            pygame.display.flip()
            clock.tick(60)

if __name__ == "__main__":
    main()
