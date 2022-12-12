#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int frame_size,paddr_size,page_size,laddr_size,n_page,n_frame;
	int allocation[15],pgtable[15],strt_addr[15];
	time_t t;
	int temp,r,laddr,paddr,add,pageno,offset,ne,k,q=0;
	
	
	printf("Enter the size of physical address :\n");
	scanf("%d",&paddr_size);
	
	printf("Enter the size of logical address :\n");
	scanf("%d",&laddr_size);
	
	printf("Enter the size of a page :\n");
	scanf("%d",&page_size);
	
	frame_size = page_size;
	n_page = laddr_size/page_size;
	n_frame = paddr_size/frame_size;
	
	for(int i=0;i<n_frame;i++){
		allocation[i] = -1;
	}
	strt_addr[q] = 4000;
	
	for(int y =0;y<n_frame;y++){
		temp = strt_addr[q] + page_size;
		strt_addr[++q] = temp;
	}
	
	printf("\nBefore Allocation :");
	printf("\nFrame no\tPage no\tStarting address");
	for(int i=0;i<n_frame;i++){
		printf("\n%d\t\t%d\t\t%d",i,allocation[i],strt_addr[i]);
	}
	srand((unsigned) time(&t));
	k =0;
	for(int i=0;i<n_page;i++){
		r = rand()%n_frame;
		while(allocation[r]!= -1){
			r =rand()%n_frame;
		}
		allocation[r] = k;
		k++;
		pgtable[i] = r;
	}
	
	printf("\nAfter Allocation :");
	printf("\nFrame no\tPage no\tStarting address");
	for(int i=0;i<n_frame;i++){
		printf("\n%d\t\t%d\t\t%d",i,allocation[i],strt_addr[i]);
	}
	
	printf("\n\nEnter the logical address: ");
	scanf("%d",&laddr);
	if(laddr>laddr_size){
		printf("\nTRAP: Invalid Logiacal Address");
		exit(0);
	}
	
	pageno = laddr/n_page;
	for(int i=0;i<n_frame;i++){
		if(allocation[i] == pageno){
			//printf("%d",i);
			add = strt_addr[i];
		}
	}
	
	ne = laddr_size/page_size;
	offset = laddr_size%ne;
	paddr = offset + add;
	printf("\nPhysical Address : %d",paddr);
	return 0;
}