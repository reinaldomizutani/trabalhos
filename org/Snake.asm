; 	Fernanda Maciel Federici 		- 10295093	
;	Reinaldo Mizutani				- 7062145
;	Rodrigo Luiz Pereira dos Santos - 10262461
;main:
;	
;	1. inicio - inicialização dos valores nas variáveis. 
;		Também imprime uma tela de inicialização bonitinha
;	2. desenhaBordas - desenha as bordas da fase
;	
;	Gameloop
;	3. desenhaSnake - imprime snake e food
;		- usa o vetor vetSnake e a variavel posfood pra printar tanto a snake quanto a 
;		comida
;	4. condMorte
;		1 - trombar nas paredes
;		2 - trombar dela mesma
;		3 - starGameOver
;			imprime as mensagens de game-over na tela
;	5. moveSnake
;		- se posicao da cabeça == posicao da comida, 
;			incrementa tamanho da snake e pontuacao
;			foodstatus recebe -1
;			
;		2. movimentacao snake:
;			trabalhando com vetores:
;				- r0 recebe o endereço do último gomo da snake
;				- r1 recebe o endereço do penúltimo gomo
;				
;				- loop (moveLoops) copia o valor do último gomo
;				- no penúltimo, pra poder saber onde imprimir a snake
;				
;		3. funções moveUp, moveDown, moveLeft e moveRight
;			- comparam a direcao atual da snake com a entrada do teclado
;			- se a entrada for na direcao oposta, ela continua se movendo
;				para a direcao anterior. Caso contrário, ela se move na
;				nova direcao.
;				
;			- atualizaDirecao: atualiza a direção da cabeça da snake
;			
;	6. posicaoFood:
;		- se a variavel FoodStatus for diferente de -1, não mexe em nada
;			e vai pro fim da função
;			
;		- else foodStatus recebe zero 
;		
;		caso a snake tenha pego a comida, o algoritmo segue:
;			- pega a direção atual da snake
;			- soma um valor arbitrário
;			- corrige se a comida estiver nas bordas,
;			- altera a posição da comida (na variavel posFood)
;			- imprime a nova comida.


jmp main
;---------------------------------------------------------------
; variáveis e strings
;---------------------------------------------------------------
vetSnake:  	var #500
sizeSnake:	var #1
Dir:		var #1 ; Direção da snake - 0 = direita, 1 = baixo, 2= esquerda, 3 = cima

posFood:	var #1
FoodStatus:	var #1
pointsVar: 	var #1

GameOverMessage: 	string " MORREU HA HA HA HA HA  "
EraseGameOver:		string "                        "
RestartMessage:		string " ESPACO PARA REINICIAR JOGO "
EraseRestart:		string "                            "

tela0Linha0  : string "########################################"
tela0Linha1  : string "########################################"
tela0Linha2  : string "########################################"
tela0Linha3  : string "########################################"
tela0Linha4  : string "########################################"
tela0Linha5  : string "#####!!!!###############################"
tela0Linha6  : string "####!###!###############################"
tela0Linha7  : string "#####!####!!###!###!!####!##!#!!!!######"
tela0Linha8  : string "######!###!#!##!##!##!###!#!##!#########"
tela0Linha9  : string "#######!##!##!#!##!##!###!!###!!!#######"
tela0Linha10 : string "####!###!#!###!!#!!!!!!##!#!##!#########"
tela0Linha11 : string "#####!!!##!####!#!####!##!##!#!!!!######"
tela0Linha12 : string "########################################"
tela0Linha13 : string "########################################"
tela0Linha14 : string "########################################"
tela0Linha15 : string "########################################"
tela0Linha16 : string "########################################"
tela0Linha17 : string "########################################"
tela0Linha18 : string "########################################"
tela0Linha19 : string "########################################"
tela0Linha20 : string "########################################"
tela0Linha21 : string "#########SPACEBAR TO CONTINUE###########"
tela0Linha22 : string "########################################"
tela0Linha23 : string "########################################"
tela0Linha24 : string "########################################"
tela0Linha25 : string "########################################"
tela0Linha26 : string "########################################"
tela0Linha27 : string "########################################"
tela0Linha28 : string "########################################"
tela0Linha29 : string "########################################"  

tela1Linha0  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha1  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha2  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha3  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha4  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha5  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha6  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha7  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha8  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha9  : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha10 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha11 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha12 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha13 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha14 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha15 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha16 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha17 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha18 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha19 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha20 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha21 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha22 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha23 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha24 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha25 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha26 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha27 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha28 : string "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
tela1Linha29 : string "!!!!!!!APERTE ESPACO PARA INICIAR!!!!!!!"  


;---------------------------------------------------------------
; Funções
;---------------------------------------------------------------
; inicia as variáveis no começo do jogo:
; a Cabeça está na posição 460, e o corpo possui 2 nós. 


inicio:
	push r0
	push r1
	
	loadn r0, #3
	store sizeSnake, r0 ; seta o tamanho da snake pra 3 e armazena em sizeSnake
	
	loadn r0, #0
	store pointsVar, r0 ; zera pontuacao
	
	loadn 	r0, #vetSnake ; r0 recebe vetSnake[0]
	loadn 	r1, #460	  ; r1 recebe posição inicial da snake
	storei 	r0, r1		  ; vetsnake[0] recebe posição 460
	
	inc 	r0
	dec 	r1
	storei 	r0, r1		  ; vetSnake[1] recebe 459
	
	inc 	r0
	dec 	r1
	storei 	r0, r1		  ; vetSnake[2] recebe 458
	
	inc 	r0
	loadn 	r1, #0
	storei 	r0, r1		  ; vetSnake[3] recebe 0 (para comparação nas funcoes printSnake)
			
	call FirstPrintSnake  ; imprime a snake na tela a primeira vez na posição default. 
	
	loadn r0, #0
	store Dir, r0		  ; direção inicial = direita
	
	pop r1
	pop r0
	
	rts

;---------------------------------------------------------------
; pre-imprime a snake na inicializacao
;---------------------------------------------------------------
	
FirstPrintSnake:
	push r0
	push r1
	push r2
	push r3
	push r4
	
	loadn r0, #vetSnake		; r0 recebe o vetor da snake
	loadn r1, #'o'			; r1 recebe o caractere a ser impresso
	loadn r4, #768		    ; r4 recebe a cor da snake (oliva)
	add r1, r1, r4
	loadi r2, r0			; r2 recebe vetSnake[0]
		
	loadn 	r3, #0			; r3 recebe 0 (para comparacao com o fim da snake);
	
	looPrint:
		outchar r1, r2		; imprime caractere
		inc 	r0			; incrementa posicao do vetor
		loadi 	r2, r0		; recebe vetSnake[] incrementado
		cmp r2, r3			; comparacao com zero, para sair do loop
		jne looPrint
	
	loadn 	r0, #465		; posicao inicial da comida
	loadn 	r1, #'o'		; caractere da comida
	outchar r1, r0			; imprime a comida
	store 	posFood, r0		; armazena a posicao da comida
	
	pop r4
	pop	r3
	pop r2
	pop r1
	pop r0
	
	rts


	
; rotina simples para desenhar as bordas da fase
desenhaBordas:
	push r0
	push r1
	push r2
	push r3
	push r4
	
	loadn r0, #0
	loadn r1, #39
	
	loadn r2, #'$'
	loadn r3, #2304
	add r2, r2, r3
	
	loadn r3, #40
	loadn r4, #1200
	
	Stage_Loop1:
		outchar r2, r0
		outchar r2, r1
		
		add r0, r0, r3
		add r1, r1, r3
		
		cmp r0, r4
		jle Stage_Loop1
		
	loadn r0, #1
	loadn r1, #1161
	
	Stage_Loop2:
		outchar r2, r0
		outchar r2, r1
		
		inc r0
		inc r1
		
		cmp r0, r3
		jle Stage_Loop2
	
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	
	rts

;---------------------------------------------------------------
; rotina para mover a snake
;---------------------------------------------------------------
moveSnake:
	push r0
	push r1
	push r2
	push r3
	push r4
	
	
; checar posFood
	load 	r0, posFood			; posfood armazenado em r0
	loadn 	r1, #vetSnake		
	loadi 	r2, r1				; armazena pos da cabeça em r2
	
	cmp r0, r2					; compara se a cabeça esta na comida
	jne movimentacaoSnake		; se nao estiver, move normalmente
							
	load 	r0, sizeSnake		; se pegar comida
	inc 	r0					; incrementa tamanho da snake
	store 	sizeSnake, r0		; e armazena em sizeSnake
	
	load r0, pointsVar			; r0 recebe pontos
	inc r0						; incrementa pontos
	store pointsVar, r0			; armazena pontuacao
	
	loadn 	r0, #0				; ajusta foodstatus pra -1
	dec 	r0					
	store 	FoodStatus, r0		
		
	movimentacaoSnake:			; Passa o valor de cada gomo da snake pro próximo gomo,
		loadn 	r0, #vetSnake 	; no vetor da snake
		loadn 	r1, #vetSnake	
		load 	r2, sizeSnake	; r1 e r2 recebem endereço de vetsnake, r2 recebe tamanho
		
		add 	r0, r0, r2		; r0 recebe endereco do ultimo gomo da snake
		
		dec 	r2				
		add 	r1, r1, r2		; r1 recebe endereco do penultimo gomo da snake
		
		loadn 	r4, #0
		
		moveLoops:				; loop para passar o valor do gomo para o próximo
			loadi 	r3, r1		; r3 recebe valor do gomo
			storei 	r0, r3		; armazena no próximo gomo o valor do anterior
			
			dec r0				; decrementa valores
			dec r1
			
			cmp r2, r4			; comparacao pra finalizar o loop
			dec r2
			
			jne moveLoops	

; -----------------------------------------------------------------			
; CALCULO DA DIRECAO
; -----------------------------------------------------------------
; r2 recebe o char a ser comparado com a entrada do teclado, e manda pra funcao adequada
; como num switch case

		inchar 	r1
		
		loadn r2, #'w'
		cmp r1, r2
		jeq moveUp
		
		loadn r2, #'s'
		cmp r1, r2
		jeq moveDown
		
		loadn r2, #'a'
		cmp r1, r2
		jeq moveLeft
		
		loadn r2, #'d'
		cmp r1, r2
		jeq moveRight		
	
		
		jmp atualizaDirecao
; move cima (e auxiliar para aceitar entrada oposta)
		moveUp:
			loadn 	r0, #3			; r0 recebe a direcao desejada (entrada do teclado)
			loadn 	r1, #1			; r1 recebe a direcao oposta à entrada
			load  	r2, Dir			; r2 recebe a direcao atual
			cmp 	r1, r2			; a funcao compara se a entrada é oposta à direcao desejada
			jeq 	move_Down		; se for oposta, a snake continua se movendo na direçao anterior
			
			store 	Dir, r0			; se nao for, ela muda de direcao e armazena a informacao na
			jmp 	Move_Up			; variavel dir
		
		Move_Up:
			loadn 	r0, #vetSnake	; r0 = & vetSnake
			loadi 	r1, r0			; r1 = vetSnake[0]
			loadn 	r2, #40
			sub 	r1, r1, r2
			storei 	r0, r1
			
			jmp Move_End
			
; move baixo (e auxiliar para aceitar entrada oposta)
		moveDown:
			loadn 	r0, #1			; equivalente moveUp
			loadn 	r1, #3
			load  	r2, Dir
			cmp 	r1, r2
			jeq 	Move_Up
			
			store 	Dir, r0
			jmp 	move_Down
			
		move_Down:
			loadn 	r0, #vetSnake
			loadi 	r1, r0
			loadn 	r2, #40
			add 	r1, r1, r2
			storei 	r0, r1
			
			jmp Move_End
			
; move esquerda (e auxiliar para aceitar entrada oposta)
		moveLeft:
			loadn 	r0, #2			; equivalente moveUp
			loadn 	r1, #0
			load  	r2, Dir
			cmp 	r1, r2
			jeq 	Move_Right
			
			store 	Dir, r0
			jmp 	Move_Left

		Move_Left:
			loadn 	r0, #vetSnake
			loadi 	r1, r0
			dec 	r1
			storei 	r0, r1
			
			jmp Move_End

; move direita (e auxiliar para aceitar entrada oposta)
		moveRight:
			loadn 	r0, #0			; equivalente moveUp
			loadn 	r1, #2
			load  	r2, Dir
			cmp 	r1, r2
			jeq 	Move_Left
			
			store 	Dir, r0
			jmp 	Move_Right
			
		Move_Right:
			loadn 	r0, #vetSnake
			loadi 	r1, r0
			inc 	r1
			storei 	r0, r1
			
			jmp Move_End

	
atualizaDirecao:
		load 	r0, Dir
				
		loadn 	r2, #0
		cmp 	r0, r2
		jeq 	Move_Right
		
		loadn 	r2, #1
		cmp 	r0, r2
		jeq 	move_Down
		
		loadn 	r2, #2
		cmp 	r0, r2
		jeq 	Move_Left
		
		loadn 	r2, #3
		cmp 	r0, r2
		jeq 	Move_Up
		
		jmp Move_End
			
	Move_End:
		pop r4
		pop r3
		pop r2
		pop r1
		pop r0

	rts

posicaoFood:
	push r0
	push r1

	loadn 	r0, #0				
	dec 	r0
	load 	r1, FoodStatus
	cmp 	r0, r1
	
	jne Replace_End				; if(FoodStatus != -1), vai pro fim da funcao
	
	loadn r1, #0
	store FoodStatus, r1		; else, foodstatus = 0 e continua função
	
	
	load  r1, posFood
	load r0, Dir
; Direção da snake - 0 = direita, 1 = baixo, 2= esquerda, 3 = cima

	loadn r2, #0				; 
	cmp r0, r2
	jeq reposDir
	
	loadn r2, #1
	cmp r0, r2
	jeq reposDown
	
	loadn r2, #2
	cmp r0, r2
	jeq reposEsq
	
	loadn r2, #3
	cmp r0, r2
	jeq reposUp
	
;r1 está armazenando posfood
	reposDir:
		loadn r3, #389		; gerador nada aleatório de posição de comidas
		add r1, r1, r3
		jmp reposBordas
	reposDown:
		loadn r3, #438
		sub r1, r1, r3
		jmp reposBordas
	reposEsq:
		loadn r3, #365
		sub r1, r1, r3
		jmp reposBordas
	reposUp:
		loadn r3, #422
		add r1, r1, r3
		jmp reposBordas
	
	
	reposBordas:     		;funcao pra verificar se a comida não está fora dos limites da tela
		loadn r2, #40		; comida na borda superior da tela
		cmp r1, r2
		jle reposCima 	
		
		loadn r2, #1160		; comida na borda inferior da tela	
		cmp r1, r2
		jgr reposBaixo	
		
		loadn r0, #40		; comida na borda esquerda
		loadn r3, #1
		mod r2, r1, r0
		cmp r2, r3
		jel reposEsq
		
		loadn r0, #40		; comida na borda direita
		loadn r3, #39
		mod r2, r1, r0		
		cmp r2, r3
		jeg reposDir
		
		jmp reposUpdate
		
		reposBaixo:				; se estiver na borda de baixo, reposiciona a comida na posicao 238
			loadn r1, #238
			jmp reposUpdate
		reposCima:				; se estiver na borda de cima, reposiciona a comida na posicao 981
			loadn r1, #981
			jmp reposUpdate
		reposDir:				; se estiver na borda direita, reposiciona a comida na posicao 795
			loadn r1, #795
			jmp reposUpdate
		reposEsq:				; se estiver na borda da esquerda, reposiciona a comida na posicao 247
			loadn r1, #247
			jmp reposUpdate
			
		reposUpdate:			; printa a comida na nova posição
			store posFood, r1
			loadn r0, #'*'
			outchar r0, r1
	
	Replace_End:
		pop r1
		pop r0
	
	rts

	
;---------------------------------------------------------------
; Verifica se snake bateu em algum lugar que não devia
;---------------------------------------------------------------
	
condMorte:
	loadn r0, #vetSnake		; r0 recebe vetor vetsnake
	loadi r1, r0			; r1 recebe índice zero do vetor vetsnake r0 = vetSnake[0]
	
	; condição 1: bateu na parede direita:
	loadn r2, #40		; se a posição da cabeça da snake (vetSnake[0]) for 
	loadn r3, #39		; igual a (mod vetSnake[0] % 40), ela bateu na parede
	mod r2, r1, r2		; direita. 
	cmp r2, r3
	jeq startGameOver
	
	; condicao 2: bateu na parede esquerda:
	loadn r2, #40		; se a posicao da cabeça for igual a (mod vetsnake[0], #0)
	loadn r3, #0		; ela esbarrou na parede esquerda
	mod r2, r1, r2		
	cmp r2, r3
	jeq startGameOver
	
	; condicao 3: bateu na parede de cima
	loadn r2, #40		; se a posição da cabeça for menor que 40, significa que 
	cmp r1, r2			; a snake bateu na parede de cima
	jle startGameOver
	
	; condicao 4: bateu na parede de baixo
	loadn r2, #1160		; se a posicao da cabeça for maior que 1160, ela esbarrou
	cmp r1, r2			; na parede de baixo
	jgr startGameOver
	
	; Trombou nela mesma
	load 	r2, sizeSnake	; r2 recebe tamanho da snake
	loadn 	r3, #1			; r3 recebe numero 1
	loadi 	r4, r0			; r4 recebe cabeça da snake (vetsnake[0])
		
		colisionLoop:			
			inc 	r0			; incrementa vetsnake
			loadi 	r1, r0		; r1 recebe endereço indexado e incrementado de vetsnake
			cmp r1, r4			; ou seja, r1 = vetSnake[i++];
			jeq startGameOver	; se posicao da cabeça = qq parte da cobra, da game over
			
			dec r2				; decrementa r2 (tem o valor sizeSnake)
			cmp r2, r3			; compara e manda pro começo do loop ou pro resto do codigo
			jne colisionLoop
		
	
	jmp condMorteFim

; imprime as mensagens de game over
startGameOver:
	
		loadn r0, #615
		loadn r1, #GameOverMessage
		loadn r2, #0
		call Imprime
		
		loadn r0, #687
		loadn r1, #RestartMessage
		loadn r2, #0
		call Imprime
		
		jmp gameOverLoop
	
	condMorteFim:
	
	rts

desenhaSnake:
	push r0
	push r1
	push r2
	push r3 
	push r4
	
	
	load 	r0, posFood  	; r0 recebe posFood
	loadn 	r1, #'o'		; caractere da comida
	loadn r4, #2304			; cor (vermelha) da comida
	add r1, r1, r4			; adiciona cor na comida
	outchar r1, r0			; imprime comida
	
	loadn 	r0, #vetSnake	; r0 recebe endereço do vetor vetSnake
	loadn 	r1, #'o'		; r1 recebe o caractere da snake
	loadn r4, #768			; r4 recebe a cor da snake (verde oliva)
	add r1, r1, r4			; adiciona cor na snake
	loadi 	r2, r0			; r2 recebe primeiro elemento do vetor vetsnake
	outchar r1, r2			; imprime o primeiro caractere da snake
	
	loadn 	r0, #vetSnake	; r0 recebe endereço do vetor vetSnake
	loadn 	r1, #' '		; r1 recebe espaço em branco
	load 	r3, sizeSnake	; r3 recebe tamanho da snake
	add 	r0, r0, r3		; r0 recebe tamanho + vetSnake
	loadi 	r2, r0			; r2 recebe o último elemento de vetsnake
	outchar r1, r2			; apaga o rabo da snake
	
	Draw_End:
		pop r4
		pop	r3
		pop r2
		pop r1
		pop r0
	
	rts
;----------------------------------
Delay:
						;Utiliza Push e Pop para nao afetar os Ristradores do programa principal
	Push R0
	Push R1
	
	Loadn R1, #100  ; a
    Delay_volta2:				;Quebrou o contador acima em duas partes (dois loops de decremento)
	Loadn R0, #500	; b
    Delay_volta: 
	Dec R0					; (4*a + 6)b = 1000000  == 1 seg  em um clock de 1MHz
	JNZ Delay_volta	
	Dec R1
	JNZ Delay_volta2
	
	Pop R1
	Pop R0
	
	RTS

Restart_Game:
	inchar 	r0
	loadn 	r1, #' '
	
	cmp r0, r1
	jeq apagatudo
	
apagatudo:	
	loadn r2, #tela1Linha0
	loadn r1, #0
	call ImprimeTela
	jmp main
	
	rts


; rotina para apagar snake morta e reiniciar o jogo
EraseSnake:
	push r0
	push r1
	push r2
	push r3
	
	loadn 	r0, #vetSnake		; r0 recebe endereço de vetSnake
	inc 	r0	
	loadn 	r1, #' '			; r1 recebe  ' ' para apagar no loop
	loadi 	r2, r0				; r2 recebe poiscao zero de vetsnake
	loadn 	r3, #0				; r3 recebe zero, para comparacao com o fim da snake
	
	looPrint:
		outchar r1, r2			; loop para apagar a snake
		inc 	r0
		loadi 	r2, r0
		cmp r2, r3
		jne looPrint
	
	pop	r3
	pop r2
	pop r1
	pop r0
	
	rts

Imprime:
	push r0		; Posição na tela para imprimir a string
	push r1		; Endereço da string a ser impressa
	push r2		; Cor da mensagem
	push r3
	push r4

	
	loadn r3, #'\0'

	LoopImprime:	
		loadi r4, r1
		cmp r4, r3
		jeq SaiImprime
		add r4, r2, r4
		outchar r4, r0
		inc r0
		inc r1
		jmp LoopImprime
		
	SaiImprime:	
		pop r4	
		pop r3
		pop r2
		pop r1
		pop r0
		
	rts
	
;--------------------------------------------------------
; IMPRIME STRING
;--------------------------------------------------------

ImprimeTela: 	

	push r0		
	push r1		
	push r2		
	push r3		
	push r4		
	push r5		
	push r6		
				
	loadn R0, #0
	loadn R3, #40
	loadn R4, #41
	loadn R5, #1200
	loadn R6, #tela0Linha0
	
   ImprimeTela_Loop:
		call ImprimeStr
		add r0, r0, r3
		add r2, r2, r4
		add r6, r6, r4
		cmp r0, r5
		jne ImprimeTela_Loop

	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts

	
ImprimeStr:
	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6
	
	
	loadn r3, #'\0'	
	loadn r5, #' '	

   ImprimeStr_Loop:	
		loadi r4, r2
		cmp r4, r3
		jeq ImprimeStr_Sai
		cmp r4, r5
		jeq ImprimeStr_Skip
		add r4, r1, r4
		outchar r4, r0
		storei r6, r4
   ImprimeStr_Skip:
		inc r0
		inc r2
		inc r6
		jmp ImprimeStr_Loop
	
   ImprimeStr_Sai:	
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts

;--------------------------------------------------------
; Pontuacao
;--------------------------------------------------------
	
pontos: 
	push r0
	push r1
	push r2
	push r3
	push r4
	
	loadn r0, #sizeSnake
	loadn r1, #1196
	loadn r2, #50
	
	add r0, r2, r0
	
	outchar r0, r1
	
fimpts:
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts
	
pregame:
	push r0
	push r1
	push r2
	push r3
	push r4

	loadn r2, #tela0Linha0
	loadn r1, #0
	call ImprimeTela
	loadn r3, #' '
	inchar r4
	cmp r3, r4
	jne pregame
	
	loadn r2, #tela1Linha0
	loadn r1, #0
	call ImprimeTela
	
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts
	
	
main:

	call pregame
	call inicio
	call desenhaBordas
	

	gameLoop:
			call desenhaSnake
			call condMorte
			
			call moveSnake
			call posicaoFood
					
			call Delay
			
			;call pontos
			
			jmp gameLoop
		gameOverLoop:
			call desenhaBordas
			call Restart_Game
		
		jmp gameOverLoop
	
