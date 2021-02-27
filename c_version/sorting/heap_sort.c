#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void Build_heap(int *list,int i,int n)
{
	int j,temp;
	temp=list[i];
	for(j=2*i;j<=n;j=j*2)
	{
		if(j<n&&list[j]<list[j+1])
			j++;
		if(temp>list[j])
			break;
		list[i]=list[j];
		i=j;
	}
	list[i]=temp;


}
void heap_sort(int *list,int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		Build_heap(list,i,n);
	}
	for(i=n;i>=2;i--)
	{
		swap(&list[i],&list[1]);
		Build_heap(list,1,i-1);
	}
}
int main(void)
{
	int list[6]={0,10,9,5,100,6};
	int i=1,j=1;
	printf("before sorting:");
	while(i<6)
	{
		printf("%d ",list[i]);
		i++;
	}
	heap_sort(list,5);
	printf("\nafter  sorting:");

	while(j<6)
	{
		printf("%d ",list[j]);
		j++;
	}



	return 0;
}
