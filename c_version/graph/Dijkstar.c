#include<stdio.h>
#include<limits.h>
#define TRUE 1
#define FALSE 0
#define NODES 7
#define INF 9999
int cost[NODES][NODES]={
	{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}
};
int distance[NODES];
int found[NODES];
void print_distance()
{
	int i;
	for(i=0;i<NODES;i++)
		printf("%d ",distance[i]);
	printf("\n");
}
int choose(int distance[],int n,int found[])
{
	int i,min,minpos;
	min=INF;
	minpos=-1;
	for(i=0;i<n;i++)
		if(distance[i]<min &&!found[i]){
			min=distance[i];
			minpos=i;
		}
	return minpos;
}
void shortest_path(int start,int cost[][NODES],int distance[],
		int n,int found[])
{
	int i,u,w;
	for(i=0;i<n;i++)
	{
		distance[i]=cost[start][i];
		found[i]=FALSE;
	}
	found[start]=TRUE;
	distance[start]=0;
	for(i=0;i<n;i++){
		print_distance();
		u=choose(distance,n,found);
		found[u]=TRUE;
		for(w=0;w<n;w++){
				if(!found[w])
				if(distance[u]+cost[u][w]<distance[w])
					distance[w]=distance[u]+cost[u][w];
		}
	}
	
}
void main()
{
	shortest_path(0,cost,distance,NODES,found);
}

