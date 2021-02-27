#include<stdio.h>
void swap(int*a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void shell_sort(int *list,int n)
{
	int i,j,gap;
	for(gap=n/2;gap>0;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			for(j=i-gap;j>=0&& list[j]>list[j+gap];j=j-gap)
				swap(&list[j],&list[j+gap]);
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
	shell_sort(list,5);
	printf("\nafter  shell_sorting:");
	while(j<5)
	{
		printf("%d ",list[j]);
		j++;
	}



	return 0;
}
