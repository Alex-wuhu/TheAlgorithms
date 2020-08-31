#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct {
	int capacity;
	int size;
	ElementType*Elements;

}HeapStruct;
HeapStruct*CreateHeap(int heapsize)
{
	HeapStruct*h;
	h=(HeapStruct*)malloc(sizeof(HeapStruct));
	h->size=0;
	h->capacity=heapsize;
	h->Elements=(ElementType*)malloc(sizeof(int)*(heapsize+2));
	return h;
}

void swap(int *a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void PrintHeap(HeapStruct*h)
{
	if (h->size==0)
		printf("heap is empty\n");
	else{
	int i;
	int level=1;
	printf("\n");
	for (i=1;i<=h->size;i++){
		if(i==level){
			printf("\n");
			level*=2;
		}
		printf("\t%d",h->Elements[i]);
	}
	printf("\n");
	}
}
void insert(HeapStruct*h,ElementType value)
{
	if((h->size+1)>=h->capacity)
		printf("heap is full\n");
	else{
	h->size++;
	h->Elements[h->size]=value;
	int child=h->size;
	int parent=child/2;

	while(child>1 && h->Elements[parent]>h->Elements[child])
	{
		swap(&h->Elements[parent],&h->Elements[child]);
		child=parent;
		parent=child/2;
	}
	}
}

ElementType DeleteHeap(HeapStruct*h)
{
	if (h->size==0)
		return 0;
	int result=h->Elements[1];
	swap(&h->Elements[1],&h->Elements[h->size]);
	h->size-=1;

	int parent=1;
	int child=2;
	if(child+1<=h->size)
		child=(h->Elements[child]<h->Elements[child+1]) ? child :child+1;
	while(child<=h->size && h->Elements[parent]>h->Elements[child])
	{
		swap(&h->Elements[parent],&h->Elements[child]);

		parent=child;
		child*=2;
		if (child+1<=h->size)
			child=(h->Elements[child]<h->Elements[child+1]) ? child : child+1;
	}
	return result;
}
int main(void)
{
	
	HeapStruct *heap=CreateHeap(10);
	insert(heap,10);
	insert(heap,20);
	insert(heap,5);
	insert(heap,0);
	PrintHeap(heap);
	printf("After deleting %d\n",DeleteHeap(heap));
	PrintHeap(heap);
	return 0;
}






		

