#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* next;
	void * data;
	int  num;
}Node;


Node* list_init(void)
{
	Node *p = malloc(sizeof(Node));
	if(p == NULL)
	{
		printf("malloc error");
		return NULL;
	}
	p->next = NULL;
	p->data = "A";
	p->num = 0;
	return p;
}


Node* list_add(Node *list_freeptr,int i,char* data,int num)
{
	Node *p = list_freeptr;
	Node *new = malloc(sizeof(Node));
	if(new == NULL)
	{
		printf("malloc error");
		return NULL; 
	}
	new->data = data;
	new->num = num;
	
	if(i == 0)
	{
		new->next = p;
		return new;
	}
	else
	{
		int j = 0;
		while(p!=NULL)
		{	
			j++;
			if(j == i)
			{
				new->next = p->next;
				p->next = new;
				return list_freeptr;
			}
			p = p->next;
		}
		
	}
	return NULL;
}


Node* list_del(Node *list_freeptr,int i)
{
	Node *p = list_freeptr;
	if(i == 0)
	{
		p = p->next;
		free(list_freeptr);
		return p;
	}
	else
	{
		int j=0;
		while(p != NULL)
		{
			j++;
			if(j == i)
			{
				Node * temp = p->next;
				p->next = p->next->next;
				free(temp);
				return list_freeptr;
			}
			p = p->next;
		}
	}
	return NULL;
}


int list_add_end(Node *list_freeptr,char* data,int num)
{
	Node *p = list_freeptr;
	while(p->next != NULL)
	{
		p = p->next;
	}
	Node *new = malloc(sizeof(Node));
	if(new == NULL)
	{
		printf("malloc error");
		return -1; 
	}
	new->data = data;
	new->num = num;
	new->next = NULL;
	p->next = new;
	return 0;
} 

Node* list_del_end(Node *list_freeptr)
{
	Node *p = list_freeptr;
	if(p->next == NULL)//只有一个链表节点
	{
		free(p);
		return NULL;
	}
	while(p->next->next != NULL)
	{
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	return list_freeptr;
}


void list_show(Node *list_freeptr)
{
	Node *p = list_freeptr;
	while(p != NULL)
	{
		printf("%d ",p->num);
		p = p->next;
	}
	printf("\n");
}

void list_destory(Node* list_freeptr)
{
	Node* p = list_freeptr;
	while(p != NULL)
	{
		Node* Temp = p->next;
		free(p);
		p = Temp;
	}
}

int main(void)
{
	Node *list = list_init();
	if(list == NULL)
	{
		printf("malloc error");
		return -1;
	}
	for(int i = 1; i < 10; i++)
	{
		list_add_end(list,"A",i);
	}
	list_show(list);
	list = list_add(list,0,"B",100);
	list_show(list);
	list = list_add(list,5,"B",100);
	list_show(list);
	list_del_end(list);
	list_show(list);
	list_del(list,5);
	list_show(list);
	for(int i = 7; i > 0;  i--)
	{
		list_del(list,i);
		list_show(list);
	}
	list_destory(list);
	list_show(list);
	return 0;
}