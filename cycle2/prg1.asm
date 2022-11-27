
.MODEL SMALL
.STACK 100H
.DATA
 

STRING DB 'AKASH', '$'
STRING1 DB 'String is palindrome', '$'
STRING2 DB 'String is not palindrome', '$'
 
.CODE
MAIN PROC FAR
 MOV AX, @DATA
 MOV DS, AX
 
 CALL Palindrome
 
 
 MOV AH, 4CH
 INT 21H
 MAIN ENDP
 Palindrome PROC
 

 MOV SI,OFFSET STRING
 

 LOOP1 :
    MOV AX, [SI]
    CMP AL, '$'
    JE LABEL1
    INC SI
    JMP LOOP1
 
 
 LABEL1 :
    MOV DI,OFFSET STRING
    DEC SI
 
    LOOP2 :
     CMP SI, DI
     JL yes_Palindrome
     MOV AX,[SI]
     MOV BX, [DI]
     CMP AL, BL
     JNE NOT_Palindrome
 
    DEC SI
    INC DI
    JMP LOOP2
 
  yes_Palindrome:
   
    LEA DX,STRING1
 
  
    MOV AH, 09H
    INT 21H
    RET
 
 NOT_Palindrome:
    
    LEA DX,STRING2
 
    
    MOV AH,09H
    INT 21H
    RET
 
Palindrome ENDP
END MAIN
