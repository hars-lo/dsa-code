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
int identical(struct node* r1,struct node* r2)
{
    int left,right;
    if(r1==NULL && r2==NULL)
    {
        return 0;
    }
    if(r1==NULL && r2!=NULL)
    {
        return -1;
    }
    if(r1!=NULL && r2==NULL)
    {
        return -1;
    }
    if(r1->data!=r2->data)
    {
      return -1; 
    }
    left=identical(r1->left,r2->left);
    right=identical(r1->right,r2->right);
    if(left==0 && right==0)
    {
        return 0;
    }
    return -1;

}
main()
{
    struct node* root1=NULL;
    struct node* root2=NULL;
    root1=create();
    root2=create();
   int a= identical(root1,root2);
   if(a==0)
   {
    printf("\nboth trees are identical");
   }
   else{
    printf("\nnot identical");
   }
}