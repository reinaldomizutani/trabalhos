# def é a definição de funções em python. Não precisa declarar void nem tipos de variáveis
def leTabelaInicial():

	#comando para abrir o arquivo. Assim como em C, 
	#e criado o "ponteiro" f.
	with open('TabelaInicial.txt', 'r') as f:

		#comando readlines -> le todo o arquivo (até o EOF) e joga na variavel tabela
		tabela = f.readlines()

		#criando um dicionário vazio(tabela hash)
		dados = {}

		#para todas as linhas na variavel tabela
		for line in tabela:
			try: 	# isso aqui é uma lindeza sem tamanho! try tenta fazer alguma 
					# coisa, se não der certo, ele faz a outra coisa. 
					# Parece bobeira, mas é um comando à prova de erros!

				# a tabela tem um "|" no começo. line recebe line[1] em diante
				line = line[1:]

				# os dois últimos caracteres da tabela são '|' e '\n'. remove ambos
				line = line[:-2]

				# quebra a linha em 3 variáveis (a, b, c), separando quando houver um '|'
				a, b, c = line.split('|') #por definição, .split() forma strings (no caso são 3)

				#a = nro, b = nome, c = carro

				#toda vez que tiver 2 espaços consecutivos ele substitui por "nada"
				a = a.replace('  ', '')
				b = b.replace('  ', '')
				c = c.replace('  ', '')

				#se o último caractere for um espaço, 
				if(b[-1] == ' '):
					#b recebe b até o penúltimo caractere
					b = b[:-1]
				#mesma coisa do if anterior
				if(c[-1] == ' '):
					c = c[:-1]

				# a hash table 'dados' recebe 'a' (que é o número do morador na tabela inicial)
				# só que os colchetes transformam a em uma lista -> [a]
				# obs: para fazer cast para lista em python é só colocar colchetes em volta da variavel
				dados[a] = [b]

				# append = push -> .append(c) insere 'c' na lista da hash table 'b'
				dados[a].append(c)

			# tratamento de excessoes: se der ruim em alguma linha, ele executa 
			# o bloco de código abaixo, no caso "pass", que significa "ignore"
			# obs: botado de proposito, pq vai ter varias linhas que não me 
			# interessam lá no arquivo 'TabelaInicial.txt'
			except Exception as e:
				pass

			dados.pop('NRO', None)

		#retorna a hash table 'dados'
		return dados


def saveDados(tabela):
	ndx = []
	with open('dados.txt', 'w') as dados:
		for key in tabela:
			dados.write(key + '|')
			temp = tabela[key]
			dados.write(temp[0] + '|' + temp[1])
			dados.write('\n')

def leDados():
	with open('dados.txt', 'r') as f:
		temp = f.readlines();
		return temp

# essa coisa esquisita é a Main de python... 
if __name__ == '__main__':

	#chamada da função leTabela()
	tabela = leTabelaInicial()

	saveDados(tabela)

	teste = leDados()
	
	print(teste)


	#printando pra ver se deu tudo certo
	