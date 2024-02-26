111
segment data use32 class=data

    file_name db "output.txt", 0   ; filename to be created
    access_mode db "w", 0       ; file access mode:; w - creates an empty filefor writing
    file_descriptor dd -1       ; variable to hold the file
    
    arr dd 0                      ; liste initializieren
    format db "%d", 0          ; format deci output
    format_text db "%s", 0          ; format deci output
    message db "arr = ", 0        ; message input
    blank db "%c",0
    trei db 3
    arr_nou dd 0
    sem db 0
    message_no db "Keine Zahl"
    
segment code use32 class=code
    start:
    
        push dword access_mode
        push dword file_name
        call [fopen]
        ;file oeffnen
        add esp, 4*2 ;Stack waschen
        
        mov [file_descriptor], eax ; store the filedescriptor returned by fopen
        cmp eax, 0
        je final                   ;wenn dem file nicht korrekt gebildet oder geoeffnet war -> final
        
        mov ecx,0
        push dword message
        call [printf]
        add esp, 4*1
        
        repeta:
            
            push dword arr
            push dword format
            call [scanf]
            add esp, 4*2
            
            
            ; in arr Zahl im hex tun
            mov ebx,[arr]
            cmp ebx,0
            je final
            ;bei 0 stoppen
            
            
            mov eax,[arr]
            div byte [trei]
            cmp ah,0
            jne repeta
            
            mov eax,ebx
            mov dh,0
            mov dl,1
            div_trei:
            
            mov ecx,1
            mov [sem],ecx
            
            push dword ebx
            push dword format
            call [printf]
            add esp, 4*2
            
            push dword ebx
            push dword format
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*2
            
            jmp repeta

        final:
        
        cmp byte [sem],0
        jne gata
        push dword message_no
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4*2
        
    
        gata:
    ; exit(0)
    push    dword 0      ; push the parameter for exit onto the stack
    call    [exit]       ; call exit to terminate the program