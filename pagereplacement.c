//fifo
#include <stdio.h>
#include <stdlib.h>

int main(){
    int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
    int pno = 22;
    int fno = 3;
    int frames[] = {-1, -1, -1};
    int hit, cur = 0, pfault = 0;

    for(int i = 0; i < pno; i++){
        hit = 0;
        for(int j = 0; j < fno; j++){
            if(frames[j] == pages[i]){
                printf("Hit\n");
                hit = 1;
            }
        }
        if(!hit){
            frames[cur] = pages[i];
            printf("page fault\n");
            pfault++;
            cur = (cur + 1) % fno;
        }
    }
    printf("%d \n", pfault);
    return 1;
}//lru
#include <stdio.h>

int main(){
    int pno = 22, fno = 3;
    int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
    int frames[] = {-1, -1, -1};
    int cache[] = {-1, -1, -1};
    int pfault = 0, hit, index;
    for(int i = 0; i < pno; i++){
        hit = 0;
        for(int j = 0; j < fno; j++ ){
            if(frames[j] == pages[i]){
                hit = 1;
            }
        }
        if(hit){
            for(int k = 0; k < fno; k++){
                if(cache[k] == pages[i]){
                    index = k;
                }
            }
            //rearrange cache
            int temp = cache[index];
            index++;
            while(index < fno){
                cache[index - 1] = cache[index];
                index++;
            }
            cache[index - 1] = temp;
            printf("hit \n");
        }
        
        if(!hit){
            for(int i = 0; i < fno; i++){
                if(frames[i] == cache[0]){
                    index = i;
                    break;
                }
            }
            //replace least recently used
            frames[index] = pages[i];
            //update cache
            index = 1;
            while(index < fno){
                cache[index - 1] = cache[index];
                index++;
            }
            cache[index - 1] = pages[i];
            printf("page fault\n");
            pfault++;
        }
    }
    printf("No of page fautls = %d \n", pfault);
    return 1;
}

//optimal
#include <stdio.h>

int main(){
    int pno = 22, fno = 3;
    int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
    int frames[] = {-1, -1, -1};
    int cache[] = {-1, -1, -1};
    int pfault = 0, hit, index, temp;
    int cur = 0;
    for(int i = 0; i < pno; i++){
        hit = 0;
        if(frames[cur] == -1){
            frames[cur] = pages[i];
            cur = (cur  + 1) % 3;
            printf("page fault\n");
            pfault++;
        }
        else{
            for(int j = 0; j < fno; j++ ){
                if(frames[j] == pages[i]){
                    hit = 1;
                }
            }
            
            if(hit){
                for(int k = 0; k < fno; k++){
                    if(cache[k] == pages[i]){
                        index = k;
                    }
                }
                printf("hit \n");
            }
            
            if(!hit){
                //copy frames to cache
                for(int i = 0; i < fno; i++){
                    cache[i] = frames[i];
                }
                //delete next 2 upcoming page nos
                int k = i + 1;
                int counter = 1;
                //make the index in cache -1 if they upcoming
                while(counter < 3){
                    for(int j = 0; j < fno; j++){
                        if(cache[j] == pages[k]){
                            cache[j] = -1;
                            counter++;
                        }
                    }
                    k++;
                }
                //find the element to replace
                for(int j = 0; j < fno; j++){
                    if(cache[j] != -1){
                        temp = cache[j];
                    }
                }
                //replace it
                for(int j = 0; j < fno; j++){
                    if(frames[j] == temp){
                        frames[j] = pages[i];
                    }
                }
                
                printf("page fault\n");
                pfault++;
            }
        }
        printf("%d %d %d \n", frames[0], frames[1], frames[2]);
    }
    printf("No of page fautls = %d \n", pfault);
    return 1;
}

