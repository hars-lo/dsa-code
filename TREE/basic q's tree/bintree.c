#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create()
{
    int x;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    printf("  Enter Data (enter -1 for no node): ");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    new->data=x;
    printf("\nEnter the left child of %d",x);
    new->left=create();
    printf("\nEnter right side of %d",x);
    new->right=create();
    return new;
}
void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf(" %d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);                              
    postorder(root->right);
    printf(" %d\t",root->data);
}
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        count++;
    }
    inorder(root->left);
    printf(" %d\t",root->data);
    inorder(root->right);
}
void noofleaf(struct node* root)
{
   printf("\nThe number of leaf nodes are %d",count);
}
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else{
        return y;
    }
}
int  height(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    } 
    int left=height(root->left);
    int right=height(root->right);
    int ans= max(left,right)+1;
    return ans;
}
int diameter(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3= height(root->left) +1+ height(root->right);
    int a= max(op1,op2);
    return  max(op3,a);
}
main()
{
    struct node* root=0;
    root=create();
    printf("Preorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\ninorder traversal: ");
   inorder(root);
   noofleaf(root);
   int h=height(root);
   printf("\nheight=%d",h);
   int d=diameter(root);
   printf("\ndiameter=%d",d);
}