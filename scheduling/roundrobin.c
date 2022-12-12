#include <stdio.h>

struct process{
    int pid, id;
    int at, bt;
    int rt; //remaining time
    int ct; //completion time
    int ta; //ta = ct - at
    int wt; //waiting time = ta - bt
};

void rr(struct process p[], int n, int tq){
    int ghantt[30];
    int counter = 0; //no of processes completed
    int i = 0; //current process executing
    int cur_t = 0, g = 0;
    //g iterator for ghantt
    while(counter < n){
        if(p[i].rt <= tq && p[i].rt > 0){
            printf("s\n");
            
            cur_t = cur_t + p[i].rt;
            ghantt[g] = i; printf("%d ", p[i].pid); g++;
            ghantt[g] = cur_t; printf("%d\n", cur_t); g++;
            p[i].ct = cur_t;
            p[i].rt = 0;
            counter += 1;
        }
        else if(p[i].rt > tq){
            printf("l\n");
            cur_t += tq;
            p[i].rt -= tq;
            ghantt[g] = i; printf("%d ", p[i].pid); g++;
            ghantt[g] = cur_t; printf("%d\n", cur_t); g++;

        }
        if(i == n - 1){
            i = 0;
        }
        else if(p[i + 1].at <= cur_t){  
            i++;
        }
        else{
            i = 0;
        }
    }
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[10];
    for(int i = 0; i < n; i++){
        printf("\nEnter process id: ");
        scanf("%d", &p[i].pid);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    }
    int tq;
    printf("\nEnter time quantum: ");
    scanf("%d", &tq);
    rr(p, n, tq);
    
    return 1;
}