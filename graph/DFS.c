#include<stdio.h>
#define MAX 4
int adj_mat[MAX][MAX]={
	{0,1,0,1},
	{1,0,1,1},
	{0,1,0,1},
	{1,1,1,0}};
int visited[MAX];
void graph_dfs_mat(int v){
	int w;
	visited[v]=1;
	printf("%d ",v);
	for (w=0;w<MAX;w++){
		if(adj_mat[v][w] &&!visited[w])
			graph_dfs_mat(w);
	}
}
void main(){
	graph_dfs_mat(1);
	printf("\n");
}
