#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	int key;
	struct TreeNode*left,*right;
}TreeNode;
void printInorder(TreeNode*t)
{
	if(t!=NULL){
	printInorder(t->left);
	printf("%d ",t->key);
	printInorder(t->right);
	}	
}
void printPreorder(TreeNode*t)
{
	if (t!=NULL){
		printf("%d ",t->key);
		printPreorder(t->left);
		printPreorder(t->right);
	}
}
void printPostorder(TreeNode*t){
	if (t!=NULL){
		printPostorder(t->left);
		printPostorder(t->right);
		printf("%d ",t->key);
	}
}
TreeNode*findNode(TreeNode*node,int key)
{
	while (node!=NULL){
		if(key==node->key)
			return node;
		else if (key<node->key)
			node=node->left;
		else
			node=node->right;
	}
	if (node==NULL)
		return NULL;
	
}

TreeNode*insertNode(TreeNode*root,int key)
{
	TreeNode*parNode,*curNode;
	TreeNode*newNode;
	curNode=root;
	parNode=NULL;
	newNode=(TreeNode*)malloc(sizeof(TreeNode));
	newNode->key=key;
	newNode->left=newNode->right=NULL;
	while (curNode!=NULL )
	{
		if (key==curNode->key)
		{
			printf("%d already exited ",key);
			free(newNode);
			return root;
		}
		parNode=curNode;
		if (key<curNode->key)
			curNode=curNode->left;
		else
			curNode=curNode->right;
	}
	if (parNode!=NULL)
		if (parNode->key>key)
			parNode->left=newNode;
		else
			parNode->right=newNode;
	else
		root=newNode;
	return root;
}
TreeNode* deleteNode(TreeNode*node,int key)
{
	TreeNode*parNode,*curNode,*childNode,*succ,*succ_p;
	parNode=NULL;
	curNode=node;
	if(node ==NULL)                         //  tree is empty
	{
		printf("tree is empty!");
		return node;
	}
	while(curNode!=NULL &&curNode->key!=key)
	{     						// find  node
		parNode=curNode;
		if(key<curNode->key)
			curNode=curNode->left;
		else
			curNode=curNode->right;
	}
	if(curNode==NULL){
		printf("%d is not in the tree\n",key);
		return node;
	}
	if (curNode->left==NULL && curNode->right==NULL)        //node is leaf 
	{
		if (parNode->left==curNode)
			parNode->left=NULL;
		else
			parNode->right=NULL;
		
	}
	else if (curNode->left!=NULL &&curNode->right!=NULL)          // two childnodes
	{
		succ=curNode->right;
		while(succ->left!=NULL){
			succ_p=succ;
			succ=succ->left;
		}
		if(curNode->right==succ)
		{
			if(parNode->left==curNode)
				parNode->left=succ;
			else
				parNode->right=succ;
			succ->left=curNode->left;
		}else{
			succ_p->left=NULL;
			if(parNode->left==curNode)
				parNode->left=succ;
			else
				parNode->right=succ;
			succ->left=curNode->left;
			succ->right=curNode->right;
		}

	}
	else                                      // with one childnode
	{
		if(curNode->left!=NULL)
			childNode=curNode->left;
		else
			childNode=curNode->right;
		if(parNode->left==curNode)
			parNode->left=childNode;
		else
			parNode->right=childNode;
	}
	free(curNode);
	return node;	
}

int main(void){
	TreeNode*t=NULL;
	int ch=-1;
	int key;
	char  temp;
	while (ch!=5)
	{
		printf("------options list:\n");
		printf("------Intert     (1)\n");
		printf("------Delete     (2)\n");
		printf("------Find key   (3)\n");
		printf("------Print tree (4)\n");
		printf("------out        (5)\n");
		printf("------option:");
		scanf("%d",&ch);
		switch(ch)
		{
                        case 1:
				printf("Enter the key:");
				scanf("%d",&key);
				t=insertNode(t,key);
				printf("%d insert succeeded\n",key);
				break;
			case 2:
				printf("Delete value:");
				scanf("%d",&key);
				t=deleteNode(t,key);
				break;
			case 3:
				printf("find  value:\n");
				scanf("%d",&key);
				if (findNode(t,key)!=NULL)
					printf("%d is in the tree\n",key);
				else
					printf("%d is not in the tree\n",key);
				break;
			case 4:
				printf("\nprinting-inorder (i)\nprinting-preorder (r)\nprinting-postorder (p):\n");
				getchar();
				scanf("%c",&temp);
				if (temp=='i'){
					printf("Inorder:");
					printInorder(t);
				}
				else if(temp=='r')
				{
					printf("Preorder:");
					printPreorder(t);
				}
				else
				{
					printf("Postorder:");	
					printPostorder(t);
				}
				printf("\n");
				break;
			case 5:
				printf("Thanks Bye!\n");
				break;
			default:
				printf("Plz enter the number rightly\n");

			
		}
	}

	return 0;
	
}
