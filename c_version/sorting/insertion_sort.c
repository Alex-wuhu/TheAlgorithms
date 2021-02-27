#include<stdio.h>
void insertion_sort(int *list,int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		j=i-1;
		int key=list[i];
		for(;j>=0 &&key<list[j];j--)
		{
			list[j+1]=list[j];
		}
		list[j+1]=key;
	}
}

int main(void)
{
	int list[5]={10,9,5,100,6};
	int i=0,j=0;
	printf("before sorting:");
	while(i<5)
	{
		printf("%d ",list[i]);
		i++;
	}
	insertion_sort(list,5);
	printf("\nafter  insertion_sorting:");
	while(j<5)
	{
		printf("%d ",list[j]);
		j++;
	}



	return 0;
}
