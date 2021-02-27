#include<stdio.h>
#include"linked_stack.h"
#include<stdlib.h>
#include<assert.h>
LinkStack * init()
{
	LinkStack *s=malloc(sizeof(LinkStack));
	s->count=0;
	return s;
}
void push(LinkStack *s,int value)
{
	StackNode *new=malloc(sizeof(StackNode));
	assert(new);
	new->data=value;
	new->next=s->top;
	s->top=new;
	s->count++;
}
void display(LinkStack*s)
{
	if(s->count==0)
	{
		printf("stack is empty!!\n");
		return;
	}
	int n=s->count;
	StackNode *p=s->top;
	while(n>0){
		printf("%d ",p->data);
		p=p->next;
		n--;
	}
	printf("\n");
}
void  pop(LinkStack *s)
{
	if(s->count==0)
	{
		printf("stack is empty!!");
		return;
	}
	StackNode *p=s->top;
	s->top=s->top->next;
	s->count--;
	printf("delete %d \n",p->data);
	free(p);
}
void main()
{
	LinkStack *s=init();
	push(s,10);
	push(s,20);
	push(s,30);
	display(s);
	pop(s);
	display(s);
}

