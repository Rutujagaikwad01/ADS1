#include<iostream>
#include<cstdlib>
using namespace std;
class BST
{
    public:
    int data;
    BST* left;
    BST* right;
    BST(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};
void insert(BST* &root,int val)
{
    if(root==NULL)
    {
        root=new BST(val);
    }
    else
    {
        if(val<=root->data)
        {
            insert(root->left,val);
        }
        else
        {
            insert(root->right,val);
        }
    }
}
void create(BST* &root)
{
    int val,no_node;
    
    cout<<"\nEnter root node: ";
    cin>>val;
    root=new BST(val);
    cout<<"\nEnter no. of nodes to be inserted in BST: ";
    cin>>no_node;
    cout<<"\nEnter The values of nodes: ";
    for(int i=0;i<no_node;i++)
    {
        cin>>val;
        insert(root,val);
    }
}

void preorderTraversal(BST* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
int find(BST* root,int x)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==x)
    {
        cout<<"\nNode found : "<<root->data;
    }
    if(x>root->data)
        return(find(root->right,x));
    return(find(root->left,x));
}
BST* find_min(BST* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
   // cout<<"\nMIN node:  "<<root->data;
   return root;
}
void find_max(BST* root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    cout<<"\nMAX node:  "<<root->right;
}
BST* Delete(BST* root,int val)
{
    if(root==NULL)
    {
        return root;
    }
    else if(val<root->data)     { root->left=Delete(root->left,val); }
    else if(val>root->data)     { root->right=Delete(root->right,val); }
    else
    {
        //case 1 & 2 
        if(root->left==NULL) //&& root->right==NULL)
        {
            BST* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            BST* temp=root->left;
            delete root;
            return temp;
        }
        //case 3
        else
        {
            BST* temp=find_min(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
    BST* root=NULL;
    create(root);
    preorderTraversal(root);
    find(root,10);
    find_max(root);
    find_min(root);
    cout<<"\nDELETE:::: ";
    Delete(root,8);
    preorderTraversal(root);
}