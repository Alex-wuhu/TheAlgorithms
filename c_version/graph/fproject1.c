#include<stdio.h>
#include<stdlib.h>

void dijkstra(int **matrix,int num,int s);
void print(int *distance,int num);
void main()
{
	int i,m,n;
	int **matrix,num=1;
	char temp[20],ch;                 
	int startnode;           
	printf("Enter the nodes:");
	scanf("%d",&startnode);                  //get start node
	gets(temp);  			//get first line
	for(i=0;i<20;i++){
		if(temp[i]==' ')
			num++;
	}
	printf("Enter the distance:");
	matrix=(int **)calloc(num,sizeof(int*));
	for(i=0;i<num;i++)
		matrix[i]=(int*)calloc(num,sizeof(int));

	while(1){
		scanf("%d""%c""%d""%c",&m,&ch,&n,&ch);     //get the a-b-
		scanf("%d",&matrix[m-1][n-1]);             // get the distance between a and b 
		ch=getchar();
		if(ch=='\n')		//      '\n' means input finished
			break;
	}
	 dijkstra(matrix,num, startnode-1);

	
}
void print(int *distance,int num)
{
	for(int i=0;i<num;i++)
		printf("%d ",distance[i]);
	printf("\n");
}
void dijkstra(int **matrix,int num,int s)
{
	int i,j,temp;
	int *visited,distance[num],pre[num];
	visited=(int*)calloc(num,sizeof(int));
	visited[s]=1;                           // startnode is visited and othernoed shuold be 0
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			if(matrix[i][j]==0)
				matrix[i][j]=9999;	//initial cost value
		}
	}
	
	for(i=0;i<num;i++)
	{

		distance[i]=matrix[s][i];      // initial distance and prenode value
		if(i==s)
			distance[i]=0;
	}
	                 
	for(i=0;i<num;i++)
	{
		print(distance,num);
		temp=9999;
		for(j=0;j<num;j++)
		{
			if(distance[j]<temp &&!visited[j] )
			{
				temp=distance[j];
				visited[j]=1;
				for(int m=0;m<num;m++)
				{
					if(temp+matrix[j][m]<distance[m] )
						distance[m]=temp+matrix[j][m];
				}
			}
		}
	}
}






