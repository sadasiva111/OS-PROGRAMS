#include<stdio.h>
#include<string.h>
#include<conio.h>
struct directory{
	char dname[10],fname[10][10];
    int fcnt;
}dir[10];
int i,dcnt=0,k;
char f[30], d[30];

void createDirectory();
void createFile();
void deleteFile();
void searchFile();
void display();

void main(){
	int option;
	printf("\n1.Create Directory\t2.Create File\t3.Delete File\t4.Search File\t5.Display\t6.Exit");
	while(1){
		printf("\nEnter your choice:");
		scanf("%d",&option);
		switch(option){
			case 1: createDirectory(); 
					break;
			case 2: createFile();
					break;
			case 3: deleteFile();
					break;
			case 4: searchFile();
					break;
			case 5: display();
					break;
			case 6: exit(0);		
			default:printf("Invalid Selction");
		}
	}
}
void createDirectory(){
	printf("\nEnter name of directory:");
	scanf("%s",dir[dcnt].dname);
	dir[dcnt].fcnt=0;
	dcnt++;
	printf("Directory created");
}
void createFile(){
	int flag=0;
	printf("\nEnter name of the directory:");
	scanf("%s",d);
	for(i=0;i<dcnt;i++){
		if(strcmp(d,dir[i].dname)==0){
			printf("Enter name of the file:");
			scanf("%s",dir[i].fname[dir[i].fcnt]);
			dir[i].fcnt++;
			printf("File created");
			flag=1;
			break;
		}
	}
	if(flag==0)  printf("Directory %s not found",d);
}
void deleteFile(){
	int flag1=0,flag2=0;
	printf("\nEnter name of the directory:");
	scanf("%s",d);
	for(i=0;i<dcnt;i++){
		if(strcmp(d,dir[i].dname)==0){
			printf("Enter name of the file:");
			scanf("%s",f);
			for(k=0;k<dir[i].fcnt;k++){
				if(strcmp(f, dir[i].fname[k])==0){
					printf("File %s is deleted ",f);
					dir[i].fcnt--;
					strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
					flag2=1;
					break;
				}
			}
			if(flag2==0) printf("File %s not found",f);
			flag1=1;
			break;
		}
	}
	if(flag1==0) printf("Directory %s not found",d);
}
void searchFile(){
	int flag1=0,flag2=0;
	printf("\nEnter name of the directory:");
	scanf("%s",d);
	for(i=0;i<dcnt;i++){
		if(strcmp(d,dir[i].dname)==0){
			printf("Enter the name of the file:");
			scanf("%s",f);
			for(k=0;k<dir[i].fcnt;k++){
				if(strcmp(f, dir[i].fname[k])==0){
					printf("File %s is found ",f); 
					flag2=1;
					break;
				}
			}
			if(flag2=0) printf("File %s not found",f);
			flag1=1;
			break;
		}
	}
	if(flag1==0) printf("Directory %s not found",d);
}
void display(){
	if(dcnt==0)
		printf("\nNo Directory's ");
	else{
		printf("\nDirectory\t\tFiles");
		for(i=0;i<dcnt;i++){
			printf("\n%s\t\t",dir[i].dname);
			for(k=0;k<dir[i].fcnt;k++)
				printf("\t%s",dir[i].fname[k]);
		}
	}
}
