#include"Create_T.cpp"
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
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
void Inorder(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* node=root;
    while(!s.empty()||node!=nullptr)
    {
        while(node!=nullptr)
        {
            s.emplace(node);
            node=node->left;
        }
        TreeNode* cur=s.top();
        cout<<cur->value;
        s.pop();

        if(cur->right!=nullptr)
            node=cur->right;

    }
    cout<<endl;
   
}
void Postorder(TreeNode* root)
{
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    TreeNode* node=root;
    s1.emplace(node);
    while(!s1.empty())
    {
        TreeNode* cur=s1.top();
        s1.pop();
        s2.emplace(cur);
        if(cur->left!=nullptr)
            s1.emplace(cur->left);

        if(cur->right!=nullptr)
            s1.emplace(cur->right);
    }
    while(!s2.empty())
    {
        TreeNode* cu=s2.top();
        cout<<cu->value;
        s2.pop();
    }
    cout<<endl;
   
}
void Levelorder(TreeNode* root)
{
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty())
    {
        TreeNode* cur=q.front();
        q.pop();
        cout<<cur->value;
        if(cur->left!=nullptr)
            q.emplace(cur->left);
        if(cur->right!=nullptr)
            q.emplace(cur->right);
        /* code */
    }
    cout<<endl;    

}
void Z_print(TreeNode* root)
{
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty())
    {

        vector<int> ans;
        int flag=1;
        for(int i=0;i<q.size();i++)
        {
            TreeNode* cur=q.front();
            ans.emplace_back(cur->value);
            q.pop();
            if(cur->right!=nullptr)
                q.emplace(cur->right);
            if(cur->left!=nullptr)
                q.emplace(cur->left);
        }
        if(flag==-1)
        reverse(ans.begin(),ans.end());

        flag*=-1;
        for(auto x:ans)
            cout<<x;
    }
    cout<<endl;    
}
int main()
{
    TreeNode* root=new TreeNode(0);
    Create_Tree(root);
    Preorder(root);
    Inorder(root);
    Postorder(root);
    Levelorder(root);
    Z_print(root);
    Destory_Tree(root);

    return 0;
}