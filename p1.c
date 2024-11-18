#include<stdio.h>
#include<stdlib.h>
struct node{
   int coef;
   int exp;
   struct node* next;
};
struct node* insert(struct node* head,int co,int ex)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    new->coef=co;
    new->exp=ex;
    new->next=NULL;
    if(head==NULL|| head->exp<ex)
    {
        new->next=head;
        head=new;
    }
    else{
        while(temp->next!=NULL && temp->next->exp>= ex)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    return head;
}
void print(struct node* head)
{
    printf("\n");
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d x^%d",temp->coef,temp->exp);
        temp=temp->next;
        if(temp!=NULL)
        {
            printf(" + ");
        }
    }
}
struct node* add(struct node* l1,struct node* l2)
{
    struct node* p=l1;
    struct node* q=l2;
    struct node* res=NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->exp==q->exp)
        {
            res=insert(res,p->coef+q->coef,p->exp);
            p=p->next;
            q=q->next;
        }
        else if(p->exp > q->exp)
        {
            res=insert(res,p->coef,p->exp);
            p=p->next;
        }
        else{
            res=insert(res,q->coef,q->exp);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        res=insert(res,p->coef,p->exp);
            p=p->next;

    }
    while(q!=NULL)
    {
        res=insert(res,q->coef,q->exp);
            q=q->next;

    }
    return res;
}
int main()
{
    struct node* head1=NULL;
    head1=insert(head1,5,3);
    head1=insert(head1,4,2);
    head1=insert(head1,10,1);
    head1=insert(head1,9,0);
    struct node* head2=NULL;
    head2=insert(head2,11,3);
    head2=insert(head2,11,4);
    head2=insert(head2,11,2);
    head2=insert(head2,11,1);
    print(head1);
    print(head2);
    struct node* ans=add(head1,head2);
    print(ans);
    return 0;
} 