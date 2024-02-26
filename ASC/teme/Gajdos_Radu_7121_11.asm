bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a dd 100;a=100
    b db 4;b=4
    c db 2;c=2
    x dq 2;x=2
    
    ;(a+b)/(2-b*b+b/c)-x
    ;(104)/(2-16+2)-2
    ;(104/-16)-2
    ;(-6)-2
    ;-8
    
    ;Ergebnis wird in eax:edx gespeichert
    
; our code starts hereQ\\
segment code use32 class=code
    start:
        ; ...
        
        mov dl,2;dl=2
        mov al,[b];al=b
        cbw;al zu ax konvertieren // al->ax
        imul byte [b];ax=b*b
        mov bx,ax;bx=ax=b*b // ax zu befreien um es wieder zu benutzen 
        mov al,[b];al=b
        cbw;al zu ax konvertieren // al->ax
        idiv byte [c];ax=b/c
        add ax,bx;ax=ax*bx=(b*b)+(b/c)
        mov cx,ax;cx=ax=(b*b)+(b/c) // ax zu befreien um es wieder zu benutzen 
        mov ax,2;ax=2
        sub ax,cx;ax=ax-cx=2-(b*b)+(b/c)
        mov cx,ax;cx=ax=2-(b*b)+(b/c) // ax zu befreien um es wieder zu benutzen 
        
        mov ebx,[a];ebx=a
        mov al,[b];al=b
        cbw;al zu ax konvertieren // al->ax
        cwd;ax zu eax konvertieren // ax->eax
        add eax,ebx;eax=eax-ebx=b+a=a+b
        
        idiv cx;eax=eax/cx=(a+b)/(2-(b*b)+(b/c))
        cdq;eax zu eax:edx konvertieren // eax->eax:edx
        sub eax,[x];eax:edx=eax:edx-x=(a+b)/(2-(b*b)+(b/c))-x
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
