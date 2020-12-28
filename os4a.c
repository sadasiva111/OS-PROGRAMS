#include<stdio.h>
#include<string.h>
struct directory{
	char dname[10],fname[10][10];
	int fcnt;
}dir;

int i,option; 
char f[30]; 

void createFile();
void deleteFile();
void searchFile();
void display();

void main(){
	dir.fcnt=0;
	printf("\nEnter name of directory:");
	scanf("%s", dir.dname);
	printf("\n1. Create File\t2. Delete File\t3. Search File\t4. Display Files\t5. Exit");
	while(1){
		printf("\nEnter your choice:");
		scanf("%d",&option);
		switch(option){
			case 1: createFile(); 
					break;
			case 2: deleteFile();
					break;
			case 3: searchFile();
					break;
			case 4: display();
					break;
			case 5: exit(0);
			default: printf("Invalid Selection");
		}
	}
}

void createFile(){
	printf("\nEnter the name of the file:");
	scanf("%s",dir.fname[dir.fcnt]);
	dir.fcnt++;
}
void deleteFile(){
	int flag=0;
	printf("\nEnter the name of the file: ");
	scanf("%s",f);
	for(i=0;i<dir.fcnt;i++){
		if(strcmp(f, dir.fname[i])==0){
			printf("File %s is deleted ",f);
			strcpy(dir.fname[i],dir.fname[dir.fcnt-1]); 
			dir.fcnt--;
			flag=1;
			break;
		}
	}
	if(flag==0)  printf("File %s not found",f);
}
void searchFile(){
	int flag=0;
	printf("\nEnter the name of the file:");
	scanf("%s",f);
	for(i=0;i<dir.fcnt;i++){
		if(strcmp(f, dir.fname[i])==0){
			printf("File %s is found ", f);
			flag=1;
			break;
		}
	}
	if(flag==0)  printf("File %s not found",f);
}
void display(){
	if(dir.fcnt==0)
		printf("\nDirectory Empty");
	else{
		printf("\nThe Files are:");
		for(i=0;i<dir.fcnt;i++)
			printf("\t%s",dir.fname[i]);
	}
}
