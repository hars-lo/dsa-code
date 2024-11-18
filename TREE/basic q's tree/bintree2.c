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
struct node* inorderpre(struct node* root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->left;
    }
    return root;
}
main()
{    
    struct node* root=NULL;
    root=create();
    struct node* ans= inorderpre(root);
    printf("\n%d is inorder successor of root",ans->data);   
}