#include<stdio.h>
#include<stdlib.h>
int a[10];
int i=0;
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
int inorder(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    inorder(root->left);
    a[i]=root->data;
    i++;
    inorder(root->right);
    return i;
}

int s=0;

int sum(struct node* root)
{
    int b= inorder(root);
    for(int i=0;i<b;i++)
    {
        s+=a[i];
    }
    return i;

}
int sumtree(struct node* root)
{
    int suml=sum(root->left);
    i=0;

    int sumr=sum(root->right);
    return suml+sumr;
}
int main()
{
    struct node* root=create();
   int a= sumtree(root);
   if(a==root->data)
   {
    printf("\nsumtree");
   }
   else{
    printf("\n not a sum tree");
   }
}