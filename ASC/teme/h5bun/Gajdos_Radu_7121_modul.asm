bits 32 
global start       
 
extern exit, scanf, printf               
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll

global arr
global formatout
global message
global formatin
global blank

;global variabeln deklariert

extern subp

;extern fuer dem subp aus functions.asm

segment data use32 class=data
        
        arr dd 0                      ; liste initializieren
        formatin db "%x", 0           ; format hexa input
        formatout db "%d", 0          ; format deci output
        message db "arr = ", 0        ; message input
        blank db "%c",0
        
segment code use32 class=code
    start:
            
            push dword message
            call [printf]
            add esp, 4*1
            
            ; arr schreiben
            
            call subp ;subp apelieren
        
        push    dword 0      
        call    [exit]