jmp main
;---------------------------------------------------------------
; variáveis e strings
;---------------------------------------------------------------
vetSnake:  	var #500
sizeSnake:	var #1
Dir:		var #1 ; Direção da snake - 0 = direita, 1 = baixo, 2= esquerda, 3 = cima

posFood:	var #1
FoodStatus:	var #1

GameOverMessage: 	string " MORREU!!! "
EraseGameOver:		string "           "
RestartMessage:		string " ESPACO PARA REINICIAR JOGO "
EraseRestart:		string "                            "


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
	storei 	r0, r1		  ; vetSnake[4] recebe 0 (para comparação nas funcoes printSnake)
			
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

Move_Snake:
	push r0	; Dir / vetSnake
	push r1	; inchar
	push r2 ; local helper
	push r3
	push r4
	
	; Sincronização
	loadn 	r0, #5000
	loadn 	r1, #0
	mod 	r0, r6, r0		; r1 = r0 % r1 (Teste condições de contorno)
	cmp 	r0, r1
	jne Move_End
	; =============
	
	Check_Food:
		load 	r0, posFood
		loadn 	r1, #vetSnake
		loadi 	r2, r1
		
		cmp r0, r2
		jne Spread_Move
		
		load 	r0, sizeSnake
		inc 	r0
		store 	sizeSnake, r0
		
		loadn 	r0, #0
		dec 	r0
		store 	FoodStatus, r0
		
	Spread_Move:
		loadn 	r0, #vetSnake
		loadn 	r1, #vetSnake
		load 	r2, sizeSnake
		
		add 	r0, r0, r2		; r0 = vetSnake[Size]
		
		dec 	r2			; r1 = vetSnake[Size-1]
		add 	r1, r1, r2
		
		loadn 	r4, #0
		
		Spread_Loop:
			loadi 	r3, r1
			storei 	r0, r3
			
			dec r0
			dec r1
			
			cmp r2, r4
			dec r2
			
			jne Spread_Loop	
	
	Change_Dir:
		inchar 	r1
		
		loadn r2, #'w'	; char r4 = 'w'
		cmp r1, r2
		jeq Move_W
		
		loadn r2, #'s'	; char r4 = 's'
		cmp r1, r2
		jeq Move_S
		
		loadn r2, #'a'	; char r4 = 'a'
		cmp r1, r2
		jeq Move_A
		
		loadn r2, #'d'	; char r4 = 'd'
		cmp r1, r2
		jeq Move_D		
	
		
		jmp Update_Move
	
		Move_D:
			loadn 	r0, #0
			; Impede de "ir pra trás"
			loadn 	r1, #2
			load  	r2, Dir
			cmp 	r1, r2
			jeq 	Move_Left
			
			store 	Dir, r0
			jmp 	Move_Right
		Move_S:
			loadn 	r0, #1
			; Impede de "ir pra trás"
			loadn 	r1, #3
			load  	r2, Dir
			cmp 	r1, r2
			jeq 	Move_Up
			
			store 	Dir, r0
			jmp 	Move_Down
		Move_A:
			loadn 	r0, #2
			; Impede de "ir pra trás"
			loadn 	r1, #0
			load  	r2, Dir
			cmp 	r1, r2
			jeq 	Move_Right
			
			store 	Dir, r0
			jmp 	Move_Left
		Move_W:
			loadn 	r0, #3
			; Impede de "ir pra trás"
			loadn 	r1, #1
			load  	r2, Dir
			cmp 	r1, r2
			jeq 	Move_Down
			
			store 	Dir, r0
			jmp 	Move_Up
	
	Update_Move:
		load 	r0, Dir
				
		loadn 	r2, #0
		cmp 	r0, r2
		jeq 	Move_Right
		
		loadn 	r2, #1
		cmp 	r0, r2
		jeq 	Move_Down
		
		loadn 	r2, #2
		cmp 	r0, r2
		jeq 	Move_Left
		
		loadn 	r2, #3
		cmp 	r0, r2
		jeq 	Move_Up
		
		jmp Move_End
		
		Move_Right:
			loadn 	r0, #vetSnake	; r0 = & vetSnake
			loadi 	r1, r0		; r1 = vetSnake[0]
			inc 	r1		; r1++
			storei 	r0, r1
			
			jmp Move_End
				
		Move_Down:
			loadn 	r0, #vetSnake	; r0 = & vetSnake
			loadi 	r1, r0		; r1 = vetSnake[0]
			loadn 	r2, #40
			add 	r1, r1, r2
			storei 	r0, r1
			
			jmp Move_End
		
		Move_Left:
			loadn 	r0, #vetSnake	; r0 = & vetSnake
			loadi 	r1, r0		; r1 = vetSnake[0]
			dec 	r1		; r1--
			storei 	r0, r1
			
			jmp Move_End
		Move_Up:
			loadn 	r0, #vetSnake	; r0 = & vetSnake
			loadi 	r1, r0		; r1 = vetSnake[0]
			loadn 	r2, #40
			sub 	r1, r1, r2
			storei 	r0, r1
			
			jmp Move_End
	
	Move_End:
		pop r4
		pop r3
		pop r2
		pop r1
		pop r0

	rts

Replace_Food:
	push r0
	push r1

	loadn 	r0, #0
	dec 	r0
	load 	r1, FoodStatus
	cmp 	r0, r1
	
	jne Replace_End
	
	loadn r1, #0
	store FoodStatus, r1
	load  r1, posFood
	
	load r0, Dir
	
	loadn r2, #0
	cmp r0, r2
	jeq Replace_Right
	
	loadn r2, #1
	cmp r0, r2
	jeq Replace_Down
	
	loadn r2, #2
	cmp r0, r2
	jeq Replace_Left
	
	loadn r2, #3
	cmp r0, r2
	jeq Replace_Up
	
	Replace_Right:
		loadn r3, #355
		add r1, r1, r3
		jmp Replace_Boundaries
	Replace_Down:
		loadn r3, #445
		sub r1, r1, r3
		jmp Replace_Boundaries
	Replace_Left:
		loadn r3, #395
		sub r1, r1, r3
		jmp Replace_Boundaries
	Replace_Up:
		loadn r3, #485
		add r1, r1, r3
		jmp Replace_Boundaries
	
	
	Replace_Boundaries:
		loadn r2, #40
		cmp r1, r2
		jle Replace_Lower
		
		loadn r2, #1160
		cmp r1, r2
		jgr Replace_Upper
		
		loadn r0, #40
		loadn r3, #1
		mod r2, r1, r0
		cmp r2, r3
		jel Replace_West
		
		loadn r0, #40
		loadn r3, #39
		mod r2, r1, r0
		cmp r2, r3
		jeg Replace_East
		
		jmp Replace_Update
		
		Replace_Upper:
			loadn r1, #215
			jmp Replace_Update
		Replace_Lower:
			loadn r1, #1035
			jmp Replace_Update
		Replace_East:
			loadn r1, #835
			jmp Replace_Update
		Replace_West:
			loadn r1, #205
			jmp Replace_Update
			
		Replace_Update:
			store posFood, r1
			loadn r0, #'*'
			outchar r0, r1
	
	Replace_End:
		pop r1
		pop r0
	
	rts

Dead_Snake:
	loadn r0, #vetSnake
	loadi r1, r0
	
	; Trombou na parede direita
	loadn r2, #40
	loadn r3, #39
	mod r2, r1, r2		; r2 = r1 % r2 (Teste condições de contorno)
	cmp r2, r3
	jeq GameOver_Activate
	
	; Trombou na parede esquerda
	loadn r2, #40
	loadn r3, #0
	mod r2, r1, r2		; r2 = r1 % r2 (Teste condições de contorno)
	cmp r2, r3
	jeq GameOver_Activate
	
	; Trombou na parede esquerda
	loadn r2, #40
	cmp r1, r2
	jle GameOver_Activate
	
	; Trombou na parede esquerda
	loadn r2, #1160
	cmp r1, r2
	jgr GameOver_Activate
	
	; Trombou na própria cobra
	Collision_Check:
		load 	r2, sizeSnake
		loadn 	r3, #1
		loadi 	r4, r0			; Posição da cabeça
		
		Collision_Loop:
			inc 	r0
			loadi 	r1, r0
			cmp r1, r4
			jeq GameOver_Activate
			
			dec r2
			cmp r2, r3
			jne Collision_Loop
		
	
	jmp Dead_Snake_End
	
	GameOver_Activate:
		load 	r0, posFood
		loadn 	r1, #' '
		outchar r1, r0
	
		loadn r0, #615
		loadn r1, #GameOverMessage
		loadn r2, #0
		call Imprime
		
		loadn r0, #687
		loadn r1, #RestartMessage
		loadn r2, #0
		call Imprime
		
		jmp GameOver_loop
	
	Dead_Snake_End:
	
	rts

desenhaSnake:
	push r0
	push r1
	push r2
	push r3 
	push r4
	
	; Sincronização
	loadn 	r0, #1000
	loadn 	r1, #0
	mod 	r0, r6, r0		; r1 = r0 % r1 (Teste condições de contorno)
	cmp 	r0, r1
	jne Draw_End
	; =============
	
	load 	r0, posFood
	loadn 	r1, #'o'
	loadn r4, #2304
	add r1, r1, r4
	outchar r1, r0
	
	loadn 	r0, #vetSnake	; r0 = & vetSnake
	loadn 	r1, #'o'		; r1 = 'O'
	loadn r4, #768
	add r1, r1, r4
	loadi 	r2, r0			; r2 = vetSnake[0]
	outchar r1, r2			
	
	loadn 	r0, #vetSnake	; r0 = & vetSnake
	loadn 	r1, #' '		; r1 = ' '
	load 	r3, sizeSnake	; r3 = sizeSnake
	add 	r0, r0, r3		; r0 += sizeSnake
	loadi 	r2, r0			; r2 = vetSnake[sizeSnake]
	outchar r1, r2
	
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
	jeq Restart_Activate
	
	jmp Restart_End
	
	Restart_Activate:
		loadn r0, #615
		loadn r1, #EraseGameOver
		loadn r2, #0
		call Imprime
		
		loadn r0, #687
		loadn r1, #EraseRestart
		loadn r2, #0
		call Imprime
	
		call EraseSnake
		call inicio
		
		jmp ingame_loop
		
	Restart_End:
	
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
	
pontos: 
	push r0
	push r1
	push r2
	push r3
	
	loadn r0, #sizeSnake
	loadn r1, #1196
	loadn r2, #9
	cmp r0, r2
	jel unidades
	
unidades: 
	loadn r3, #30
	add r0, r0, r3
	outchar r0, r1
	jmp fimpts
	
fimpts:
	pop r3
	pop r2
	pop r1
	pop r0
	rts
	
main:
	call inicio
	call desenhaBordas
	
	loop:
		ingame_loop:
			call desenhaSnake
			call Dead_Snake
			
			call Move_Snake
			call Replace_Food
					
			call Delay
			
			call pontos
			
			jmp ingame_loop
		GameOver_loop:
			call desenhaBordas
			call Restart_Game
		
		jmp GameOver_loop
	
