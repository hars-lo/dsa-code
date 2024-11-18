#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* create(struct node* head,int d)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->next=NULL;
    new->next=head;
    head=new;
    return head;
}
struct node* reverse(struct node* head)
{
    struct node* current=head;
    struct node* prev=NULL;
    struct node* next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
void print(struct node* head) {
    struct node* temp = head;
    if (head == NULL) {
        printf("empty\n");
    } else {
        while (temp != NULL) {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL) {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}
void add(struct node* head1, struct node* head2) {
    struct node* l1 = reverse(head1);
    struct node* l2 = reverse(head2);
    struct node* head3 = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry > 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        head3 = create(head3, sum);
    }
    printf("\nResultant: ");
    print(head3);
}

int main()
{
  struct node* head1=NULL;
  struct node* head2=NULL;
  int n1,n2;
  printf("\nEnter first number: ");
  scanf("%d",&n1);
  printf("\nEnter second number: ");
  scanf("%d",&n2);
  while(n1!=0)
  {
    head1=create(head1,n1%10);
    n1=n1/10;
  }
   while(n2!=0)
  {
    head2=create(head2,n2%10);
    n2=n2/10;
  }
  printf("\nFirst Number: ");
  print(head1);
  printf("Second Number: ");
  print(head2);
  add(head1,head2);
}