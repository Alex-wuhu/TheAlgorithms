#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
struct Node*first=NULL;
struct Node*last=NULL;
Node* creat_node(int value)
{
	Node* new=malloc(sizeof(Node));
	new->data=value;
	new->next=NULL;
	return new;
}
void insert_node(int value)
{
	Node*new=creat_node(value);
	if(first==NULL)
		first=last=new;
	else
	{
		last->next=new;
		last=new;
	}
	last->next=first;
}
void show(){
	Node *p=first;
	Node *f=NULL;
	if(p==NULL){
		printf("list is empyt!!\n");
		return;
	}
	while(f!=last){
		printf("%d ",p->data);
		f=p;
		p=p->next;
	}
	printf("\n");
}
void delete_node(int value){
	if(first==NULL){printf("list is empty"); return;}
	Node*p=first;
	int check=0;      //chekc the result
	if(p->data==value)   //delete head
	{
		first=p->next;
		last->next=first;
		check=1;
	}
	else
	{
		Node *pf=p;
		p=p->next;
		while(p!=first){
			if(p->data==value){
				if(p==last)     // delete last
				{
					last=pf;
					last->next=first;
				}
				else
					pf->next=p->next;
				check=1;
				break;
			}
			pf=p;
			p=p->next;
		}
	}
	if(check==0){
		printf("can't find %d",value);
		return;
	}
	free(p);
}
void main(){
	insert_node(1);
	insert_node(2);
	insert_node(3);
	show();
	delete_node(2);
	show();
	
}
