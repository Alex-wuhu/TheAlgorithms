#define  MAXSIZE 10
typedef struct 
{
	int data[MAXSIZE];
	int top;
}Stack;
Stack * Init(Stack* s);
void Push(Stack*s,int value);
int pop(Stack *s);
void  Top(Stack *s);
void Display(Stack *s);

