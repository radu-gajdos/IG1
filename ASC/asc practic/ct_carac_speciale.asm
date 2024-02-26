bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fread, fopen, fclose, printf               
import fread msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll 
import fclose msvcrt.dll 
import printf msvcrt.dll                          
import exit msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file_name db "Sonderzeichen.txt",0
    access_mode db "r",0 ;Datei nur für Lesen
    deskriptor dd -1
    len equ 100 ;maximale Anzahl der in einer Etappe gelesenen Elementen
    text resb len ; die Zeichenfolge, in der der Text aus der Datei gelesen wird
    format db "%d Sonderzeichen",0
    anzahl_chr dd 0 ; die Anzahl der Sonderzeichen
    anzahl_gelesenen_chr dd 0 ;die Anzahl der gelesenen Zeichen
    
; our code starts here
segment code use32 class=code
    start:
        ; die Funktion gibt den Dateideskriptor in eax oder 0 im Fehlerfall zurück
        ; eax = fopen(file_name, access_mode)
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2 ; clean-up the stack
        cmp eax, 0  ; man überprüft ob fopen die Datei erfolgreich geöffnet hat
        je ende
        mov [deskriptor], eax
        
        schleife:
        ;eax=fread(text,1,len,deskriptor)
            push dword [deskriptor]
            push dword len
            push dword 1
            push dword text 
            call [fread]
            add esp, 4*4
            
            ;eax=anzahl der gelesenen Charakter
            cmp eax,0 ; man überprüft ob die Zeichenfolge mindestens ein Charakter enthält
            je ende_file
            
            mov [anzahl_gelesenen_chr],eax ; wir speichern die Anzahl der gelesenen Zeichen
            mov ecx, eax ; man überprüft ob die Datei zur Ende gekommen ist
            mov esi, 0
            do:
                mov bl, [text+esi] ;wir lesen jedes Charakter
                cmp bl, 57 ;man überprüft ob das Charakter hat die Position kleiner als 57 in ASCII-Table
                jbe if_48_57
                cmp bl, 90 ;man überprüft ob das Charakter hat die Position kleiner als 90 in ASCII-Table
                jbe if_65_90
                cmp bl, 122 ;man überprüft ob das Charakter hat die Position kleiner als 122 in ASCII-Table
                jbe if_97_122
                
                cmp bl, 47 ;man überprüft ob das Charakter ein Sonderzeichen ist
                jbe if_inc
                cmp bl, 123 ;man überprüft ob das Charakter ein Sonderzeichen ist
                jae if_inc
                cmp bl, 64 ;man überprüft ob das Charakter ein Sonderzeichen ist
                jbe if_inc
                cmp bl, 58 ;man überprüft ob das Charakter ein Sonderzeichen ist
                jae if_inc
                cmp bl, 96 ;man überprüft ob das Charakter ein Sonderzeichen ist
                jbe if_inc
                cmp bl, 91 ;man überprüft ob das Charakter ein Sonderzeichen ist
                jae if_inc

                if_48_57:;befindet sich der Charakter zwischen den Positionen 48-57 in ASCII-Table, dann ist es eine Ziffer
                    cmp bl, 48
                    jae ende_if
                if_65_90:;befindet sich der Charakter zwischen den Positionen 65-90 in ASCII-Table, dann ist es eine grosse Buchstabe
                    cmp bl,65
                    jae ende_if
                if_97_122:;befindet sich der Charakter zwischen den Positionen 97-122 in ASCII-Table, dann ist es eine kleine Buchstabe
                    cmp bl, 97
                    jae ende_if
                if_inc:
                    inc dword[anzahl_chr];wenn es weder eine Buchstabe noch eine Ziffer ist, dann wird die Anzahl der Sonderzeichen in edx inkrementiert
                    jmp ende_if
                ende_if:
                
                inc esi
                loop do
            
            jmp schleife
            
        ende_file:
        
            push dword [deskriptor] 
            call [fclose]            ; ruft man fclose() auf, um die Datei zu schließen (deskriptor)
            add esp,4                ; clean-up the stack
            
        push dword [anzahl_chr]  
        push dword format         ;printf(format, anzahl_chr)
        call [printf]
        add esp, 4*2              ; clean-up the stack
            
        ende:
                
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program