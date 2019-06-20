#include<bits/stdc++.h>
using namespace std;
struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* Min(BstNode* root)
{
    BstNode* current=  root;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
BstNode* deleteNode(BstNode* root,int data)
{
    if(root==NULL) return root;
    else if(data<root->data)
    {
        root->left=deleteNode(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=deleteNode(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        {
            root=root->right;
            return root; //return must
        }
        else if(root->right==NULL)
        {
            root=root->left;
            return root; //return must
        }

        BstNode* temp=Min(root->left);
        root->data=temp->data;
        root->left=deleteNode(root->left,temp->data);
    }
    return root;
}
BstNode* insert(BstNode* root,int data)
{
    if(root==NULL)
    {
        root=new BstNode();
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}
void inorder(BstNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}
void pre(BstNode* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"  ";
        pre(root->left);
        pre(root->right);
    }
}
int main()
{
    cout<<"Enter total elements do you want to insert : ";
    int n;
    cin>>n;
    BstNode* root=NULL;
    for(int i=0; i<n; i++)
    {
        int value;
        cin>>value;
        root=insert(root,value);
    }
    inorder(root);
    cout<<endl;
    root=deleteNode(root,5);
    cout<<"In = ";
    inorder(root);
    cout<<endl;
    pre(root);
}
