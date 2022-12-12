#include <stdio.h>

struct process{
    int pid, id;
    int at, bt;
    int rt; //remaining time
    int ct; //completion time
    int ta; //ta = ct - at
    int wt; //waiting time = ta - bt
};

void srtf(struct process p[], int n){
    int counter = 0;
    int cur_t = 0;
    while(counter < n){
        int val_process[10] = {0,0,0,0,0,0,0,0,0,0}, vp = 0;
        for(int i = 0; i < n; i++){
            if(p[i].at <= cur_t && p[i].rt){
                val_process[vp] = i;
                vp++;
            }
        }
        int mini = 0;
        for(int i = 1; val_process[i]; i++){
            if(p[val_process[i]].rt < p[val_process[mini]].rt){
                mini = i;
            }
        }
        printf("%d ", p[val_process[mini]].pid);
        p[val_process[mini]].rt -= 1;
        if(p[val_process[mini]].rt == 0){
            counter++;
        }
        cur_t++;
    }
    printf("\n");
}
int main()
{
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
    printf("hi\n");
    srtf(p, n);
    return 1;
}