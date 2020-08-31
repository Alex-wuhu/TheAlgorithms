#include<stdio.h>
#define max 20
void swap(int*a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int v[],int low,int high)
{
        int pivot=v[low];
        while(low<high)
	{
		while(low<high &&v[high]>=pivot)
			high--;
		swap(&v[low],&v[high]);
		while(low<high &&v[low]<=pivot)
			low++;
		swap(&v[low],&v[high]);

        }
        return low;
}

void print(int list[],int n)	
{
        int i;
        for (i=0;i<n;i++)
                printf("%d ",list[i]);
        printf("\n");
}

void quick_sort(int list[],int left,int right)
{
	if(left<right)
	{
		int pivot=partition(list,left,right);
		quick_sort(list,left,pivot-1);
		quick_sort(list,pivot+1,right);
	}
}
void main(){
	int list[max]={9,8,3,0,5,4,7,2,1,6};
	printf("before sorting:");
	print(list,10);
	quick_sort(list,0,9);
	
	printf("after  sorting:");
	print(list,10);
}
