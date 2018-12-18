COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Aseembly Language libraries.
The program generates 3 random values, J and K for ranges of L. L is then stored in an array
element. This process is looped until the entire array has been filled, and is stored in a 
procedure. The procedure is called twice in main for demonstration.

==========================================================================================
Author : Rami Husein
Date Created : 07 / 28 / 2018
Revisions : 0
Course : CISS 360
Assignment : Week 5 Assignment 1
==========================================================================================*
INCLUDE Irvine32.inc

.data

throwArray DWORD 10 DUP(?)
throwArray2 DWORD 10 DUP(?)
arrayLength = 10

.code
main PROC

mov esi, OFFSET throwArray
call fillArray	;Call once
call Crlf

mov esi, OFFSET throwArray2
call fillArray	;Call again
call Crlf

exit
main ENDP


fillArray PROC
mov ecx, arrayLength		;Set the counter

.WHILE ecx > 0
	dec ecx				;Decrement the counter

	mov eax, 20
	call RandomRange
	add eax, 1
	mov ebx, eax		; Generate a number between 1 and 20 === (High Range)

	sub eax, 1
	call RandomRange
	add eax, 1
	mov edx, eax		; Generate a number between 1 and (High Range) === (Low Range)



	mov eax, ebx		;Set the High Range 
	sub eax, edx 		;Subtract from the High Range, the Low Range
	call RandomRange	;Generate random number into eax
	add eax, edx		;Add the Low Range back to generate a number between the original ranges




	call WriteInt
	mov [esi], eax		;Fill element
	add esi, 4			;Point to next DWORD element

.ENDW
ret
fillArray ENDP


END main