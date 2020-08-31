#include<stdio.h>
#include<stdlib.h>
#define max_q 10
typedef int element;
typedef struct{
	element queue[max_q];
	int front,rear;
}Q;
void init(Q* q){
	q->front=q->rear=0;
}
int is_empty(Q *q){return q->front==q->rear;}
int is_full(Q* q){ return (q->rear+1)%max_q==q->front;}
void enqueue(Q* q,element key)
{
	if(is_full(q)){
		printf("queue is full!\n");
		return;
	}
	q->rear=(q->rear+1)%max_q;
	q->queue[q->rear]=key;
}
int dequeue(Q *q){
	if(is_empty(q)){
		printf("q is empty!\n");
		return;
	}
	q->front=(q->front+1)%max_q;
	return q->queue[q->front];
}
int indegree(int v,int num,int**m){
	int i,ind=0;
	for(i=0;i<num;i++){
		if(m[i][v]==1)
			ind++;
	}
	return ind;
}
void main(int argc,char *argv[])
{

	FILE*fp;
	char temp[20];
	int i,num=1;
	int m,n;
	char ch;
	if((fp=fopen(argv[1],"r"))==NULL){
		printf("can't open\n");
		exit(EXIT_FAILURE);
	}
	fgets(temp,100,fp);
	for(i=0;i<20;i++){
		if(temp[i]==' ')
			num+=1;
	}
	int **matrix;
	int *visited;
	matrix=(int**)calloc(num,sizeof(int *));
	for(i=0;i<num;i++)
		matrix[i]=(int*)calloc(num+1,sizeof(int));
	visited=(int *)calloc(num,sizeof(int));

	while(fscanf(fp,"%d",&m)==1){
		ch=getc(fp);
		fscanf(fp,"%d",&n);
		matrix[m-1][n-1]=1;
	}
	Q q;
	init(&q);
	for(i=0;i<num;i++){
		if(indegree(i,num,matrix)==0){
			enqueue(&q,i);
			visited[i]=1;
		}
	}
	printf("topological sort:\n");
	while(!is_empty(&q)){
		int sort=dequeue(&q);
		printf("%d ",sort+1);
		for(i=0;i<=num;i++)
			matrix[sort][i]=0;
		for(i=0;i<num;i++){
			if(indegree(i,num,matrix)==0 &&!visited[i])
			{
				enqueue(&q,i);
				visited[i]=1;
			}
		}
	}
	printf("\n");


	fclose(fp);
}

