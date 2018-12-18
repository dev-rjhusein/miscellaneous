COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Aseembly Language libraries.
The program prompts a user for credits and grade average integers. It checks 

==========================================================================================
Author : Rami Husein
Date Created : 07 / 28 / 2018
Revisions : 0
Course : CISS 360
Assignment : Week 5 Assignment 2
==========================================================================================*
INCLUDE Irvine32.inc

.data
menu BYTE "1. x AND y", "2. x OR y", "3. NOT x", "4. x XOR y", "5. Exit program", 0


.code
main PROC







exit
main ENDP



DisplayMenu PROC
mov ecx, LENGTHOF menu
L1: 
    mov edx, OFFSET menu
    call WriteString
loop L1

ret

DisplayMenu ENDP


END main