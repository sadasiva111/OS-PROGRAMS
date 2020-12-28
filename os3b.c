#include<stdio.h>
void main(){
	int memory_size,os_size;
	int i,m,n,s[20];
	printf("Enter total memory size:");
	scanf("%d",&memory_size);
	printf("Enter memory for OS:");
	scanf("%d",&os_size);
	memory_size -= os_size;
	printf("Enter no. of pages:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter size of page%d:",i+1);
		scanf("%d",&s[i]);
	}
	for(i=0;i<n;i++){
		if(memory_size>=s[i]){
			printf("Page %d allocated \n",i+1);
			memory_size -=s[i];
		}
		else
			printf("process p%d is blocked\n",i+1);
	}
	printf("External Fragmentation is=%d",memory_size);
}
