#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void Bubble_sort(int *list,int n)
{
	int check=1;            // if there is no need to swap, break
	int i,j;
	for(i=0;i<n && check;i++)
	{
		check=0;
		for(j=n-1;j>=i;j--)
		{
			if(list[j]>list[j+1])
			{
				swap(&list[j],&list[j+1]);
				check=1;
			}
		}
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
	Bubble_sort(list,5);
	printf("\nafter  sorting:");
	while(j<5)
	{
		printf("%d ",list[j]);
		j++;
	}



	return 0;
}
