COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Assembly Language libraries.
This program uses a defined procedure to iterate over an array and find 3 consecutive occurences
of 3. The procedure returns '1' in EAX if the seequence is found, and '0' otherwise.


==========================================================================================
Author : Rami Husein
Date Created : 08 / 10 / 2018
Revisions : 0
Course : CISS 360
Assignment : Week 7 Assignment 3
==========================================================================================*
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword
FindThrees PROTO, ptrArray:PTR DWORD, arrSize:DWORD

.data
arr1 DWORD 1, 2, 3, 4, 5, 3, 2, 4, 3, 2, 3, 3, 3, 5, 6, 8, 8, 9				;Yes
arr2 DWORD 3, 3, 8, 8, 8, 3, 8, 33, 3, 3, 8, 7, 3, 6, 4, 6					;No
arr3 DWORD 9, 3, 2, 3, 3, 2, 33, 3, 3, 2, 3, 2, 3, 2, 3, 3, 3, 3			;Yes
arr4 DWORD 3, 3, 33, 3, 3, 333, 333, 333, 3, 3, 3, 333, 333, 3, 33, 3		;Yes

.code
main PROC

INVOKE FindThrees, ADDR arr1, LENGTHOF arr1
INVOKE FindThrees, ADDR arr2, LENGTHOF arr2
INVOKE FindThrees, ADDR arr3, LENGTHOF arr3
INVOKE FindThrees, ADDR arr4, LENGTHOF arr4



invoke ExitProcess,0
main ENDP

FindThrees PROC, ptrArray:PTR DWORD, arrSize:DWORD
pushad
mov esi, ptrArray
mov ecx, arrSize
L1:
mov ebx, [esi]
	.IF ebx == 3
		dec ecx
		add esi, 4
		L2:
		mov ebx, [esi]
			.IF ebx == 3
			dec ecx
			add esi, 4
			.ELSE
			add esi, 4
			loop L1
			.ENDIF
			L3:
			mov ebx, [esi]
				.IF ebx == 3
				popad
				mov eax, 1
				ret
				.ELSE
				add esi, 4
				loop L1
				.ENDIF



	.ELSE
	add esi, 4
	loop L1
	.ENDIF
popad
mov eax, 0
ret
FindThrees ENDP

END main

