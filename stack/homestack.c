#include<stdio.h>
#define MAXSIZE 100
typedef int element;
typedef struct{
	element stack[MAXSIZE];
	int top;
}StackType;
void init(StackType *s){
	s->top=-1;
}
int is_empty(StackType *s){
	return s->top==-1;
}
int is_full(StackType *s){
	return s->top==MAXSIZE-1;
}
void push(element x,StackType *s)
{
	if (is_full(s))
		fprintf(stderr,"stack full\n");
	else
		s->stack[++(s->top)]=x;
}
element pop(StackType *s)
{
	if (is_empty(s))
		fprintf(stderr,"stack empty\n");
	else {
		return s->stack[(s->top)--];
	}
}
element peek(StackType*s)
{
	if (is_empty(s))
		fprintf(stderr,"stack empty\n");
	else
		return s->stack[s->top];
}
void main()
{
	StackType s;
	init(&s);
	push(16,&s);
	push(27,&s);
	push(38,&s);
	printf("%d\n",pop(&s));
	printf("%d\n",peek(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",is_empty(&s));
}

