#include<stdio.h>
#include<stdlib.h>

typedef struct Tree_node{
	int key;
	struct Tree_node *left;
	struct Tree_node *right;
}Tree_node;
Tree_node *createTreeNode(int key)
{
	Tree_node* node=(Tree_node*)malloc(sizeof(Tree_node));
	node-> left==NULL;
	node->right==NULL;
	node->key=key;
	return node;
}
void makeLeftSubTree(Tree_node*main,Tree_node*sub)
{
	if(main->left !=NULL)
		return;
	main->left=sub;
}
void makeRightSubTree(Tree_node*main,Tree_node*sub)
{
	if (main->right!=NULL)
		return;
	main->right=sub;
}
void inorder(Tree_node*node)
{
	if (node==NULL)
		return;
	inorder(node->left);
	printf("%d\n",node->key);
	inorder(node->right);
}
void preorder(Tree_node*node)
{
	if (node==NULL)
		return;
	printf("%d\n",node->key);
	preorder(node->left);
	preorder(node->right);
}
void postorder(Tree_node*node)
{
	if (node==NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("%d\n",node->key);
}
int main(void){
	Tree_node*t1=createTreeNode(1);
	Tree_node*t2=createTreeNode(2);
	Tree_node*t3=createTreeNode(3);
	Tree_node*t4=createTreeNode(4);

	makeLeftSubTree(t1,t2);
	makeRightSubTree(t1,t3);
	makeLeftSubTree(t2,t4);
	printf("inorder Traversal\n");
	inorder(t1);
	printf("Preorder Traversal\n");
	preorder(t1);
	printf("pOSTorder Traversal\n");
	postorder(t1);
	return 0;
}

