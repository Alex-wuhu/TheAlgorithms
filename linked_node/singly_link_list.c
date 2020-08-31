#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Node{
        element data;
        struct Node*link;
}Node;
typedef struct Node* PNode;
PNode creat_node(element data)
{
        PNode new;
        new=malloc(sizeof(Node));
        new->data=data;
        new->link=NULL;
        return new;
}

void Insert_node( PNode *head, element value){
	PNode new=creat_node(value);
	PNode p=*head;
	if(p==NULL){
		*head=new;
	}
	else
	{
		while(p->link!=NULL)
			p=p->link;
		p->link=new;
	}
}

void Delete_node(PNode *head,element value)
{
	PNode p=*head;
	PNode pf=*head;
	if(p==NULL){
		printf("list is empty!");
		return;
	}
	if(p->data==value)     //delet head 
		*head=p->link;
	else 
	{
		int check=0;
		while(p!=NULL)
		{
			if(p->data==value){
				pf->link=p->link;
				p->link=NULL;
				check=1;
				break;
			}
			pf=p;
			p=p->link;
			
		}
		if(check==0)
			printf("can't find %d\n",value);

	}
	free(p);
}
				

void display(PNode head)
{
        PNode p;
	p=head;
	if(p==NULL)
		printf("list is empty!");
	else{
       		while(p!=NULL){
               		printf("%i ",p->data);
                	p=p->link;
		}
	}
        printf("\n");
}

void main(){
	PNode head=NULL;
	Insert_node(&head,1);
	Insert_node(&head,2);
        Insert_node(&head,3);
	printf("before delete\n");
	display(head);
	printf("after delete 5\n");
	Delete_node(&head,5);
	display(head);

}

