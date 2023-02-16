DATA SEGMENT 
STRING DB 100 DUP(?)
MSG1 DB 10,13,"ENTER A STRING: $"
MSG2 DB 10,13,"STRING AFTER REPLACE IS $"
MSG3 DB 10,13,"STRING TO REPLACE IS A $"
MSG4 DB 10,13,"STRING  WHICH IS REPLACED IS I $"



DATA ENDS

DISPLAY MACRO MSG
 LEA DX,MSG
 MOV AH,09
 INT 21H
ENDM

CODE SEGMENT 
   ASSUME CS:CODE,DS:DATA
   START:
    
     MOV AX, DATA
     MOV DS, AX
     MOV ES, AX
     
     DISPLAY MSG1
     LEA DI, STRING
     MOV AH,1
     
     READ:
     INT 21H
     CMP AL, 0DH
     JE ENDOFSTRING
     STOSB
     JMP READ
     
     ENDOFSTRING:
     MOV AL, "$"
     STOSB
     
      DISPLAY MSG3
      DISPLAY MSG4
     
     
     
     COUNT:
     MOV AL, STRING[BX]
     CMP AL, "$"
     JE EXIT
     CMP AL, "A"
     JE REVV 
     INC BX 
     JMP COUNT
     
     REVV:
       MOV STRING[BX],"I"
       INC BX
       JMP COUNT   
         
     EXIT:
     
     DISPLAY MSG2
     
     LEA SI, STRING
     
     PRINT:
      MOV DL,[SI]
      CMP DL,"$"
      JE OUTT
      MOV AH,02H
      INT 21H
      INC SI
      JMP PRINT
      
      
      OUTT:
      
      
     
     
     
     MOV AH,4CH
     INT 21H
     
CODE ENDS
END START
