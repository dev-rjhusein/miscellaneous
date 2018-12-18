COMMENT *
==========================================================================================
Description:
This program utilizes the Irvine x86 Assembly Language libraries.
This program recreates an 8x8 chessboard of white and gray squares.


==========================================================================================
Author : Rami Husein
Date Created : 08 / 10 / 2018
Revisions : 0
Course : CISS 360
Assignment : Week 7 Assignment 3
==========================================================================================*
include Irvine32.inc
;.386
;.model flat, stdcall
;.stack 4096
;ExitProcess proto, dwExitCode:dword

.data


.code
main PROC

	call whiteFirst
	call greyFirst
	call whiteFirst
	call greyFirst
	call whiteFirst
	call greyFirst
	call whiteFirst
	call greyFirst
	call Crlf

exit

main ENDP

greySq PROC
	mov eax, 0 + (gray * 16)
	call SetTextColor
	mov eax, 0
	mov al, ' '
	call WriteChar
	ret
greySq ENDP

whiteSq PROC
	mov eax, 0 + (white * 16)
	call SetTextColor
	mov eax, 0
	mov al, ' '
	call WriteChar
	ret

whiteSq ENDP

whiteFirst PROC
	call whiteSq
	call whiteSq

	call greySq
	call greySq

	call whiteSq
	call whiteSq

	call greySq
	call greySq

	call whiteSq
	call whiteSq

	call greySq
	call greySq

	call whiteSq
	call whiteSq

	call greySq
	call greySq
	call Crlf
	ret
whiteFirst ENDP


greyFirst PROC
	call greySq
	call greySq

	call whiteSq
	call whiteSq

	call greySq
	call greySq

	call whiteSq
	call whiteSq

	call greySq
	call greySq

	call whiteSq
	call whiteSq

	call greySq
	call greySq

	call whiteSq
	call whiteSq
	call Crlf
	ret
greyFirst ENDP


END main

