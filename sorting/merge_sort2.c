#include<stdio.h>
#include<stdlib.h>
void swap(int*a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void merge(int *list,int l,int r,int n)
{
	int *b=malloc(n*sizeof(int));
	int c=l;
	int p1,p2;
	p1=l;
	p2=(l+r)/2+1;
	while((p1<(1+r)/2) && (p2<r+1))
	{
		if(list[p1]<=list[p2])
		{
			b[c++]=list[p1];
			p1++;
		}
		else
		{
			b[c++]=list[p2];
			p2++;
		}
	}
	if(p2==r+1)
	{
		while(p1<((r+l)/2+1))
		{
			b[c++]=list[p1];
			p1++;
		}
	}
	else
	{
		while(p2<(r+1))
		{
			b[c++]=list[p2];
			p2++;
		}
	}
	for(c=l;c<r-l+1;c++)
		list[c]=b[c];
	free(b);

}
void merge_sort(int *list,int n,int l,int r)
{
        if(r-l==1)
        {
                if(list[l]>list[r])
                        swap(&list[l],&list[r]);
        }
        else if(l!=r)
        {
                merge_sort(list,n,l,(r+1)/2);
                merge_sort(list,n,(r+1)/2+1,r);
                merge(list,l,r,n);
        }
        //  else l==r   no change

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
	merge_sort(list,5,0,4);
	printf("\nafter  merge_sort:");
	while(j<5)
	{
		printf("%d ",list[j]);
		j++;
	}



	return 0;
}
