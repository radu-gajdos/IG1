#include <stdio.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {//verifica parametrii
        printf("Trebuie sa dai numele fisierului! (si numai numele fiserului)");
        return 0;
    }

    FILE *file = fopen(argv[1], "r");//deschide cu read

    if (file == NULL) {//daca nu sa deschis
        printf("Fisierul nu sa deschis!");
        return 0;
    }

    char c;

    while ((c = fgetc(file)) != EOF) {//fiecare caracter
        printf("%c",c);//scriw fiecare caracer
        if (c=='\n'){//daca caracterul ii \n
           printf("\n");//mai pune un \n
        }
    }

    fclose(file);//inchide fisierul
    return 0;
}