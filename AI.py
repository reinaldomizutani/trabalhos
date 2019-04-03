import pygame


def printaMuros(mapa):
	""" imprime os muros intransponíveis na tela """
	for item in mapa:
		pygame.draw.rect(win, (75,75,100),(20*item[1], 20*item[0], width, height))
	

if __name__ == '__main__':
	

	# -- entrada de dados -----------------------------------

	with open('in.txt', 'r') as f:
		entrada = f.readlines()
		
	dados = entrada[0].split()
	line1 = entrada[1]
	
	tamY = int(dados[0])
	tamX = int(dados[1])
	mapa = []

	#-- lendo a matriz e produzindo um mapa dos objetos -----

	for tempY in range(1,tamY):
		for tempX in range(tamX):
			if(entrada[tempY][tempX] == '-'):
				wall = [tempY-1,tempX]
				mapa.append(wall)

	#--------------------------------------------------------

	pygame.init()

	win = pygame.display.set_mode((20*tamX,20*tamY))

	pygame.display.set_caption("inteligencia artificial")

	x = 20
	y = 20

	width = 20
	height = 20
	vel = 5

	run = True
	while run:
		pygame.time.delay(50)

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				run = False

		keys = pygame.key.get_pressed()

		if keys[pygame.K_LEFT]:
			if(x <=0):
				x = x
			else:
				x = x - 20
		if keys[pygame.K_RIGHT]:
			if(x>=(20*tamX)-20):
				x = x
			else: 
				x = x + 20
		if keys[pygame.K_UP]:
			if(y <=0):
				y = y
			else:
				y = y - 20
		if keys[pygame.K_DOWN]:
			if(y>= (20*tamY)-20):
				y = y
			else:
				y = y + 20
		win.fill((200,200,200))
		pygame.draw.rect(win, (100,100,200),(x, y, width, height),5)
		printaMuros(mapa)
		pygame.display.update()

	pygame.quit()