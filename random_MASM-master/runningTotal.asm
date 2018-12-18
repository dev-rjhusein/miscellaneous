COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Aseembly Language libraries.
The program loops thrice, accepting user input of unisgned 32-bit integers, keeping a 
running total and dispalying the sum to the console when the loops breaks.

==========================================================================================
Author: Rami Husein
Date Created: 07/21/2018
Revisions: 0
Course: CISS 360
Assignment: Week 4 Assignment 1
==========================================================================================*


INCLUDE Irvine32.inc

.data

	varInt SDWORD 0
	getInput BYTE "Enter a positive number lower than two billion:", 0
	dispSum BYTE "The sum is: ", 0
		
			;// Set original coordinates to approx. the middle to the default console size 
	rows BYTE 12
	cols BYTE 29

.code
main PROC

			;//Clear The screen
	call Clrscr

			;//Set the input string to edx for WriteString call and give ecx a count of 3 for looping
	mov ecx, 3

			;//Loop for user input three times and keep a running total
L1:
	mov dh, rows
	mov dl, cols
	call Gotoxy					;Re-call to keep cursor in middle
	mov edx, OFFSET getInput
	call WriteString
	call ReadInt
	add varInt, eax				;keep running total
	inc rows					;increment rows because space is linear
	
	Loop L1

			;//Move the value to eax for WriteInt call
	mov eax, varInt


			;;;Display the sum
	mov edx, OFFSET dispSum
	call WriteString
	call WriteInt	
	call Crlf
	call WaitMsg


	exit
main ENDP
END main