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
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword
FindGreatest proto, ptrArray:PTR DWORD, arrSize:DWORD

.data
greatest DWORD ?

true = 1
false = 0
neg_flag BYTE ?

arr1 DWORD 5, 10, -5, -11, 3, 5		;signed doubleword array

arr2 DWORD -8, -11, -19, 3, -21, 567		;signed doubleword array

arr3 DWORD -5, 5, -4, 4, -3, 3, -2, 2, -1, 1, 0		;signed doubleword array

.code
main PROC

invoke FindGreatest, ADDR arr1, LENGTHOF arr1
invoke FindGreatest, ADDR arr2, LENGTHOF arr2
invoke FindGreatest, ADDR arr3, LENGTHOF arr3

invoke ExitProcess,0
main ENDP

;==========================================================
FindGreatest PROC USES esi ecx eax, ptrArray:PTR DWORD, arrSize:DWORD

mov greatest, 0
mov esi, ptrArray
mov ecx, arrSize
mov eax, 0

;Exit if length of array is zero
cmp ecx, 0
je L9


L1:
	;Check if number is negative
	mov eax, [esi]
	mov neg_flag, false
	or eax, eax

	jns L3	;jump if positive
		neg eax

		;if number is negative, check if the greatest number is also negative
		push eax				;save the surrent number
		mov eax, greatest
		or eax, eax
		;if the greatest number is not negative, then the negative current number is defintelly smaller than it, so move on
		jns L4
		;if the greatest number is negative, then reverse compare (smaller number would be larger)

		pop eax
		cmp greatest, eax
		jle L4
		mov greatest, eax
		jmp L4




		;if the number is positive
		L3:
		cmp greatest, eax
		jg L4
		mov greatest, eax
		jmp L4

L4:
add esi, 4
loop L1



L9:
mov eax, greatest
ret
FindGreatest ENDP

;=========================================================




END main