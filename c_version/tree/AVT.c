#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a)>(b)) ?(a) :(b))
typedef struct avl_node{
	struct avl_node *left,*right;
	int data;
}avl_node;
void display(avl_node*node)
{
	if(node!=NULL){
		printf("(");
		display(node->left);
		printf("%i",node->data);
		display(node->right);
		printf(")");
	}
}
int get_height(avl_node*node)
{
	int height=0;
	if(node!= NULL)
		height=1+max(get_height(node->left),get_height(node->right));
	return height;
}
int get_height_diff(avl_node*node)
{
	if(node==NULL)
		return 0;
	return get_height(node->left) - get_height(node->right);
}
avl_node*rotate_left(avl_node* pa)
{
	avl_node*child=pa->right;
	pa->right=child->left;
	child->left=pa;
	return child;
}
avl_node*rotate_right(avl_node*pa)
{
	avl_node*child=pa->left;
	pa->left=child->right;
	child->right=pa;
	return child;
}
avl_node*rotate_left_right(avl_node*pa)
{
	avl_node*child=pa->left;
	pa->left=rotate_left(child);
	return rotate_right(pa);
}
avl_node*rotate_right_left(avl_node*pa)
{
	avl_node*child=pa->right;
	pa->right=rotate_right(child);
	return rotate_left(pa);
}
avl_node*rebalance(avl_node**node)
{
	int height_diff=get_height_diff(*node);
	if (height_diff>1){
		if(get_height_diff((*node)->left)>0)
			*node=rotate_right(*node);
		else
			*node=rotate_left_right(*node);
	}
	else if(height_diff<-1){
		if(get_height_diff((*node)->right)<0)
			*node=rotate_left(*node);
		else
			*node=rotate_right_left(*node);
	}
	return *node;
}
avl_node*avl_add(avl_node **root,int key)
{
	if(*root==NULL){
		*root=(avl_node*)malloc(sizeof(avl_node));
		if (*root==NULL)
			exit(1);
		(*root)->data=key;
		(*root)->left=(*root)->right=NULL;
	}
	else if(key<(*root)->data){
		(*root)->left=avl_add(&((*root)->left),key);
		*root=rebalance(root);
	}
	else if(key>(*root)->data){
		(*root)->right=avl_add(&((*root)->right),key);
		*root=rebalance(root);
	}
	else
		exit(1);
	return *root;
}
avl_node*avl_delete(avl_node*root,int key)
{
	if (root==NULL){
		printf("can't find %i",key);
		exit(1);
	}
	else if(key>root->data){
		root->right=avl_delete(root->right,key);
		root=rebalance(&root);
	}
	else if(key<root->data){
		root->left=avl_delete(root->left,key);
		 root=rebalance(&root);
	}
	else
	{
		if (root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if (root->left!=NULL && root->right==NULL)
		{
			avl_node*temp=root->left;
			free(temp);
			root=root->left;
		}
		else if(root->right!=NULL && root->left==NULL)
		{
			avl_node*temp=root->right;
			free(temp);
			root=root->right;
		}
		else
		{
			avl_node*temp=root->right;
			while(temp->left!=NULL){
				temp=temp->left;
			}
				root->data=temp->data;
				free(temp);
		}
	}	

	return root;
}
void main(){
	avl_node*root=NULL;
	avl_add(&root,7);
	avl_add(&root,6);
	avl_add(&root,5);
	avl_add(&root,4);
        avl_add(&root,3);
        avl_add(&root,2);
        avl_add(&root,1);
        avl_add(&root,8);
        avl_add(&root,9);
	display(root);
	printf("  ");
	printf("after delete 1 \n");
	avl_delete(root,1);
	display(root);
}
   



