#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* create()
{
    int x;
    node* newnode=(node*)malloc(sizeof(node));

    printf("enter data (-1 if no new node)");
    scanf("%d",&x);

    if(x==-1)
    return 0;

    else
    {
        newnode->data=x;
        printf("enter left child of %d",x);
        newnode->left=create();

        printf("enter right child of %d",x);
        newnode->right=create();

        return newnode;
    }
}

node* check(node* root)
{
    if(root->left!=NULL && root->right!=NULL || root->left==NULL && root->right==NULL)
    return root;

    else
    return NULL;
}

node* perfect(node* root)
{
    node* left=check(root->left);
    node* right=check(root->right);

    if(left!=NULL && right!=NULL)
    return root;

    else
    return NULL;
   
}
int main()
{
    node* root;

    root=create();
    
    node* ans=perfect(root);
    
    if(ans!=NULL)
    printf("perfect tree");

    else
    printf("not perfect");

    return 0;
}

    
    
