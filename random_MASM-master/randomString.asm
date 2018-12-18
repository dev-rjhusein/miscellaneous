COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Aseembly Language libraries.
The program allows a user to input a length of a desired random string. It passed the length 
to a defined procedure that generates a random integer within the Captial Letter Ascii values
and appends it to a string. When the entire string has been appended, it uses the Irvine library
to display the string to the console. Per requirements, the program loops 20 times.

==========================================================================================
Author : Rami Husein
Date Created : 07 / 22 / 2018
Revisions : 0
Course : CISS 360
Assignment : Week 4 Assignment 2
==========================================================================================*
INCLUDE Irvine32.inc

.data
loopTwenty DWORD 6		;Number of times to loop program
getInput BYTE "Enter a number between 1 and 50, please:", 0
charString BYTE 50 DUP (?)			;Allocate some memory for a string (SAFE string max is 50 chars)

.code
;;;;;;;;;;;;;;;;;;;;;;;;;; MAIN FUNCTION;;;;;;;;;;;;;;;;;;;;;;
main PROC


mov ecx, loopTwenty
L1:

		;Get user input of string length
mov edx, OFFSET getInput
call Crlf
call WriteString
call ReadInt

		;Use Procedure to generate and display the random string
call StringGen
sub loopTwenty, 1
mov ecx, loopTwenty
loop L1


call Crlf
exit
main ENDP


;;;;;;;;;;;;;;;;;;;;;;;;;; String Generator FUNCTION;;;;;;;;;;;;;;;;;;;;;;
StringGen proc
mov esi, OFFSET charString
mov ecx, eax

L1 :
		;Generate an ascii capital letter value
mov eax, 25
call RandomRange
add eax, 65

		;Append that value to the "String"
mov [esi], al
inc esi
		;Loop given number of times
	loop L1


		;Print the string
mov ecx, LENGTHOF charString
mov edx, OFFSET charString
call WriteString
mov edx, 0
ret
StringGen endp


END main