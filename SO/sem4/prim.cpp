#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int fd, n;
    char c[2];
    fd=open("a", O_RDWR);

    while(read(fd,c,1)){
        if(c[0]=='E'){
            c[0]='e';
            lseek(fd,-1,SEEK_CUR);
            write(fd,c,1);
        }
    }

}
