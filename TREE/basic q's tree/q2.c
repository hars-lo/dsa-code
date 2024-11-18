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
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf(" %d\t",root->data);
    inorder(root->right);
}
int  max(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int mx=root->data;
    int lft_max=max(root->left);
    int rht_max=max(root->right);
    if(mx<lft_max)
    {
        mx=lft_max;
    }
    if(mx<rht_max){
        mx=rht_max;
    }
    return mx;
}
main()
{
    struct node* root=create();
    inorder(root);
    printf("\n");
   int a= max(root);
   printf("\nmax=%d",a);
}