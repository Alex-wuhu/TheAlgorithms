#include"Create_T.cpp"
#include<stack>
using namespace std;
//recursively traverse
void preTraverse(TreeNode* root)
{
    if(root==nullptr)
        return;
    cout<<root->value<<" ";
    preTraverse(root->left);
    preTraverse(root->right);

}
void InorderTraverse(TreeNode* root)
{
    if(root==nullptr)
        return ;
    InorderTraverse(root->left);
    cout<<root->value<<" ";
    InorderTraverse(root->right);
}
void PostorderTraverse(TreeNode* root)
{
    if(root==nullptr)
        return;
    PostorderTraverse(root->left);
    PostorderTraverse(root->right);
    cout<<root->value<<" ";
}
void Preorder(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* node=root;
    s.emplace(node);
    while(!s.empty())
    {
        TreeNode* cur=s.top();
        s.pop();
        if(cur->right!=nullptr)
            s.emplace(cur->right);
        if(cur->left!=nullptr)
            s.emplace(cur->left);
        cout<<cur->value;
    }
    cout<<endl;
}

int main()
{
    TreeNode* root=new TreeNode(0);
    Create_Tree(root);
    //traverse
    preTraverse(root);
    cout<<endl;
    InorderTraverse(root);
    cout<<endl;
    PostorderTraverse(root);
    cout<<endl;
    Preorder(root);
    Destory_Tree(root);

    return 0;
}