def testeCadeias(graph, estadosIniciais, cadeias, aceitacao, terminais):

	#para todos os estados iniciais
	for estado in estadosIniciais:

		noAtual = estadosIniciais[0]-1

		#para cada letra da cadeia
		for letra in cadeia:
			if(letra not in terminais):
				return 0

			if(letra not in [item[1] for item in graph[noAtual]]):
				print("    rejeitado internamente")
				return 0

			for adj in graph[noAtual]:
				if(adj[1] == letra):
					noAtual = adj[0]

	
	if(noAtual in aceitacao):
		return 1
	else:
		return 0
		


if __name__ == '__main__':
	

	graph = {}
	transicoes = []
	cadeias = []
	with open('1.in', 'r') as f:
		#linha 1
		estados = f.readline()
		estados = int(estados)	

		#linha 2
		terminais = f.readline()
		terminais = terminais.split()		

		#linha 3
		estadosIniciais = f.readline()
		estadosIniciais = estadosIniciais.split()
		for item in estadosIniciais:
			a = int(item)
			estadosIniciais.remove(item)
			estadosIniciais.append(a)		

		#linha 4
		aceitacao = f.readline()
		aceitacao = [int(n) for n in aceitacao.split()]		

		#linha 5
		numeroTransicoes = f.readline()
		numeroTransicoes = int(numeroTransicoes)		

		for x in range(int(numeroTransicoes)):
			x = f.readline()
			transicoes.append(x.rstrip('\n'))

		# numero de cadeias
		numeroCadeias = int(f.readline())		

		# cadeias
		for x in range(numeroCadeias):
			x = f.readline()
			x = x.rstrip('\n')
			temp = list(x)
			cadeias.append(temp)

	estados = int(estados)
	for x in range(estados):
		graph.setdefault(x, [])	

	for item in transicoes:
		v, peso, w = item.split()
		v = int(v)
		w = int(w)
		temp = [w, peso]
		graph[v].append(temp)
	
	a = 1
	for cadeia in cadeias:
		result = testeCadeias(graph, estadosIniciais, cadeias, aceitacao, terminais)
		if(result == 1):
			print(str(a) + '. aceita')
		else:
			print(str(a) + '. rejeita')
		a +=1

