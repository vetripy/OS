#include<stdio.h>
#include<stdlib.h>

int chopsticks[5] = {0};

void Wait(int *s){
    *s -= 1;
}

void Signal(int *s){
    *s += 1;
}

void philosopher(int p){
    Wait(&chopsticks[p]);
    Wait(&chopsticks[(p + 1) % 5]);
    printf("philosopher %d is eating\n", p);
    Signal(&chopsticks[p]);
    Signal(&chopsticks[(p + 1) % 5]);
    printf("philosopher %d is thinking\n", p);
}

int main(){
    int n, random;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        random = rand() % 10 + 1;
        random = random % 5;
        philosopher(random);
    }
    return 1;
}