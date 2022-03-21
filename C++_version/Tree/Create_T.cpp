#include<iostream>

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode():value(0),left(nullptr),right(nullptr){}
    TreeNode(int v):value(v),left(nullptr),right(nullptr){}

};
void Create_Tree(TreeNode* root)
{
    TreeNode* n1=new TreeNode(1);
    TreeNode* n2=new TreeNode(2);
    TreeNode* n3=new TreeNode(3);
    TreeNode* n4=new TreeNode(4);
    TreeNode* n5=new TreeNode(5);
    TreeNode* n6=new TreeNode(6);
    TreeNode* n7=new TreeNode(7);
    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n1->right=n4;
    n2->left=n5;
    n2->right=n6;
    n4->left=n7;
    
}
void Destory_Tree(TreeNode* root)
{
    TreeNode* d=root;
    if(root==nullptr)
        return ;

    Destory_Tree(d->left);
    Destory_Tree(d->right);
    
    delete d;
}
