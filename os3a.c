#include<stdio.h>

void main(){
	int memory_size,os_size;
	int i,ps[20],n,frag=0;
	printf("Enter size of memory:");
	scanf("%d",&memory_size);
	printf("Enter memory for OS:");
	scanf("%d",&os_size);
	memory_size=memory_size-os_size;
	printf("Enter no.of partitions to be divided:");
	scanf("%d",&n);
	int size=memory_size/n;
	for(i=0;i<n;i++){
		printf("Enter process %d process size",i+1);
		scanf("%d",&ps[i]);
		if(ps[i]<=size){
			frag=frag+size-ps[i];
			printf("process%d is allocated\n",i+1);
		}
		else
			printf("process%d is blocked",i+1);
	}
	printf("total fragmentation is %d",frag);
}
