#--------------------------------------------------------
# 1. PREPARANDO OS DADOS
# A entrada é um arquivo com uma matriz triangular (parte inferior).
# Esse trecho de código trata os dados para que eles sejam efetivamente
# uma matriz N x N
#--------------------------------------------------------

with open ('biblio.txt', 'r') as entrada:
	lines = entrada.readline()
	lines = int(lines)
	preDados = entrada.readlines()

dados = []

for line in preDados:
	line = line.strip()
	line = line.replace('   ', '  ')
	line = line.replace('  ', ' ')
	line = line.replace(' ', ',')
	line = line.split(',')
	for item in line:
		dados.append(int(item))

matriz = [[]]
subitem = []

for item in dados:
	if(item != 0):
		subitem.append(item)
	else:
		subitem.append(item)
		matriz.append(subitem)
		subitem = []

matriz.remove([])


#--------------------------------------------------------
# Inserção: Heuristica "inserção mais barata"
#--------------------------------------------------------
index = 1
visitados = []
custo = []
distancia = 1

while(len(visitados) < lines):
	for item in matriz[index]:
		print(item)
		visitados.append(1)






#--------------------------------------------------------

'''

x = 0
y = 1

while(x<lines):
	y = y + x
	while(y < lines):
		matriz[x].append(matriz[y][x])
		y += 1
	x += 1
	y = 1

for item in matriz:
	print(item)
'''