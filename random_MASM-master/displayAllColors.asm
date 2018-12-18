COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Aseembly Language libraries.
The program loops 256 times, each time using the value of register ECX to call the
"SetTextColor" procedure from the Irvine Library. The program display every possible
color combintion (foreground/background) that the console allows.

==========================================================================================
Author : Rami Husein
Date Created : 07 / 23 / 2018
Revisions : 0
Course : CISS 360
Assignment : Week 4 Assignment 3
==========================================================================================*
INCLUDE Irvine32.inc

.data

oneNum DWORD "1", 0

.code
main PROC

mov ecx, 256				;It said I CAN use a nested loop, not that I HAD to.
mov edx, OFFSET oneNum		;Char to print

L1:
	dec ecx					;dec ecx to account for 0 (zero)
	mov eax, ecx			;set eax for SetTextColor call
	inc ecx					;Reset ecx to normal value
	call SetTextColor
	call WriteString
	
	loop L1



main ENDP

END main