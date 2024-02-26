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
    a dw 0000111100001111b
    b dw 1111000011110000b
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        mov cx,0
        mov bx,0
        
        ;die Bits 0-3 von C sind diegleichen wie die Bits 5-8 von B
        
        
        mov ax,[b]
        ;ax=   1111000011110000b
        and ax,0000000111100000b
        ;wir izolieren die bits 5-8 aus b
        ;ax=   0000000011100000b
        ror ax,5
        ;rotieren es um es richtig im bx zu fugen
        ;ax=   0000000000000111b
        or bx,ax ;wir fuegen die bits 5-8 von a auf die bits 0-3 von bx 
        ;bx=   0000000000000111b
        ;cx:bx=00000000000000000000000000000111b
        
        ;die Bits 4-8 von C sind die gleichen wie die Bits 0-4 von A
        
        mov ax,[a]
        ;ax=   0000111100001111b
        and ax,0000000000011111b
        ;wir izolieren die bits 0-4 aus a
        ;ax=   0000000000001111b
        rol ax,4
        ;rotieren es um es richtig im bx zu fugen
        ;ax=   0000000011110000b
        or bx,ax ;wir fuegen die bits 0-4 von a auf die bits 4-8 von bx 
        ;bx=   0000000011110111b
        ;cx:bx=00000000000000000000000011110111b
        
        ;die Bits 9-15 von C sind die gleichen wie die Bits 6-12 von A
         
        mov ax,[a]
        ;ax=   0000111100001111b
        and ax,0001111111000000b
        ;wir izolieren die bits 6-12 aus a
        ;ax=   0000111100000000b
        rol ax,3
        ;rotieren es um es richtig im bx zu fugen
        ;ax=   0111100000000000b
        or bx,ax ;wir fuegen die bits 6-12 von a auf die bits 9-15 von bx 
        ;bx=   0111100011110111b
        ;cx:bx=00000000000000000111100011110111b
        
        ;die Bits 16-31 von C sind die gleichen wie die Bits von B
        mov ax,[b]
        ;wir izolieren alle bits von b in ax
        ;ax=   1111000011110000b
        or cx,ax
        ;wir fuegen alle bits von b in cx 
        ;cx=   1111000011110000b
        ;cx:bx=11110000111100000111100011110111b
        
        ;cx:bx=C=Ergebniss
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
