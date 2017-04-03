#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *root = NULL;

struct node * insertBST(struct node *root,int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        if(root->data >= temp->data)
        {
            if(root->left == NULL)
            {
                root->left = temp;
            }
            else
            {
                insertBST(root->left,temp->data);
            }
        }
        if(root->data < temp->data)
        {
            if(root->right == NULL)
            {
                root->right = temp;
            }
            else
            {
                insertBST(root->right,temp->data);
            }
        }
    }
    return root;
}
void inorderTraversal(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<"\t";
    inorderTraversal(root->right);
}
void preorderTraversal(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<"\t";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}
void postorderTraversal(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout<<root->data<<"\t";
}
int height(struct node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int left = height(root->left);
        int right = height(root->right);
        if(left > right)
        {
            return left+1;
        }
        else
        {
            return right+1;
        }
    }
}
int main()
{
    int choice,data;
    while(1)
    {
        cout<<"\n1.Insert\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n5.Height\n6.exit\n\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter data to insert : ";
                cin>>data;
                root = insertBST(root,data);
                break;
            case 2:
                cout<<"inorder traversal : ";
                inorderTraversal(root);
                break;
            case 3:
                cout<<"preorder traversal : ";
                preorderTraversal(root);
                break;
            case 4 :
                cout<<"postorder traversal : ";
                postorderTraversal(root);
                break;
            case 5 :
                cout<<"Height of the tree is : ";
                cout<<height(root);
                break;
            case 6 : exit(0);
            default:cout<<"Invalid choice.\n";
        }
    }
}
