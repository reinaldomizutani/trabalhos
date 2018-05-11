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
	linha = format(numero, '03d') + '|' + nome + '|' + carro + '\n'
	ndx['inserir'].append(linha)

	#mensagem de confirmacao ou erro
	if linha in ndx['inserir']:
		print('Insercao realizada com sucesso! ')

	return ndx

def remove(ndx):
	nro = int(input("digite o numero: "))
	
	if nro in ndx:
		ndx['remover'].append(nro)

		#mensagem de confirmacao ou erro
		if(nro in ndx['remover']):
			print('remocao realizada com sucesso!')
		else:
			print('erro na remocao')
	
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
	value = input('digite o novo valor: ')
	ndx['inserir'].append([opt, value])

	#mensagem de confirmacao ou erro
	if([opt, value] in ndx['inserir']):
		print('alteracao realizada com sucesso!')
	else:
		print('erro na alteracao do cadastro.')
	
	return ndx

def procura(ndx):
	numero = int(input('numero a ser buscado: '))
	
	if numero in ndx:
		print('usuario encontrado com sucesso!')
		with open('dados.txt', 'r') as f:
			dados = f.readlines()
			numero = format(numero, '03d')
			for line in dados:
				if(line[:3] == numero):
					nro, nome, carro = line.split('|')
					print('numero = ' + nro)
					print('nome = ' + nome)
					print('carro = '+ carro)
	print('\n')

def compacta(ndx):
	ndxMemory = {}
	dadosMemory = {}
	with open('dados.txt', 'r+') as dados:
		with open('primario.ndx', 'r+') as ndxFile:
			for line in ndxFile:
				key, value = line.split()
				ndxMemory[int(key)] = int(value)

			for line in dados:
				nro, nome, carro = line.split('|')
				carro = carro.rstrip()
				dadosMemory[int(nro)] = nome + ' ' + carro

			
			print('ndxMemory')
			print(ndxMemory)
			print('dadosMemory')
			print(dadosMemory)

			
			if(ndx['remover'] != []):
				for item in ndx['remover']:
					ndxMemory.pop(item, None)
					dadosMemory.pop(item, None)
				ndx['remover'] = []

			

			print('\n')
			print(item)
			print(ndxMemory)
			print(dadosMemory)
					

			return ndxMemory



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
			procura(ndx)
		elif(option == 5):
			ndx = compacta(ndx)
		elif(option == 6):
			salva(ndx)



	


