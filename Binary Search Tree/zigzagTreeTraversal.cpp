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

struct node* insertBST(struct node *root,int data)
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

void printZigzagLevel_1(struct node *root,int i)
{
    if(root == NULL)
    {
        return ;
    }
    if(i == 1)
    {
        cout<<root->data<<"\t";
    }
    else
    {
        printZigzagLevel_1(root->left,i-1);
        printZigzagLevel_1(root->right,i-1);
    }
}
void printZigzagLevel_2(struct node *root,int i)
{
    if(root == NULL)
    {
        return ;
    }
    if(i == 1)
    {
        cout<<root->data<<"\t";
    }
    else
    {
        printZigzagLevel_2(root->right,i-1);
        printZigzagLevel_2(root->left,i-1);
    }
}
void zigzagTraversal(struct node *root)
{
    int h = height(root);
    for(int i=1;i<=h;i++)
    {
        if(i%2 == 0)
        {
            printZigzagLevel_2(root,i);
        }
        else
        {
            printZigzagLevel_1(root,i);
        }
    }
}

int main()
{
    int choice,data;
    while(1)
    {
        cout<<"\n1.Insert\n2.Zigzag Traversal\n3.Height\n4.exit\n\n";
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
                zigzagTraversal(root);
                break;
            case 3:
                cout<<"\nThe height of the tree is : "<<height(root)<<endl;
                break;
            case 4:exit(0);
            default:cout<<"Invalid Choice .\nTry again : ";
        }
    }
}

