import sys, pygame
pygame.init()

black = 0, 0, 0
speed = [8, 8]

ball = pygame.image.load("./unterricht/SCHULE/2024-04-29/ball.gif")
ballrect = ball.get_rect()
size = width, height = 1920, 1080
screen = pygame.display.set_mode(size)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()
    ballrect = ballrect.move(speed)
    if ballrect.left < 0 or ballrect.right > width:
        speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > height:
        speed[1] = -speed[1]

    screen.fill(black)
    screen.blit(ball, ballrect)

    pygame.display.flip()