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

TRUE = 1
FALSE = 0
OkToRegister BYTE ?


gradeAverage WORD 275
credits WORD 12

getCredits BYTE "Please enter the student's credits (1 - 30): ", 0
getAverage BYTE "Please enter the student's grade average: ", 0

badCredits BYTE "That is not a valid credits entry. Please enter between 1 and 30.", 0

goodToGo BYTE "The student can register", 0
notReady BYTE "The student cannot register", 0

.code
main PROC



mov ecx, 1

;;;Get and check user input
@C0002:
	mov edx, OFFSET getCredits 
	call WriteString  
	call ReadInt 
	mov credits, ax

	;;;If (credits < 1) || (credit > 30)
    cmp word ptr credits,1  
    jb @C0001  
    cmp word ptr credits,30  
    jae @C0001
    jmp @C0003
    @C0001:
		mov edx, OFFSET badCredits 
		call WriteString  
		call Crlf
		inc ecx
		jmp @C0002

@C0003:
;;;Get average input without checking
mov edx, OFFSET getAverage  
call WriteString  
call ReadInt
mov gradeAverage, ax 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

mov OkToRegister, FALSE 

;;;Check and set OkToRegister

;;; If gradeAverage > 350
cmp word ptr gradeAverage,350  
jbe @C0004
jmp @C0006


;;; Else, If (gradeAverage > 250) && (credits <= 16) 
@C0004:
    cmp word ptr gradeAverage,250  
    jbe @C0005  
    cmp word ptr credits,16  
    ja @C0005
    jmp @C0006  


;;; Else, If (credits <= 12) 
@C0005:
    cmp word ptr credits,12  
    ja @C0007



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;; Display answer

;;;If OkToRegister is true
@C0006:
    mov edx, OFFSET goodToGo  
    call WriteString  
    call Crlf 
    jmp @C0008  

;;;If OkToRegister is false
@C0007:
    cmp byte ptr OkToRegister, FALSE   
    mov edx, OFFSET notReady
    call WriteString
    call Crlf

@C0008:

exit
push 0  

exit
main ENDP
END main