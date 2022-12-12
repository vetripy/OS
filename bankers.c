#include <stdio.h>

int executable(int cur, int need[5], int avail[5]){
    for(int i = 0; i < 3; i++){
        if(need[i] > avail[i])
            return 0;
    }
    return 1;
}
int main(){
    int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
                    { 2, 0, 0 }, // P1
                    { 3, 0, 2 }, // P2
                    { 2, 1, 1 }, // P3
                    { 0, 0, 2 } }; // P4

	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
					{ 3, 2, 2 }, // P1
					{ 9, 0, 2 }, // P2
					{ 2, 2, 2 }, // P3
					{ 4, 3, 3 } }; // P4


	int avail[3] = { 3, 3, 2 }; // Available Resources
    
    //need matrix
    int need[5][3] = { { 0, 0, 0 }, // P0 // MAX Matrix
					{ 0, 0, 0 }, // P1
					{ 0, 0, 0 }, // P2
					{ 0, 0, 0 }, // P3
					{ 0, 0, 0 } }; // P4
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Need matrix: \n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            printf("%d  ", need[i][j]);
        }
        printf("\n");
    }

    //bankers
    printf("available initially\n");
    for(int i = 0; i < 3; i++){
        printf("%d ", avail[i]);
    }
    printf("\n");
    int counter = 0;
    int cur = 0;
    int exe[5];
    for(int i = 0; i < 5; i++){
        exe[i] = 0;
    }
    while(counter < 5){
        printf("checking p%d\n", cur);
        int flag = 1;
        for(int i = 0; i < 3; i++){
            if(need[cur][i] > avail[i])
                flag = 0;
        }   
        if(flag && exe[cur] == 0){
            printf("available \n");
            for(int i = 0; i < 3; i++){
                avail[i] += alloc[cur][i];
            }
            for(int i = 0; i < 3; i++){
                printf("%d ", avail[i]);
            }
            printf("\n");
            exe[cur] = 1;
            counter += 1;
        }
        if(cur == 4){
            cur = 0;
        }
        else{
            cur += 1;
        }
        
    }
    return 1;
}