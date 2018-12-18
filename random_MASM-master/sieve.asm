COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Aseembly Language libraries.
This program creates an array of numbers from 2 - 1000. It then processes the array, determining
if the values inside are prime numbers. If they are, the program stores the numbers to another
array, as well as displays the number to the console.

==========================================================================================
Author : Rami Husein
Date Created : 08 / 05 / 2018
Revisions : 0
Course : CISS 360
Assignment : Week 6 Assignment 2
==========================================================================================*
INCLUDE Irvine32.inc

.data

primes word 2000 DUP (0)
numbers word 2000 DUP (0)
count word 0


.code
main PROC
mov eax, 2	;Set first number
mov esi, 0	;numbers indexer
mov edi, 0	;primes indexer

;Fill an array with numbers 2 - 1000
.WHILE ax < LENGTHOF numbers
	mov numbers[esi], ax
	inc ax
	add esi, 2
.ENDW


;iterate over all numbers
mov esi, 0

.WHILE esi < LENGTHOF numbers
	mov count, 0


	;Iterate over numbers 0(zero) to current
	call ClearRegs
	mov cx, numbers[esi]
	mov eax, ecx
	cdq
	mov ebx, 2
	div ebx
	mov edx, eax
	
	mov ebx, 2
	.WHILE ebx <= edx
		push edx
		mov ecx, 0
		mov cx, numbers[esi]
		mov eax, ecx
		cdq
		div ebx

		.IF edx == 0
			add count, 1
			.BREAK
		.ENDIF
		add ebx, 1
		pop edx
	.ENDW
	
	.IF count == 0
		mov eax, 0
		mov ax, numbers[esi]
		mov primes[edi], ax
		call WriteInt
		call Crlf
		add edi, 2

	.ENDIF
	add esi, 2


.ENDW

		






exit
main ENDP



ClearRegs PROC
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0
ret
ClearRegs ENDP

END main