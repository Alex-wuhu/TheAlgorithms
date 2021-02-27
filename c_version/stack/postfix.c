#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char *key;
	int top;
	int max_size;
}stacktype;
void init(stacktype *s)
{
	s->top=-1;
	s->max_size=100;
	s->key=(char *)malloc(sizeof(int)*s->max_size);
}
int is_empty(stacktype *s)
{
	return (s->top==-1);
}
int is_full(stacktype*s)
{
	return (s->top==(s->max_size-1));
}
void push(stacktype*s, int item)
{
	if (is_full(s)){
		printf(" \n");
		return;
	}
	else
		s->key[++(s->top)]=item;
}
int pop(stacktype*s)
{
	if(is_empty(s)){
		printf("empty!!\n");
		exit(1);
	}
	else
		return s->key[(s->top)--];
}
int peek(stacktype*s){
	if (is_empty(s)){
		return 0;
	}
	else
		return s->key[s->top];
}		
void main()
{
	stacktype s;
	
	char ch;
	int m,n,temp;
	int item;
	init(&s);

	printf("converted postfix form: ");
	while((ch=getchar())!='#')
	{
		if('1'<=ch && ch<='9'){
			if(ch=='1')
				item=1;
			else if(ch=='2')
				item=2;
			else if(ch=='3')
				item=3;
			else if(ch=='4')
				item=4;
			else if(ch=='5')
				item=5;
			else if(ch=='6')
				item=6;
			else if(ch=='7')
				item=7;
			else if(ch=='8')
				item=8;
			else 
				item=9;
			push(&s,item);
			putchar(ch);
		}
		else 
		{
			putchar(ch);
			n=pop(&s);
			m=pop(&s);
			if(ch=='+')
				temp=m+n;
			else if(ch=='-')
				temp=m-n;
			else if(ch=='*')
				temp=m*n;
			else if(ch=='/')
				temp=m/n;
			else 
				temp=m%n;

			push(&s,temp);
		}
	}
		printf("\n");
		printf("evaluation result: %i",peek(&s));



}
