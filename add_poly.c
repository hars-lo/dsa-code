#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int exp;
    struct node *next;
};
struct node* create(struct node* head,int co,int ex)
{
    struct node* temp=head;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->coef=co;
    new->exp=ex;
    new->next=NULL;
    if(head==NULL|| head->exp<ex)
    {
        new->next=head;
        head=new;
    }
    else{
        while(temp->next!=NULL && temp->next->exp >= ex)
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
    struct node* temp=head;
    if(head==NULL)
    {
        printf("\npolynomial is empty!!!\n");
    }
    else{
        while(temp!=NULL)
        {
            printf("(%dX^%d)",temp->coef,temp->exp);
            temp=temp->next;
            if(temp!=NULL)
            {
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }

    }
}
struct node* add(struct node* head1,struct node* head2)
{
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exp==ptr2->exp)
        {
            head3=create(head3,ptr1->coef+ptr2->coef,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp)
        {
            head3=create(head3,ptr1->coef,ptr1->exp);
            ptr1=ptr1->next;
        }
        else
        {
            head3=create(head3,ptr2->coef,ptr2->exp);
            ptr2=ptr2->next;
        }
    }

    while(ptr1!=NULL)
    {
        head3=create(head3,ptr1->coef,ptr1->exp);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        head3=create(head3,ptr2->coef,ptr2->exp);
        ptr2=ptr2->next;
    }
    return head3;
}
int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    head1=create(head1,5,6);
    head1=create(head1,6,4);
    head1=create(head1,2,3);
    head2=create(head2,8,6);
    head2=create(head2,3,2);
    head2=create(head2,4,1);
    head2=create(head2,5,0);
    printf("First Polynomial: ");
    print(head1);
    printf("\nsecond polynomial: ");
    print(head2);
    printf("\nResultant polynomial :");
   struct node* res= add(head1,head2);
    print(res);
    return 0;
}