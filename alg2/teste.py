import os

def leTabela():
	with open("TabelaInicial.txt", 'r') as f:
		with open("Dados.txt", 'w') as dados:
			with open("primario.ndx", 'w') as ndx:

				tabela = f.readlines()
				arquivo = []
				for line in tabela:
					try:

						tempLine = line.rstrip('\n')
						tempLine = tempLine[1:-1]
						nro, nome, veiculo = tempLine.split('|')
						nro = nro.rstrip(' ')
						nome = nome.rstrip(' ')
						veiculo = veiculo.rstrip(' ')
						linha = nro + '|' + nome.ljust(40,' ') + '|' + veiculo.ljust(20,' ') + '\n'
						arquivo.append(linha)


					except Exception as e:
						pass
				arquivo.pop(0)
				arquivo = sorted(arquivo)

				#construindo primario.ndx
				ndxMem = {}
				finalposition = 0
				for linha in arquivo:
					dados.write(linha)
					nro, nome, veiculo = linha.split('|')
					ndx.write(nro + ' ' + str(format(finalposition, '05d')) + '\n')
					ndxMem[int(nro)] = finalposition
					finalposition = finalposition + len(linha) + 1

				return ndxMem

def insere(ndx):
	with open('Dados.txt', 'a') as f:
		with open('primario.ndx', 'a') as ndxFile:

			nro = int(input('digite o numero: '))
			nro = format(nro, "03d")
			
			nome = input('digite o nome: ')
			veiculo = input('digite o veiculo: ')
			linha = nro + '|' + nome.ljust(40,' ') + '|' + veiculo.ljust(20,' ') + '\n'
			f.write(linha)
			tempNdx = max(ndx.values()) + len(linha) + 1
			
			ndx[int(nro)] = tempNdx
			tempNdx = format(tempNdx, "05d")
			linhaNdx = nro + ' ' + tempNdx
			ndxFile.write(linhaNdx)
			print(ndx)
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
		
		print('qual dado você quer alterar:')
		print('1) numero ')
		print('2) nome')
		print('3) veiculo')
		opt = int(input('opcao: '))
		value = input('digite o novo valor: ')
		ndx['alterar'].append([nro,opt, value])

		#mensagem de confirmacao ou erro
		if([opt, value] in ndx['inserir']):
			print('alteracao realizada com sucesso!')
		else:
			print('erro na alteracao do cadastro.')
	
	return ndx

def procura(ndx):
	print(ndx)
	numero = int(input('numero a ser buscado: '))
	

	if numero in ndx:
		indice = ndx[numero]
		print('usuario encontrado com sucesso!')
		with open('dados.txt', 'r') as f:
			f.seek(indice,0)
			linha = f.readline()
			print(linha)
	else:
		print('Usuario nao encontrado...')
	print('\n')

def returnMax(ndx):
	maior = 0
	for item in ndx:
		if(isinstance(item,int)):
			pos = ndx[item]
			print(pos)
			if(maior < pos):
				maior = pos
		
		

	return maior

def compacta(ndx):



	ndxMemory = []
	dadosMemory = {}
	with open('dados.txt', 'a') as dados:
		for item in ndx['inserir']:######### RESOLVER ISSO AQUI
			dados.write(item)
			pos = returnMax(ndx)
			chave = int(ndx['inserir'][:3])
			ndx[chave] = pos
			ndx['inserir'].remove(item)

	with open('dados.txt', 'r+') as dados:
		with open('primario.ndx', 'r+') as ndxFile:

			for line in ndxFile:
				key, value = line.split()
				key = int(key)
				value = int(value)
				ndxMemory.append([key,value])

			for line in dados:
				nro, nome, carro = line.split('|')
				carro = carro.rstrip()
				dadosMemory[int(nro)] = nome + ' ' + carro

			
			'''
			for item in ndx['remover']:
				indice = ndx[item] + 67
				dados.seek(indice,0)
				proxLinhas = dados.readlines()
				dados.seek(ndx[item])
				dados.writelines(proxLinhas)
			'''

			#alterar dados!!
			for item in ndx['alterar']:
				nro = item[0]
				tipo = item[1]
				dado = item[2]

				indice = ndx[nro]
				dados.seek(indice,0)
				linha = dados.readline()
				oldNro, oldNome, oldCarro = linha.split('|')
				dados.seek(indice,0)
				if(tipo == 1):
					novaLinha = format(nro, "03d") + '|' + oldNome + '|' + oldCarro
				elif(tipo == 2):
					novaLinha = oldNro + '|' + dado.ljust(40,' ') + '|' + oldCarro
				else:
					novaLinha = oldNro + '|' + oldNome + '|' + dado.ljust(20, ' ')

				dados.write(novaLinha)
				ndx['alterar'].remove(item)

			print(ndx)	

			#adicionar dados:


			return ndx



def salva(ndx):
	print(ndx)



if __name__ == '__main__':

	ndx = leTabela()
	ndx['remover'] = []
	ndx['alterar'] = []
	ndx['inserir'] = []


	option = 8 #numero arbitrario

	os.system('CLS') #usar CLS do sistema operacional

	while(option != 6):
		
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
		print("  0) salva dados")

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
			print('done')
		elif(option == 0):
			salva(ndx)



	


