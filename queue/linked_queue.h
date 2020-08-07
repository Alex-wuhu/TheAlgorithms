typedef struct qnode
{
	int data;
	struct qnode* next;
}qnode;
typedef struct Linkqueue
{
	qnode *front;
	qnode *rear;
}Linkqueue;
void enqueue(Linkqueue* q,int value);
void dequeue(Linkqueue*q);
void display(Linkqueue *q);
Linkqueue*init();
