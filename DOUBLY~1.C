#include<stdio.h>
#include<conio.h>
struct node{
	 int data;
	 struct node *left,*right;
}*root=NULL,*temp,*p;
int location,length,count,i;
int Length(){
    struct node*temp=root;
      for(count=0;temp!=NULL;count++)
       temp=temp->right;
	 return count;
}
void insertAtBegin(){
	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("\tEnter node data:");
	 scanf("%d",&temp->data);
	 temp->left=NULL;
	 temp->right=NULL;
	 if(root==NULL)
		  root=temp;
	 else{
		  temp->right=root;
		  root->left=temp;
		  root=temp;
	 }
}
void insertAtEnd(){
	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("\tEnter node data:");
	 scanf("%d",&temp->data);
	 temp->left=NULL;
	 temp->right=NULL;
	 if(root==NULL)
		  root=temp;
	 else{
		  p=root;
		  while(p->right!=NULL)
			   p=p->right;
		  p->right=temp;
		  temp->left=p;
	 }
}
void insertAfter(){
	 printf("\tEnter location to insert after:");
	 scanf("%d",&location);
	 if(location>Length())
		  printf("\tInvalid location\n");
	 else{
		  temp=(struct node*)malloc(sizeof(struct node));
		  printf("\tEnter node data:");
		  scanf("%d",&temp->data);
		  temp->left=NULL;
		  temp->right=NULL;
		  p=root;
		  for(i=1;i<location;i++)
			   p=p->right;
		  temp->right=p->right;
		  p->right=temp;
		  temp->left=p;
		  p->right=temp;
	 }
}
void display(){
	 struct node*temp=root;
	 while(temp!=NULL){
		  printf("%d->",temp->data);
		  temp=temp->right;
	 }
}
void Delete(){
	 printf("\tEnter location to delete");
	 scanf("%d",&location);
	 if(location>Length())
		  printf("\tThere is no such node because it is having %d nodes\n",length);
	 else if(location==1){
		  temp=root;
		  root=temp->right;
		  root->left=temp->left;
	 }
	 else{
		  struct node*p=root,*q;
		  for(i=1;i<location-1;i++)
			   p=p->right;
		  q=p->right;
		  p->right=q->right;
		  q->right->left=p;
		  free(q);
	 }
}
void main(){
	 int choice;
	 clrscr();
	 printf("**OPERATIONS OF DOUBLY LINKED LISTS**");
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
			   case 4 :printf("\tLinked list contains %d nodes\n",Length());
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




