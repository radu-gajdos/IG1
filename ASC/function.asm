bits 32
global subp
extern start
extern exit


extern sir
extern format1
extern format2
extern spatiu

extern printf
import printf msvcrt.dll

segment code use32 class=code public

subp:   
    mov eax, [sir]
    push dword eax
    push dword format1
    call [printf]
    add esp, 4*2
    
    mov eax, " "
    push dword eax
    push dword spatiu
    call [printf]
    add esp, 4*2
    
    mov eax, [sir]
    push dword eax
    push dword format2
    call [printf]
    add esp, 4*2
    
    ret