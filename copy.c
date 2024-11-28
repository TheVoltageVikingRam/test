#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void fileCopy(int f1, int f2);

int main(int argc, char *argv[])
{
    if (argc!=3)
    {
        printf("\n file not found!! \n");
        exit(1);
    }
    
    int fd1 = open(argv[1],0);
    if (fd1 == -1)
    {
        printf("\n error in file opening \n");
        exit(1);
    }
    int fd2 = creat(argv[2],0666);
    if (fd2 == -1)
    {
        printf("\n error in file creating \n");
        exit(1);
    }
    
    fileCopy(fd1,fd2);
    close(fd1);
    close(fd2);
    
    return 0;
}


void fileCopy(int f1, int f2)
{
    char buf[512];
    int cnt;
    while (cnt = read(f1, buf, sizeof(buf)))
    {
        write(f2, buf, cnt);
    }
}
