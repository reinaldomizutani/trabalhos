

if __name__ == '__main__':
	matriz = []

	with open('figura2.txt', 'r') as f:
		arquivo = f.readlines()
	
		for line in arquivo:
			temp = [int(n) for n in line.split()]
			matriz.append(temp)

	matriz.sort(reverse = True)
	
	linhas = len(matriz[0])
	colunas = linhas-1

	for line in matriz:
		print(line)

	for x in range(colunas):
		print(matriz[x][0])


