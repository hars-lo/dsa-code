#include<iostream>
using namespace std;
struct node {
    int xexp;
    int yexp;
    int coef;
    struct node* next;
};
struct node* insert(struct node* head,int xp,int yp,int cf) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->xexp = xp;
    newnode->yexp = yp;
    newnode->coef = cf;
    newnode->next=NULL;
    struct node* temp=head;
    if(head==NULL || (newnode->xexp + newnode->yexp)>(head->xexp + head->yexp)  )
    {
        newnode->next = head;
        head = newnode;
    }
    else{
    while(temp->next!=NULL && (temp->next->xexp + temp->next->yexp)>(newnode->xexp + newnode->yexp))
    {
       temp = temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
    return head;
}
void print(struct node* head)
{
    struct node* t=head;
    while(t!=NULL)
    {
        cout<<t->coef<<" (x^"<<t->xexp<<"y^"<<t->yexp<<")";
        t=t->next;
        if(t!=NULL)
        {
            cout<<" + ";
        }
    }
}
struct node* add(struct node* h1,struct node* h2)
{
    struct node* h3=NULL;
    struct node* t1=h1;
    struct node* t2=h2;
    while(t1!=NULL && t2!=NULL)
    {
        if((t1->xexp==t2->xexp)&& (t1->yexp==t2->xexp))
        {
            h3=insert(h3,t1->xexp,t1->yexp,t1->coef+t2->coef);
            t1=t1->next;
            t2=t2->next;
        }

    }

}
int main()
{
    struct node* h=NULL;
    struct node* k=NULL;
    h=insert(h,2,3,4);
    h=insert(h,4,8,4);
    h=insert(h,3,6,4);
    h=insert(h,1,1,4);
    k=insert(k,2,3,4);
    k=insert(k,4,6,4);
    k=insert(k,4,8,4);
    print(h);
    print(k);
    struct node* ans=add(h,k);
    print(ans);
    return 0;
}