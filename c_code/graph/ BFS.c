#include<stdio.h>
#define max_v 4
#define max_q 10
int adj_mat[max_v][max_v]={
	{0,1,0,1},
	{1,0,1,1},
	{0,1,0,1},
	{1,1,1,0}};
int visited[max_v];
int n=4;
//  queue struct and functions
typedef int element;
typedef struct{
	element queue[max_q];
	int front,rear;
}QueueType;

void init(QueueType * q){ q->front=q->rear=0; }
int is_empty(QueueType *q){ return q->front==q->rear;}
int is_full(QueueType *q){ return (q->rear+1)%max_q==q->front; }

void enqueue(QueueType*q,element key)
{
	if(is_full(q)){
		printf("queue is full\n");
		return;
	}
	q->rear=(q->rear+1)%max_q;
	q->queue[q->rear]=key;
}
element dequeue(QueueType*q)
{
	if(is_empty(q)){
		printf("queue is empty\n");
		return -1;
	}
	q->front=(q->front+1)%max_q;
	return q->queue[q->front];
}
// BFS functions
void graph_bfs_mat(int v){
	int w;
	QueueType q;
	init(&q);
	visited[v]=1;
	printf("%d ",v);
	enqueue(&q,v);
	while(!is_empty(&q)){
		v=dequeue(&q);
		for(w=0;w<n;w++){
			if(adj_mat[v][w] && !visited[w] ){
				visited[w]=1;
				printf("%d ",w);
				enqueue(&q,w);
			}
		}
	}
}
void main(){
	graph_bfs_mat(0);
	printf("\n");
}
