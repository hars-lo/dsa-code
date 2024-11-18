#include<stdio.h>
#include<stdlib.h>
int suM=0;
int a[10];

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
int inorder(node* root)
{
    static i=0;
    
    if(root==NULL)
    return NULL;

    else
    {
        inorder(root->left);
        a[i]=root->data;
        i++;
        inorder(root->right);
    }

    return i;
}

int sum(node* root)
{
    
    int b =inorder(root);
    
    for(int i=0;i<b;i++)
    suM=suM+a[i];

    return suM;
}

int sumtree(node* root)
{

   int suml=sum(root->left);
   suM=0;
   int sumr=sum(root->right);
 printf("%d %d",suml,sumr);
   


   return sumr;

}
int main()
{
    node* root;
    root=create();
    int a=sumtree(root);
    if(root->data==a)
   printf("\nsumtree");
   else
   printf("\nnot a sumtree");
    return 0;
}

    
    
