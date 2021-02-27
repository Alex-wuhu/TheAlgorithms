#include<stdio.h>
#define MAX 6
int binary_search(int list[MAX],int key)
{
	int start=0;
	int last=MAX;
	int mid=(start+last)/2;
	while(start<=last)
	{
		if(list[mid]==key)
			return mid;
		if(list[mid]>key)
			last=mid-1;
		else
			start=mid+1;
		mid=(start+last)/2;
	}
	return -1;

}
int main(void)
{
	int list[MAX]={1,2,3,4,5,6};
	int key;
	printf("search key:");
	scanf("%d",&key);
	int check=binary_search(list,key);
	if(check==-1)
		printf("can't find %d",key);
	else
		printf("%d is %d one of list",key,check+1);

	return 0;
}

