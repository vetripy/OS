#include<stdio.h>
#include<stdlib.h>

int mutex = 0, item_no = 0, buffer[10], empty = 10, full = 0;
//1 means lock aquired

void Wait(int *semaphore){
    *semaphore -= 1;
}

void Signal(int *semaphore){
    *semaphore += 1;
}

void producer(){
    Wait(&mutex);
    if(full != 10){
        full++;
        empty--;
        item_no ++;
        printf("item %d produced\n", item_no);
        
    }
    else{
        printf("buffer is full\n");
    }
    Signal(&mutex);
}

void consumer(){
    Wait(&mutex);
    if(empty != 10){
        full--;
        empty++;
        printf("item %d consumed\n", item_no);
        item_no--;
    }
    else{
        printf("buffer is empty\n");
    }
    Signal(&mutex);
}

int main(){
    int n, random;
    printf("enter the number of iterations: ");
    scanf("%d", &n);
    printf("\n");
    for(int i = 0; i < n; i++){
        random = rand()%100 + 1;
        if(random % 2 == 0){
            if(mutex != 1)
                producer();
        }
        else{
            if(mutex != 1)
                consumer();
        }
    }
    return 1;
}