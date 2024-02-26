bits 32

global start

extern exit, printf, scanf, fopen, fclose, fread

import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll 
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll


segment data use32 class=data
    nume_fisier db "input.txt", 0
    mod_acces db "r", 0
    descriptor_fis dd -1
    nr_car_citite dd 0
    len equ 100
    buffer resb len
    
    format db "Maximal ist das Ziffer %d mit der Frequenz %d", 0
    
    frequenz db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ; Frequenz des Ziffer Reiche
    lenf equ $-frequenz
    maxf db 0
    maxz dd 0
    

segment code use32 class=code
    start:
        push dword mod_acces ; "read"
        push dword nume_fisier
        call [fopen]
        add esp, 4*2 ; Bereinigung der Parameter vom Stack
        cmp eax, 0 ; Prüfen Sie, ob "input.txt" existiert
        je end 
        mov [descriptor_fis], eax  ; die Adresse
        
        bucla:  ; Wir können nicht die gesamte Datei auf einmal lesen, deshalb lesen wir 100 Zeichen auf einmal
            push dword [descriptor_fis]
            push dword len
            push dword 1
            push dword buffer ; Hier setzen wir die gelesenen Zeichen
            call [fread]
            add esp, 4*4
            
            cmp eax, 0
            je cleanup  ; Wenn es keine Zeichen zu lessen gibt, es Fertig ist
            mov [nr_car_citite], eax
            ; --
                mov ecx, [nr_car_citite]
                mov esi, 0
                repeat:
                    mov al, [buffer+esi] ; Prüfen Sie, ob das Zeichen eine Ziffer ist
                    cmp al, 0x30
                    jl next
                    cmp al, 0x39
                    jg next ; muss die Hex Code zwischen 30 und 39 haben / oder in Decimal 48-57
                    
                    mov eax, 0
                    mov al, [buffer+esi]
                    mov bl, 48
                    sub al, bl  ; transformieren aus hex code zum Ziffer
                    
                    ;Frequenz Reiche
                    mov bl, [frequenz+eax] 
                    inc bl  
                    mov [frequenz+eax], bl ; Wenn wir eine Ziffer lessen, inc die Ziffer Frequenz
                    
                    next:
                    inc esi ; esi += 1
                    
                    loop repeat
            ; -- 
            jmp bucla
            
        cleanup:
            push dword [descriptor_fis]
            call [fclose] ; Wir schließen die Datei
            add esp, 4 ; Bereinigung der Parameter vom Stack
            
        ; Wir brauchen die Datei nicht mehr
        ; Wir brauchen nur die Reiche Frequenz
        
        mov ecx, lenf ; Wir nehmen die len der Reiche Frequenz
        jecxz end
        mov esi, 0
        repetation:
            mov al, [frequenz+esi]
            mov bl, [maxf]
            cmp al, bl ; Wir vergleichen die aktuelle Ziffernfrequenz mit dem Maximum
            jle kleiner ; frequenz kleiner oder egal als maximal
            ; wenn es grosser ist
            mov [maxf], al
            mov [maxz], esi
            kleiner:
            inc esi
        loop repetation
        
        ; print
        mov esi, [maxz]
        mov eax, 0
        mov al, [frequenz+esi]
        push eax
        push esi
        push format
        call [printf] ; Wir zeigen die Ergebnis auf dem Bildschrim
        add esp, 4*3
        
        end:
        ; end
        push dword 0
        call [exit]