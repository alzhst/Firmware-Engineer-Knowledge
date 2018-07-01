#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char ch;
	struct node* left;
	struct node* right;
}TreeNode;

typedef TreeNode* PtrTreeNode;
typedef PtrTreeNode Tree;



//创建二叉树
void CreateTree(Tree *T)
{
	char ch;
	scanf("%c",&ch);

	if(ch == '*')
	{
		*T = NULL;
	}
	else
	{
		*T = (Tree)malloc(sizeof(TreeNode));
		(*T)->ch = ch;
		CreateTree(&(*T)->left);
		CreateTree(&(*T)->right);
	}
}

//前序遍历
void PreShow(Tree T)
{
	if(T == NULL)
		return;
	printf("%c ",T->ch);
	PreShow(T->left);
	PreShow(T->right);
}

//中序遍历
void MidShow(Tree T)
{
	if(T == NULL)
		return;
	MidShow(T->left);
	printf("%c ",T->ch);
	MidShow(T->right);
}

//后序遍历
void BackShow(Tree T)
{
	if(T == NULL)
		return;
	BackShow(T->left);
	BackShow(T->right);
	printf("%c ",T->ch);
}


int main()
{
	Tree t;
	CreateTree(&t);
	PreShow(t);
	printf("\n");
	MidShow(t);
	printf("\n");
	BackShow(t);
	printf("\n");
	return 0;
}