#include<stdio.h>
#include<stdlib.h>
#include"linked_queue.h"
void enqueue(Linkqueue*q,int value)
{
	qnode* new=malloc(sizeof(qnode));
	new->data=value;
	new->next=NULL;
	q->rear->next=new;
	q->rear=new;
}
void dequeue(Linkqueue*q)
{
	if(q->rear==q->front){
		printf("queue is empty!!\n");
		return;
	}
	qnode *p=q->front->next;
	q->front->next=p->next;
	printf("delete %d\n",p->data);
	if(p==q->rear)
		q->rear=q->front;
	free(p);
}
void display(Linkqueue*q)
{
	if(q->front==q->rear)
	{
		printf("queue is empty!\n");
		return;
	}
	qnode* p=q->front->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(void)
{
	Linkqueue *q=malloc(sizeof(Linkqueue));
	q->front=q->rear=malloc(sizeof(qnode));
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	display(q);
	dequeue(q);
	dequeue(q);
	display(q);
	dequeue(q);
	display(q);
	return 0;
}
