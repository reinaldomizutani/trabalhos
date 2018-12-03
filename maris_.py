
def calcCusto(visitados, matriz):
	temp = 0
	for item in range(len(matriz[0])):
		temp = temp + matriz[visitados[item]][item]
	return temp


#--------------------------------------------------------
# 1. PREPARANDO OS DADOS
# A entrada é um arquivo com uma matriz triangular (parte inferior).
# Esse trecho de código trata os dados para que eles sejam efetivamente
# uma matriz N x N
#--------------------------------------------------------
if __name__ == '__main__':
		
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
	# Transformando matriz triangular em matriz completa:
	#--------------------------------------------------------
	x = 0
	y = 1
	while(x<lines):
		y = y + x
		while(y < lines):
			matriz[x].append(matriz[y][x])
			y += 1
		x += 1
		y = 1

	#--------------------------------------------------------
	# Inserção: Heuristica "inserção mais barata"
	#--------------------------------------------------------


	#recebendo nó inicial, por onde iniciarão as inserções
	index = int(input('digite o nó inicial (valores entre 0 e ' + str(lines) + '):'))

	visitados = []
	visitados.append(index)
	custo = []

	while(len(visitados) < lines):
		small = 10000
		tempY = 0
		for x in range(len(matriz[index])):
			if(matriz[index][x] < small and matriz[index][x] != 0 and x not in visitados):
				small = matriz[index][x]
				tempY = x
		
		visitados.append(tempY)
		custo.append(matriz[index][tempY])
		index = tempY

	visitados.append(visitados[0])
	custo.append(matriz[visitados[0]][visitados[-2]])


	#--------------------------------------------------------
	# melhorando a solução:
	#--------------------------------------------------------
	benchCusto = calcCusto(visitados,matriz)

	tempVisitados = []
	listaMelhores = []
	for item in visitados:
		tempVisitados.append(item)

	for item in range(len(tempVisitados)):
		if(item<len(tempVisitados)-1):
			temp = tempVisitados[item]
			tempVisitados[item] = tempVisitados[item+1]
			tempVisitados[item + 1] = temp
		else:
			temp = tempVisitados[-1]
			tempVisitados[-1] = tempVisitados[0]

		custoAtual = calcCusto(tempVisitados,matriz)



		if(custoAtual < benchCusto):
			listaMelhores.append([custoAtual, tempVisitados])
	
	custo = calcCusto(visitados, matriz)
	with open('saida.txt', 'w') as saida:
		saida.write('1. solução inicial após a inserção por "inserção mais barata"' + '\n')
		saida.write('custo = ' + str(custo) + '\n')
		saida.write('ordem = ' + str(visitados) + '\n\n')
		saida.write('2. Melhor solucao encontrada após 2-opt' + '\n')
		saida.write('custo = ' + str(min(listaMelhores)[0]) + '\n')
		saida.write('ordem = ' + str(min(listaMelhores)[1]) + '\n\n')
		saida.write('3. Todas as soluções encontradas:' + '\n')

		for item in listaMelhores:
			saida.write('custo = ' + str(item[0]) + '\n' + 'ordem = ' + str(item[1]) + '\n\n')


	print('primeira solução encontrada = ' + '\n' + str(visitados))
	print('custo = ' + str(custo))
	print('melhor custo encontrado = '  + str(min(listaMelhores)[0]))
	