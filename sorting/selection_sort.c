#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selection_sort(int *list,int n)
{
	int i,j,min;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(list[min]>list[j])
			{
				min=j;
			}
		}
		if(i!=min)
			swap(&list[min],&list[i]);
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
	selection_sort(list,5);
	printf("\nafter  sorting:");
	while(j<5)
	{
		printf("%d ",list[j]);
		j++;
	}



	return 0;
}
