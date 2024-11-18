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
void lefttraverse(struct node* root)
{
    if(root==NULL ||( root->left==NULL && root->right==NULL))
    {
        return;
    }
   printf(" %d\t",root->data);
   if(root->left!=NULL)
   {
    lefttraverse(root->left);
   }
}
void leaftraverse(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        printf(" %d\t",root->data);
    }
    leaftraverse(root->left);
    leaftraverse(root->right);
}
void righttraverse(struct node* root)
{
    if(root==NULL ||( root->left==NULL && root->right==NULL))
    {
        return;
    }
   printf(" %d\t",root->data);
   if(root->right!=NULL)
   {
    righttraverse(root->right);
   }
}

main()
{
    struct node* root=create();
    printf("left traversal: ");
    lefttraverse(root->left);
    printf("\n");
    printf("leaf traversal: ");
    leaftraverse(root);
    printf("\nright traversal: ");
    righttraverse(root->right);
}