bits 32

global subp

;dem subp als global deklarieren


extern start
extern exit


extern arr
extern formatin
extern formatout
extern blank

; hinzufuegen der variabeln aus modul.asm

extern printf
extern scanf
import printf msvcrt.dll
import scanf msvcrt.dll

segment code use32 class=code public

subp:   
    repeta:
    
            push dword arr
            push dword formatin
            call [scanf]
            add esp, 4*2
            
            ; in arr Zahl im hex tun
            
            
            mov eax, [arr]
            push dword eax
            push dword formatout
            call [printf]
            add esp, 4*2
            
            ; 10 Basis schreiben
            
            mov eax, " "
            push dword eax
            push dword blank
            call [printf]
            add esp, 4*2
            
            ;blank also " " schreiben
            
            jmp repeta
            
            ret