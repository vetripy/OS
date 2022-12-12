#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
    int shmid = shmget(2000, 1024, 0666|IPC_CREAT);
    char * sh_mem = shmat(shmid, NULL, 0);
    char * ptr;
    ptr = sh_mem;
    for(char c='a';c<='z';c++)
        *ptr++=c;
    shmdt(sh_mem);
    return 1;
}

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
    int shmid = shmget(2000, 1024, 0666);
    char * sh_mem = shmat(shmid, NULL, 0);
    
    printf("%s \n", (char *)sh_mem);
    shmdt(sh_mem);
    shmctl(shmid, IPC_RMID, NULL);
    return 1;
}