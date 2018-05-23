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


def remove(ndx):
	with open('Dados.txt', 'w') as f:
		f.seek(67,0)
		teste = 'alskdjflaskjdflkasj'
		f.write(teste)

def altera(ndx):
	print(ndx)

def compacta(ndx):
	print(ndx)


if __name__ == '__main__':
	ndx = leTabela()


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