#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define BUFFER_SIZE 256
#define INVALID_INPUT -1.0

char transformaNota(float nota_initiala){
    if(nota_initiala>=90.00){
        return 'A';
    }else if(nota_initiala<90.00 && nota_initiala>=80){
        return 'B';
    }else if(nota_initiala<80.00 && nota_initiala>=70){
        return 'C';
    }else if(nota_initiala<70.00 && nota_initiala>=60){
        return 'D';
    }else if(nota_initiala<60.00){
        return 'F';
    }
}


int main() {
    int fd1[2], fd2[2];

    pipe(fd1);
    pipe(fd2);

    pid_t pid = fork();

    if (pid > 0) {//client
        close(fd1[READ]);
        close(fd2[WRITE]);

        char buffer[BUFFER_SIZE];
        float nota_initiala;
        char nota_finala;
        char *endptr;

        printf("Input: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        nota_initiala = strtof(buffer, &endptr);

        write(fd1[WRITE], &nota_initiala, sizeof(nota_initiala));

        int status;
        read(fd2[READ], &nota_finala, sizeof(nota_finala));
        read(fd2[READ], &status, sizeof(status));

        if(status == 0) {
            printf("Client: Received from server: Bitte einem Zahl zwischen 0.00 und 100.00 angeben.\n");
        } else {
            printf("Client: Empfang vom Server: Deine Note ist : %c \n", nota_finala);
        }

        close(fd1[WRITE]);
        close(fd2[READ]);
    } else if (pid == 0) {//server

        close(fd1[WRITE]);
        close(fd2[READ]);

        float nota_initiala;
        int status = 1;

        read(fd1[READ], &nota_initiala, sizeof(nota_initiala));

        if(nota_initiala<0.00 || nota_initiala>100.00) {
            printf("Server: Invalider input\n");
            status = 0;
            write(fd2[WRITE], &status, sizeof(status));
            exit(1);
        }

        char nota_finala=transformaNota(nota_initiala);
        if(status==1){
            printf("Server: %c \n", nota_finala);
        }

        write(fd2[WRITE], &nota_finala, sizeof(nota_finala));

        close(fd1[READ]);
        close(fd2[WRITE]);
    } else {
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}