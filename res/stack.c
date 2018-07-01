#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* next;
	int num;
}Node;
typedef Node* NodePtr;
typedef Node* Stack;


//函数声明
Stack StackCreate(void);
int IsStackEmpty(Stack stack);
int StackPush(Stack stack, int x);
int StackPop(Stack stack);
int StackTop(Stack stack);
void StackDestory(Stack stack);



//创建一个栈
Stack StackCreate(void)
{
	NodePtr Head = (NodePtr)malloc(sizeof(Node));
	if(Head == NULL)
	{
		printf("No free space\n");
		return NULL;
	}
	Head->next = NULL;
	return Head;
}

//判断栈是否为空
int IsStackEmpty(Stack stack)
{
	return stack->next == NULL;
}

//入栈
int StackPush(Stack stack, int x)
{
	NodePtr new = (NodePtr)malloc(sizeof(Node));
	if(new == NULL)
	{
		printf("No free space\n");
		return -1;
	}
	new->num = x;
	new->next = stack->next;
	stack->next = new;
	return 0;
}

//出栈
int StackPop(Stack stack)
{
	if(!IsStackEmpty(stack))
	{
		NodePtr Temp = stack->next;
		stack->next = Temp->next;
		free(Temp);
		return 0;
	}
	printf("Empty Stack\n");
	return -1;
}

//获取栈顶信息
int StackTop(Stack stack)
{
	if(IsStackEmpty(stack))
	{
		printf("Empty Stack\n");
		return 0;
	}
	return stack->next->num;
}

//销毁栈
void StackDestory(Stack stack)
{
	NodePtr p = stack->next;
	while(p != NULL)
	{
		NodePtr Temp = p->next;
		free(p);
		p = Temp;
	}
}


int main(void)
{
	Stack s = StackCreate();
	for(int i = 1; i <= 5;i++)
		StackPush(s,i);
	for(int i = 1; i <= 3;i++)
		StackPop(s);
	for(int i = 1; i <= 3;i++)
		StackPush(s,i*10);
	for(int i = 0; i < 5; i++)
	{
		printf("%d ",StackTop(s));
		StackPop(s);
	}
	printf("\n");
	StackDestory(s);
	printf("%d ",StackTop(s));
	return 0;
}