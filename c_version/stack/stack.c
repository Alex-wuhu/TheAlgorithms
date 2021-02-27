#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"stack.h"
Stack * Init(Stack *s)
{
	s=(Stack*)malloc(sizeof(int)*(MAXSIZE+1));
	assert(s);
	s->top=-1;
	return s;
}
void push(Stack *s,int value)
{
	if(s->top>=MAXSIZE-1)
	{
		printf("error! stack is full");
		return;
	}
	s->top+=1;
	s->data[s->top]=value;
}
int pop(Stack *s)
{
	if(s->top==-1){
		printf("stack is empty!");
		return -1;
	}
	int top=s->data[s->top];
	s->top--;
	return top;
}

void Top(Stack*s)
{
	if(s->top==-1){
		printf("stack is empty!");
		return;
	}
	printf("Top of stack is %d\n",s->data[s->top]);
}
void Display(Stack *s)
{
	int i=0;
	int len=s->top;
	if (s->top==-1){
		printf("stack is empty!");
		return ;
	}
	while (i<=len)
	{
		printf("%d ",s->data[i]);
		i++;
	}
	printf("\n");
}
void main()
{
	Stack*s=Init(s);
	push(s,1);
	push(s,2);
	push(s,3);
	Display(s);
	Top(s);
	
	int p=pop(s);
	printf("after delete %d\n",p);
	Display(s);
}
