jmp main


tela1Linha0  : string "                                        "
tela1Linha1  : string "                                        "
tela1Linha2  : string "                                        "
tela1Linha3  : string "                                        "
tela1Linha4  : string "                                        "
tela1Linha5  : string "                                        "
tela1Linha6  : string "                                        "
tela1Linha7  : string "                                        "
tela1Linha8  : string "                                        "
tela1Linha9  : string "****************************************"
tela1Linha10 : string "                                        "
tela1Linha11 : string "                                        "
tela1Linha12 : string "                                        "
tela1Linha13 : string "                                        "
tela1Linha14 : string "                                        "
tela1Linha15 : string "                                        "
tela1Linha16 : string "                                        "
tela1Linha17 : string "                                        "
tela1Linha18 : string "****************************************"
tela1Linha19 : string "                                        "
tela1Linha20 : string "                                        "
tela1Linha21 : string "                                        "
tela1Linha22 : string "                                        "
tela1Linha23 : string "                                        "
tela1Linha24 : string "                                        "
tela1Linha25 : string "                                        "
tela1Linha26 : string "                                        "
tela1Linha27 : string "                                        "
tela1Linha28 : string "                                        "
tela1Linha29 : string "                                        "

;---------------------------------------------------------------
; rotinas para imprimir a tela
;---------------------------------------------------------------
	
	
ImprimeTela: 	; Rotina de impressao de tela elaborada pelo Prof Simoes
				; Poucas alteracoes (registradores utilizados) foram feitas
	push r0		; protege o r0 na pilha para ser usado posteriormente
	push r1		; protege o r1 na pilha para ser usado posteriormente
	push r2		; protege o r2 na pilha para ser usado posteriormente
	push r3		; protege o r3 na pilha para ser usado posteriormente 
	push r4		; protege o r4 na pilha para ser usado posteriormente 
	push r5		; protege o r5 na pilha para ser usado posteriormente 
	push r6		; protege o r6 na pilha para ser usado posteriormente 

	; R2 possui a posicao da tela a ser imprimida
	loadn R0, #0 			; posicao inicial da impressao, comeco da tela.
	loadn R3, #40  			; Incremento da linha na tela
	loadn R4, #41  			; Incremento da linha no mapa da memoria (inclui caractere nulo)
	loadn R5, #1200 		; Limite da tela
	loadn R6, #tela1Linha0	; Endereco onde comeca a primeira linha do cenario na memoria
	
   ImprimeTela_Loop:
		call ImprimeStr
		add r0, r0, r3  		; incrementaposicao para a segunda linha na tela -->  r0 = R0 + 40
		add r2, r2, r4  		; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r2 = r2 + 41
		add r6, r6, r4  		; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r2 = r2 + 41
		cmp r0, r5				; Compara r0 com 1200
		jne ImprimeTela_Loop	; Enquanto r0 < 1200

	pop r6	; Resgata os valores dos registradores utilizados na Subrotina da Pilha
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts

;-----------------------------------------------------------
; rotina para imprimir strings da tela
;-----------------------------------------------------------
	
ImprimeStr:	;  Rotina de Impresao de Mensagens feita pelo Prof. Simoes    
	push r0	; protege o r0 na pilha para ser usado posteriormente
	push r1	; protege o r1 na pilha para ser usado posteriormente
	push r2	; protege o r2 na pilha para ser usado posteriormente
	push r3	; protege o r3 na pilha para ser usado posteriormente
	push r4	; protege o r4 na pilha para ser usado posteriormente
	push r5	; protege o r5 na pilha para ser usado posteriormente
	push r6	; protege o r6 na pilha para ser usado posteriormente
	
	
	loadn r3, #'\0'	; Criterio de parada
	loadn r5, #' '	; Espaco em Branco

   ImprimeStr_Loop:	
		loadi r4, r2 		; Transforma o ponteiro para a tela a ser impressa em valor
		cmp r4, r3			; If (Char == \0) verifica criterio de parada
		jeq ImprimeStr_Sai
		cmp r4, r5			; If (Char == ' ') pula impressao se o caractere for "espaco"
		jeq ImprimeStr_Skip
		add r4, r1, r4		; Soma a Cor do caractere a ser imprimido
		outchar r4, r0		; Imprime o caractere na tela
		storei r6, r4 		; Salva alteracao na memoria
   ImprimeStr_Skip:
		inc r0				; Incrementa a posicao na tela
		inc r2				; Incrementa o ponteiro da String
		inc r6				; Incrementa o ponteiro da String da tela na memoria
		jmp ImprimeStr_Loop
	
   ImprimeStr_Sai:	
	pop r6	; Resgata os valores dos registradores utilizados na Subrotina da Pilha
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts
	
;--------------------------------------------------------------
;main
;--------------------------------------------------------------
main:
	loadn r2, #tela1Linha0	; Tela na memoria que limpa tudo
	loadn r1, #0  			; cor branca!
	call ImprimeTela   		; Rotina de Impresao de Cenario na Tela Inteira
	
jmp main
