COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Aseembly Language libraries.
This program takes a string of plaintext, display it, encrypts it using either ROL or ROR
depending on a positive or negative value in a 'key' array, display the encrypted string, 
then decrypts it using a similar method, but the opposite, and then dispalys the decrypted 
string.

==========================================================================================
Author : Rami Husein
Date Created : 08 / 01 / 2018
Revisions : 0
Course : CISS 360
Assignment : Week 6 Assignment 1
==========================================================================================*
INCLUDE Irvine32.inc

.data

firstStr BYTE "A big black bug bit a big black bear",0
secondStr BYTE "A man a plan a canal panama",0
key BYTE -2, 4, 1, 0, -3, 5, 2, -4, -4, 6
strPtr DWORD firstStr

index BYTE ?
again BYTE ?

.code
main PROC

;===================================== CRYPT THE FIRST STRING ===
	;Display the original string								;
mov edi, OFFSET firstStr										;
mov esi, OFFSET key												;
mov ecx, LENGTHOF key											;
call DisplayString												;
																;
																;
	;Encrypt and display the encrypted string					;
mov edi, OFFSET firstStr										;
call Encrypt													;
call DisplayString												;
																;
																;
	;Decrypt and display the decrypted string					;
mov edi, OFFSET firstStr										;
call Decrypt													;
call DisplayString												;
call Crlf														;
call Crlf														;
;================================================================


;===================================== CRYPT THE SECOND STRING ==
;Display the original string									;
mov edi, OFFSET secondStr										;
mov esi, OFFSET key												;
mov ecx, LENGTHOF key											;
call DisplayString												;
																;
																;
	;Encrypt and display the encrypted string					;
mov edi, OFFSET secondStr										;
call Encrypt													;
call DisplayString												;
																;
																;
	;Decrypt and display the decrypted string					;
mov edi, OFFSET secondStr										;
call Decrypt													;	
call DisplayString												;
;================================================================



exit
main ENDP

;=================================================
Encrypt PROC
;=================================================
push edi
mov eax, 0
mov edx, 0

forever:
mov esi, OFFSET key
mov ecx, LENGTHOF key

L1:

mov al, [edi];;;;;;;;;;;;;;;;;;;;;;;;;
mov ebx, 0		;ebx is for key
mov bl, [esi]

.IF al == 0
	jmp getOut
.ENDIF

.IF bl >= 100
	neg bl
	mov again, bl
	.WHILE again > 0
		ROL al, 1
		sub again, 1
	.ENDW

.ELSE
	mov again, bl
	.WHILE again > 0
		ROR al, 1
		sub again, 1
	.ENDW

.ENDIF
	
	mov [edi], al;;;;;;;;;;;;;;;;;;;;
	inc esi
	inc edx
	inc edi
	loop L1

jmp forever

getOut:
pop edi
ret
Encrypt ENDP
;=================================================
;=================================================




;=================================================
Decrypt PROC
;=================================================
push edi
mov eax, 0
mov edx, 0

forever:
mov esi, OFFSET key
mov ecx, LENGTHOF key

L1:

mov al, [edi];;;;;;;;;;;;;;;;;;;;;;;;;
mov ebx, 0		;ebx is for key
mov bl, [esi]

.IF al == 0
	jmp getOut
.ENDIF

.IF bl >= 100
	neg bl
	mov again, bl
	.WHILE again > 0
		ROR al, 1
		sub again, 1
	.ENDW

.ELSE
	mov again, bl
	.WHILE again > 0
		ROL al, 1
		sub again, 1
	.ENDW

.ENDIF
	
	mov [edi], al;;;;;;;;;;;;;;;;;;;;
	inc esi
	inc edx
	inc edi
	loop L1

jmp forever

getOut:
pop edi
ret
Decrypt ENDP
;=================================================
;=================================================



;=================================================
DisplayString PROC
;=================================================
mov edx, edi
call WriteString
call Crlf

ret
DisplayString ENDP
;=================================================
;=================================================

END main