typedef struct StackNode
{
	int data;
	struct StackNode *next;
}StackNode;
typedef struct LinkStack
{
	StackNode *top;
	int count;
}LinkStack;
void push(LinkStack *s,int value);
void  pop(LinkStack*s);
void display(LinkStack*s);
LinkStack* init();
