#include<stdio.h>
#define MAX 8
typedef int element;
typedef struct{
	element queue[MAX];
	int front,rear;
}QueueType;
void init(QueueType *q)
{
	q->front=q->rear=0;
}
int is_empty(QueueType *q)
{
	return q->front==q->rear;
}
int is_full(QueueType *q)
{
	return q->front==(q->rear+1)%MAX;
}
void enqueue(QueueType *q,element x)
{
	if( is_full(q))
	{
		printf("full!");
		return;
	}
	else{
		q->queue[q->rear]=x;
		q->rear=(q->rear+1)%MAX;
	}
}
element dequeue(QueueType*q)
{
	if(is_empty(q)){
		printf("empty!!");
		return 0;
	}
	else{
		int delete=q->queue[q->front];
		q->front=(q->front +1)%MAX;
		return delete;
	}
}

element peek(QueueType *q)
{
	return q->queue[(q->front)+1];
}
void display(QueueType*q)
{
	if(is_empty(q)){
		printf("empty!\n");
		return;
	}
	int i=q->front;
	for(i;i<q->rear;i++)
		printf("%d ",q->queue[i]);
	printf("\n");
}
		

int  main(void)
{
	QueueType q;
	init(&q);
	printf("front=%d,rear=%d\n",q.front,q.rear);
	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	display(&q);
	printf("dequque()=%d\n",dequeue(&q));
	printf("dequque()=%d\n",dequeue(&q));
	display(&q);
	printf("dequque()=%d\n",dequeue(&q));
	printf("front=%d,rear=%d\n",q.front,q.rear);
	return 0;
}


