bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, fopen,fclose, fprintf        
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll    
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

; The following code will open/create a file called "ana.txt" in the current folder, and it will write a text at the end of this file.
; The program will use:
; - the function fopen() to open/create the file
; - the function fprintf() to write a text to file
; - the function fclose() to close the created file.
; Because the fopen() call uses the file access mode "a", the writing operations will append text at the end of the file. The file will be created if it does not exist.

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    text db "Ana are si pere.", 0 ; text to append to file
    len EQU $-text ; lenght of 'text'
    format db "%s",0 ; we will need a string (%d)
    file_name db "Aufgabe_9.txt", 0 ; filename to be read
    access_mode db "a", 0 ; file access mode: "a" => append text at the end of the file
    file_descriptor dd -1 ; variable to hold the file descriptor

; our code starts here
segment code use32 class=code
    start:
        mov ecx,len
        mov esi, 0
        sub ecx , 1 ; we don't need the 0 at the end
        cmp ecx,0 ; we verify if 'text' contains any characters
        je final
        mov bl, 'X'
        while:
            cmp esi,ecx ; compare esi and ecx (index!= len(text))
            je endwhile ; the 'while' goes on as long as esi!= ecx ( as long as we have unverified elements in our 'text' ) 
            mov al,[text + esi] ; each character of 'text' is a byte ; al => the character from text+esi address
            inc esi ; incrementing esi
            
            ; checking if our character is a number or not (verify if character is between '0' and '9')
            
                    ; in case it isn't, go to label not_number
                    ; in case it is, go to the while label => move on to the next character 
                    
            cmp al,'0' 
            jl not_number 
            cmp al,'9'
            jg not_number
            jmp while
            
            not_number:
            
                ; checking if our character is a lowercase letter or not (verify if character is between 'a' and 'z')
            
                    ; in case it isn't, go to label not_lowercase_letter
                    ; in case it is, go to the while label => move on to the next character 
            
                cmp al,'a'
                jl not_lowercase_letter
                cmp al,'z'
                jg not_lowercase_letter
                jmp while
                
            not_lowercase_letter:
            
                ; checking if our character is an uppercase letter or not (verify if character is between 'A' and 'Z')
            
                    ; in case it isn't, go to label not_uppercase_letter
                    ; in case it is, go to the while label => move on to the next character 
            
                cmp al,'A'
                jl not_uppercase_letter
                cmp al,'Z'
                jg not_uppercase_letter
                jmp while
                
            not_uppercase_letter:
                
                ; we know now that our character is not a number, not an uppercase or lowercase letter and that means that our char is a special char
            
                mov [text + esi - 1], bl ; change the character to 'X'
                
            jmp while 
        endwhile:
        
            ; call fopen() to create the file
            ; fopen() will return a file descriptor in the EAX or 0 in case of error
            ; eax = fopen(file_name, access_mode)

                    
            ;push dword text
            ;push dword format
            ;call [printf]
            ;add esp, 4*2
            
            push dword access_mode
            push dword file_name
            call [fopen]
            add esp, 4*2 ; clean-up the stack
            mov [file_descriptor], eax ; store the file descriptor returned by fopen
            
            ; check if fopen() has successfully created the file
            cmp eax, 0
            je final
            ; append the text to file using fprintf()
            ; fprintf(file_descriptor, text)
            push dword text
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*2
            ; call fclose() to close the file
            ; fclose(file_descriptor)
            push dword [file_descriptor]
            call [fclose]
            add esp, 4
            
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
