import os

def leTabelaInicial():
	with open('TabelaInicial.txt', 'r') as f:
		tabela = f.readlines()
		dados = {}

		for line in tabela:
			try:
				line = line[1:]
				line = line[:-2]

				a, b, c = line.split('|')
				a = a.replace('  ', '')
				b = b.replace('  ', '')
				c = c.replace('  ', '')

				if(b[-1] == ' '):
					b = b[:-1]

				if(c[-1] == ' '):
					c = c[:-1]

				dados[a] = [b]
				dados[a].append(c)
			except Exception as e:
				pass

			dados.pop('NRO', None)

		return dados

def saveDados(tabela):
	lista = []
	finalPosition = 0

	for key in tabela:
		lista.append([key, tabela[key][0], tabela[key][1]])

	lista = sorted(lista)
	ndxA = {}
	with open('primario.ndx', 'w') as ndx:
		with open('dados.txt', 'w') as dados:
			
			for item in lista:
				linha = item[0] + '|' + item[1] + '|' + item[2] + '\n'
				dados.write(linha)
				ndx.write(item[0] + ' ' + str(format(finalPosition, '05d')) + '\n')
				ndxA[int(item[0])] = finalPosition
				finalPosition += len(linha)
	return ndxA

def insere(ndx):
	
	numero = int(input('digite o numero: '))
	nome = input('digite o nome: ')
	carro = input('digite o carro: ')
	with open('primario.ndx', 'r+') as ndxFile:
		with open('dados.txt', 'a') as dados:
			#trabalhando dados 
			linha = format(numero, '03d')+'|'+nome+'|'+carro+'$'
			dados.write(linha)

			#trabalhando novo ndx
			newNdx = ndxFile.readlines() # carriage esta na ultima posicao do arquivo

			temp = newNdx[-1]
			a,b = temp.split()
			b = int(b)
			b = b + len(linha)
			ndxFile.write(format(numero, '03d') + ' ' + format(b, '05d'))


	return ndx

def remove(ndx):
	nro = int(input("digite o numero: "))
	print(ndx)
	if nro in ndx:
		ndx['remover'].append(nro)
		print(ndx)
	
	else:
		print('numero nao encontrado')
	
	return ndx

	

def altera(ndx):
	nro = int(input('digite o numero da cada que voce quer alterar: '))
	if nro in ndx:
		ndx['remover'].append(nro)

	print('qual dado você quer alterar:')
	print('1) numero ')
	print('2) nome')
	print('3) veiculo')
	opt = int(input('opcao: '))
	value = input('digite o novo valor')
	ndx['inserir'].append([opt, value])
	
	return ndx

def procura(ndx):
	print(ndx)

def compacta(ndx):
	print(ndx)


def salva(ndx):
	print(ndx)



if __name__ == '__main__':

	tabela = leTabelaInicial()
	ndx = saveDados(tabela)
	ndx['remover'] = []
	ndx['alterar'] = []
	ndx['inserir'] = []


	option = 8 #numero arbitrario

	os.system('CLS') #usar CLS do sistema operacional
	
	while(option != 6):
		print(ndx)
		print("-----------------------------")
		print("Registro entrada de veiculos:")
		print("-----------------------------")
		print("digite a opcao desejada:")
		print("  1) inserir")
		print("  2) remover")
		print("  3) alterar")
		print("  4) procurar")
		print("  5) compactar")
		print("  6) sair")

		option = int(input("Opção:"))

		if(option == 1):
			ndx = insere(ndx)
		elif(option == 2):
			ndx = remove(ndx)
		elif(option == 3):
			ndx = altera(ndx)
		elif(option == 4):
			ndx = procura(ndx)
		elif(option == 5):
			ndx = compacta(ndx)
		elif(option == 6):
			salva(ndx)



	


