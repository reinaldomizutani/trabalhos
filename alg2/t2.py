"""
Discentes: 
10295221 - Hugo Vitulli
10295217 - Matheus Vinicius Gouvêa de Godoi
7062145 - Reinaldo Mizutani
"""

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

def getInt(msg):
	nro = 'asdf'
	while(not isinstance(nro, int)):
		nro = input(msg)
		try:
			nro = int(nro)
		except Exception as e:
			pass
	return nro

def insere(ndx):
	with open('crash.txt', 'w') as crash:
		with open('Dados.txt', 'a') as f:
			with open('primario.ndx', 'a') as ndxFile:
				nro = getInt('digite o numero: ')
				if(nro not in ndx):

					nro = format(nro, "03d")
					
					nome = input('digite o nome: ')
					crash.write('$' + '\n' + '1' + '\n' + str(nro) + '|' + nome)
					veiculo = input('digite o veiculo: ')
					crash.write('|' + veiculo)
					linha = nro + '|' + nome.ljust(40,' ') + '|' + veiculo.ljust(20,' ') + '\n'
					f.write(linha)
					tempNdx = max(ndx.values()) + len(linha) + 1
					
					ndx[int(nro)] = tempNdx
					tempNdx = format(tempNdx, "05d")
					linhaNdx = nro + ' ' + tempNdx
					ndxFile.write(linhaNdx)
					crash.seek(0)
					crash.write('0')
					return ndx
				else:
					print('numero duplicado. ')

def remove(ndx):
	remover = getInt("digite o numero a ser removido: ")
	remover = int(remover)
	contLines = 0
	with open('Dados.txt', 'r+') as f:
		with open('primario.ndx', 'r+')as primario:
			if(remover in ndx):
				numero = ndx[remover]
				f.seek(numero) #numero é a posicao no "dados.txt"
				f.write('#')

				ndxFile = primario.readlines()
				for line in ndxFile:
					contLines += 1
					nro, pos = line.split()
					try:
						if(int(nro) == remover):
							primario.seek((contLines-1) * 11)
							primario.write('#')
							print("Remocao realizada com sucesso! ")
					except Exception as e:
						pass
					
				
				return ndx
				# FAZER DEPOIS!!!! ndx.pop(numero, None)
			else:
				print("remocao não realizada: numero nao consta no arquivo.")
				return ndx

def altera(ndx):
	with open('crash.txt', 'w') as crash:	
		nro = getInt('digite o numero da casa que voce quer alterar: ')
		if nro in ndx:
			opt = 0
			while(opt>3 or opt<1):
				print('qual dado você quer alterar:')
				print('1) numero ')
				print('2) nome')
				print('3) veiculo')
				opt = int(input('opcao: '))
				crash.write('$' + '\n' + '2' + '\n' + str(nro) + '|' + str(opt))

			value = input('digite o novo valor: ')
			crash.write('|' + value)

			if(opt == 1):
				if(int(value) in ndx):
					print("ERRO: Numero de registro duplicado! ")

			with open('dados.txt', 'r+') as dados:
				with open('primario.ndx', 'r+') as primario:
					posicao = ndx[nro]
					dados.seek(posicao)
					linha = dados.readline()
					nro, nome, veiculo = linha.split('|')
					novalinha = ''
					#ndxMem[int(nro)] = finalposition
					if(opt == 1):
						value = int(value)
						novalinha = str(format(value, '03d')) + '|' + nome + '|' + veiculo
						novoNdx = ndx[int(nro)]
						ndx[value] = novoNdx
						ndx.pop(int(nro), None)

					elif(opt == 2):
						novalinha = nro + '|' + value.ljust(40, ' ') + '|' + veiculo
					elif(opt == 3):
						novalinha = nro + '|' + nome + '|' + value.ljust(20, ' ')

					dados.seek(posicao)
					dados.write(novalinha)
			crash.seek(0)
			crash.write('0')
			return ndx
		else: 
			print("numero digitado não consta no banco de dados. ")
			return ndx
	
def compacta(ndx):
	newFile = []
	with open('dados.txt', 'r') as dados:
		dadosMem = dados.readlines()
		for line in dadosMem:
			try:
				nro, nome, veiculo = line.split('|')
				if(nro[0] == '#'):
					pass
				else:
					veiculo = veiculo.rstrip('\n')
					newLine = [nro, nome, veiculo]
					newFile.append(newLine)
			except Exception as e:
				pass
			
			
		
		newFile = sorted(newFile)
	
	with open("dados.txt", "w")as newDados:
		with open("primario.ndx", 'w') as primario:
			ndxMem = {}
			finalposition = 0
			for item in newFile:
				try:
					tempLine = item[0] + '|' + item[1] + '|' + item[2] + '\n'	
					primario.write(item[0] + ' ' + str(format(finalposition, '05d')) + '\n')
					ndxMem[int(nro)] = finalposition
					finalposition = finalposition + len(tempLine) + 1
					newDados.write(tempLine)
				except Exception as e:
					pass
				
				


	return ndx

def procura(ndx):
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

def recupCrash(tipo, dados, ndx):
	tipo = int(tipo)

	nro, nome = dados.split('|')
	nome = nome.rstrip('\n')
	print('recuperação de crash: ')
	print('novo dado: numero = ' + nro +', nome = '+ nome)
	veiculo = input("digite o veículo: ")
	
	with open('Dados.txt', 'a') as f:
		with open('primario.ndx', 'a') as ndxFile:
							
			linha = nro + '|' + nome.ljust(40,' ') + '|' + veiculo.ljust(20,' ') + '\n'
			f.write(linha)
			tempNdx = max(ndx.values()) + len(linha) + 1
			
			ndx[int(nro)] = tempNdx
			tempNdx = format(tempNdx, "05d")
			linhaNdx = nro + ' ' + tempNdx
			ndxFile.write(linhaNdx)

			return ndx



		

if __name__ == '__main__':

	ndx = leTabela()

	with open('crash.txt', 'r') as crash:
		error = crash.readline()
		tipo = crash.readline()
		dados = crash.readline()
		if(error == '$'+'\n' and dados != ''):
			recupCrash(tipo, dados, ndx)

	with open('crash.txt', 'w'):
		print('recuperacao efetivada com sucesso! ')



	option = 8 #numero arbitrario
	#os.system('CLS') #usar CLS do sistema operacional

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
