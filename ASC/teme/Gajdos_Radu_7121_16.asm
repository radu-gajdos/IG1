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
    ;Ubung 16.
    a db 00111100b
    b dq 0011110000111100b
    c dd 00000000000000000000000000000000b
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;die Bits 24-31 von C sind die gleichen wie die Bits von A
        
        mov bx,[c]
        mov cx,[c+4]
        ;cx:bx=c
        mov al,[a]
        ;al=a=00111100b
        and al, 11111111b
        ;al=a => alle bits von a 
        or ch,al
        ;wir verfugen sie in die bits 31-24 aus c (weil c auf cx:bx definiert ist => bits 31-24 =ch)
        ;cx:bx = 00111100000000000000000000000000b
        
        ;die Bits 16-23 von C sind die Invertierung der Bits des niedrigsten Bytes von B
        
        mov ax,[b]
        ;ax=0011110000111100b
        not ax
        ;ax=1100001111000011b
        and ax, 0000000011111111b
        ;ax=0000000011000011b
        ;wir izolieren die niedrgisten bytes von b
        or cx,ax
        ;wir fugen sie in die bits 16-23 aus c (bits 16-23 reprezentieren cl)
        ;cx:bx=00111100110000110000000000000000b
        
        ;die Bits 10-15 von C haben den Wert 1
        
        or bx, 1111110000000000b
        ;dem wert 1 auf dem bits 15-10 aus c fugen
        ;cx:bx=00111100110000111111110000000000b
        
        ;die Bits 2-9 von C sind die gleichen wie die Bits des höchsten Bytes von B
        
        mov ax,[b]
        and ax, 1111111100000000b
        ;wir izolieren die hochsten bits aus b
        ;ax=0011110000000000b
        ror ax,6
        ;rotieren es um es richtig im bx zu fugen
        ;ax=0000000011110000b
        or bx,ax
        ;wir fuegen die hochstens bytes von b auf dem bits 2-9 von c
        ;cx:bx=00111100110000111111110011110000b
        
        ;die Bits 0-1 enthalten beide den Wert des Vorzeichenbits von A
        
        mov al,[a]
        ;al=a=00111100b
        and al, 10000000b
        ;vorzeichen bit (MSB) von a izolieren
        ;al=00000000b --- (wenn a=1011100=>al=10000000b)
        ror al,7
        ;rotieren es um es richtig im c zu fugen
        ;al=00000000b --- (wenn a=1011100=>al=00000001b)
        or bl,al
        ;wir fuegen die vorzeichen bit von a auf dem bit 0 von c
        ;bl=11110000b --- (wenn a=1011100=>al=11110001b)
        rol al,1
        ;wieder rotieren es um es richtig im c zu fugen
        ;al=00000000b --- (wenn a=1011100=>al=00000010b)
        or bl,al
        ;wir fuegen die vorzeichen bit von a auf dem bit 1 von c
        ;cx:bx=00111100110000111111110011110000b
        
        ;cx:bx=C=Ergebniss
        
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
