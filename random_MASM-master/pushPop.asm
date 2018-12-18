COMMENT *
==========================================================================================
Description:
This program takes a string and uses push and pop methods to reverse it.

==========================================================================================
Author: Rami Husein
Date Created: 07/13/2018
Revisions: 0
Course: CISS 360
Assignment: Week 4 Assignment null
==========================================================================================*


.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
	varString BYTE "Rami", 0

.code
main PROC
	
		mov ecx, LENGTHOF varString - 1				;Set the counter to the last index of the string
		mov esi, OFFSET varString					;Set the indexPtr to the beginning of the string

	L1:	
		movzx eax, BYTE PTR[esi]					;Move the BYTE that esi is pointing to, to eax with leading zeros
		push eax									;Push eax to the stack
		inc esi										;Increment to the next element
		loop L1

		mov ecx, LENGTHOF varString - 1				;Reset the counter to the last index of the string
		mov esi, OFFSET varString					;Reset the indexPtr to the beginning of the string

	L2:
		pop eax										;Pop eax from the stack
		mov [esi], al								;Move the lower of eax to the value container of the indexPtr
		inc esi										;Increment to the next element
		loop L2

	INVOKE ExitProcess, 0
main ENDP
END main