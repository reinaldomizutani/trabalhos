def leArquivo():
	with open('entrada.txt', 'r') as file:
		#linha 1: (int) estados
		estados = int(file.readline())

		#linha 2: (lista) terminais
		terminais = file.readline()
		terminais = terminais[2:]
		terminais = terminais.split()

		#linha 3: (lista) naoTerminais
		naoTerminais = file.readline()
		naoTerminais = naoTerminais[2:]
		naoTerminais = naoTerminais.split()

		#linha 4: (int) aceitacao
		aceitacao = int(file.readline())


		#linha 5: (int) numero de transicoes
		numTransicoes = int(file.readline())

		#linha 6 a (numTransicoes + 6): (matriz de listas) definição das arestas do grafo que representa a maquina de turing
		transicoes = []
		for linha in range(numTransicoes):
			temp = file.readline()
			temp = temp.split()
			transicoes.append(temp)

		#num cadeias a serem testadas: (int) numero de cadeias
		numCadeias = int(file.readline())

		#cadeias a serem testadas: (lista) lista com as cadeias a serem testadas
		cadeias = []
		for linha in range(numCadeias):
			temp = file.readline()
			cadeias.append(temp.rstrip('\n'))
	
		return estados, terminais, naoTerminais, aceitacao, transicoes, cadeias

def printaCoisas(estados, terminais, naoTerminais, aceitacao, transicoes, cadeias):

	print('estados = ')
	print(str(estados))
	print(' ')

	print('terminais : ')
	print(terminais)
	print(' ')

	print("não serminais (sigma'): ")
	print(naoTerminais)
	print(' ')

	print('aceitacao = ')
	print(str(aceitacao))
	print(' ')

	print('transicoes: ')
	print(transicoes)
	print(' ')

	print('cadeias :')
	print(cadeias)
	print(' ')

def preparaGrafo(estados, transicoes):
	graph = {}
	for x in range(estados):
		graph.setdefault(x,[])

	for item in transicoes:
		key = int(item[0])
		tempTransicoes = item[1:]
		graph[key].append(tempTransicoes)

	return graph

def testeCadeias(graph, posAtual, cadeia, estado):

	resultado = 0
	if 'a' not in cadeia and 'b' not in cadeia and 'c' not in cadeia and estado == 5:
		return 1

	else:
		for lista in graph[estado]:

			#se existe instrucao para o que esta na cabeca de leitura:
			if(cadeia[posAtual] in lista): 
				newEstado = int(lista[1])
				escrever = lista[2]
				movePara = lista[3]
			else:
				print("não achou na lista")
				continue
				
			newCadeia = cadeia[:posAtual] + escrever + cadeia[posAtual+1:]
			if(movePara == 'R'):
				newPosicao = posAtual + 1
			elif(movePara == 'L'):
				newPosicao = posAtual -1
			else:
				newPosicao = posAtual

			print("estado = " + str(estado))
			print('cadeia = ' + cadeia)
			print('posicao atual = ' + str(posAtual))
			print("move Para = " + movePara)
			print('nova cadeia = ' + newCadeia)
			print('novo estado = ' + str(newEstado))
			print('--------------')


			resultado = testeCadeias(graph, newPosicao, newCadeia, newEstado)
			
	

if __name__ == '__main__':

	# ----------------------- leitura e preparacao dos dados: ----------------
	estados, terminais, naoTerminais, aceitacao, transicoes, cadeias = leArquivo()

	#printaCoisas(estados, terminais, naoTerminais, aceitacao, transicoes, cadeias)

	graph = preparaGrafo(estados, transicoes)

	# ------------------------ começo do codigo em si ------------------------
	estado = 0
	posAtual = 1
	novaCadeia = ' ' + cadeias[0] + ' '
	#resultado = testeCadeias(graph, posAtual, novaCadeia, estado)
	"""
	for cadeia in cadeias:
		novaCadeia = ' ' + cadeia + ' '
		resultado = testeCadeias(graph, posAtual, novaCadeia, estado)
		if resultado == 1:
			print("DEU CERTO PORRA")
	"""

	teste = 'asdf'
	if 'a' in teste:
		print('teste')