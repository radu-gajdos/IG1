bits 32 
global start       
 
extern exit, scanf, printf               
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll

global sir
global format1
global format2
global spatiu

extern subp

segment data use32 class=data public
        
        sir dd 0                    ; array initialised with 0
        message db "sir = ", 0      ; message which will be printed before the array gets its input
        format db "%x", 0           ; format for values (base 16)
        format1 db "%u", 0          ; format for unsigned integer
        format2 db "%d", 0          ; format for signed integer
        spatiu db "%c", 0
        
segment code use32 class=code public
    start:
            
            push dword message
            call [printf]
            add esp, 4*1
            
            push dword sir
            push dword format
            call [scanf]
            add esp, 4*2
            
            call subp
        
        push    dword 0      
        call    [exit]