bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 3;a=2
    b dd 11;b=500
    c db 6;c=2
    x dq 1000;x=1000
    
    ;x-(a*a+b)/(a+c/a)
    
    ;Fur a=3,b=11,c=6,x=1000
    ;1000-(3*3+11)/(3+6/3)
    ;1000-(9+11)/(3+2)
    ;1000-(20)/(5)
    ;1000-4
    ;996
; our code starts here
segment code use32 class=code
    start:
    
        mov al,[c];al=c
        mov ah,0;vorzeichenlose Umwandlung al->ax
        div byte [a];al=c/a
        add al,[a];al=a+c/a
        
        mov bl,al ;bl=al
        mov bh,0 ;vorzeichenlose Umwandlung bl->bx
        ;bx=(a+c/a)
        
        mov al,[a] ;al=a
        mul al ;al=a*a
        mov ah,0 ;vorzeichenlose Umwandlung al->ax
        add ax,[b] ;ax=a*a+b
        mov dx,0 ;vorzeichenlose Umwandlung ax->dx:ax
        ;dx:ax=(a*a+b)
        
        div bx ;dx:ax=(dx:ax / bx)= ((a*a+b)/(a+c/a))
        mov ebx,0;ebx=0 (so dass register am anfang 0 ist)
        mov bx,ax
        mov cx,dx
        ;ebx:ecx=dx:ax=(dx:ax / bx)= ((a*a+b)/(a+c/a))
        
        mov eax,[x+0]
        mov edx,[x+4]
        ;eax:edx=x
        
        sub eax, ebx;eax:edx=c-(a*a+b)/(a+c/a)
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
