#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	 int data;
	 struct node* link;
}*root=NULL,*temp,*p;
int count,location,i;
int length(){
	 temp=root;
	 for(count=0;temp!=NULL;count++)
		  temp=temp->link;
	 return count;
}
void insertAtBegin(){
	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("\tEnter node data:");
	 scanf("%d",&temp->data);
	 temp->link=NULL;
	 if(root==NULL)
		  root=temp;
	 else{
		  temp->link=root;
		  root=temp;
	 }
}
void insertAfter(){
	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("\tEnter location to insert after:");
	 scanf("%d",&location);
	 if(location>length()){
		  printf("\tCurrent list is having %d nodes\n",length());
		  printf("\tInvalid location\n");
	 }
	 else{
		  p=root;
		  for(i=1;i<location;i++)
			   p=p->link;
		  temp=(struct node*)malloc(sizeof(struct node));
		  printf("\tEnter node data:");
		  scanf("%d",&temp->data);
		  temp->link=NULL;
		  temp->link=p->link;
		  p->link=temp;
	 }
}
void insertAtEnd(){
	 temp=(struct node *)malloc (sizeof(struct node));
	 printf("\tEnter node data:");
	 scanf("%d",&temp->data);
	 temp->link=NULL;
	 if(root==NULL)
		  root=temp;
	 else{
		  p=root;
		  while(p->link!=NULL)
			   p=p->link;
		  p->link=temp;
	 }
}

void Delete(){
	 printf("\tEnter location to delete:");
	 scanf("%d",&location);
	 if(location>length())
		  printf("\tInvalid location\n");
	 else if(location==1){
		  temp=root;
		  root=temp->link;
		  temp->link=NULL;
		  free(temp);
	 }
	 else{
		  struct node*p=root,*q;
		  for(i=1;i<location-1;i++)
			   p=p->link;
		  q=p->link;
		  p->link=q->link;
		  q->link=NULL;
		  free(q);
	 }
}
void display(){
	 temp=root;
	 if(temp==NULL)
		  printf("\tList is empty\n");
	 else{
		  while(temp!=NULL){
			   printf("%d->",temp->data);
			   temp=temp->link;
		  }
	 }
}
void main(){
	 int choice;
	 clrscr();
	 printf("**OPERATIONS OF SINGLY LINKED LISTS**");
	 printf("\n1.InsertAtBegin\t2.InsertAfter\t3.InsertAtEnd\t4.Length\t5.Delete\t6.Display\t7.Exit");
	 while(1){
		  printf("\n\tEnter your choice:");
		  scanf("%d",&choice);
		  switch(choice){
			   case 1 :insertAtBegin();
					   break;
			   case 2 :insertAfter();
					   break;
			   case 3 :insertAtEnd();
					   break;
			   case 4 :printf("\tLinkedlist contains %d nodes\n",length());
					   break;
			   case 5 :Delete();
					   break;
			   case 6 :display();
					   break;
			   case 7 :exit(0);
			   default:printf("\tInvalid Selection\n");
		  }
	 }
}


