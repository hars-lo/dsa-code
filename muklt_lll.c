#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node *next;
};

struct node* create(struct node* head, int co, int ex) {
    struct node* temp = head;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coef = co;
    new_node->exp = ex;
    new_node->next = NULL;

    if (head == NULL || head->exp < ex) {
        new_node->next = head;
        head = new_node;
    } else {
        while (temp->next != NULL && temp->next->exp > ex) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exp == ex) {
            temp->next->coef += co;
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    return head;
}

void print(struct node* head) {
    struct node* temp = head;
    if (head == NULL) {
        printf("\nPolynomial is empty!!!\n");
    } else {
        while (temp != NULL) {
            printf("(%dX^%d)", temp->coef, temp->exp);
            temp = temp->next;
            if (temp != NULL) {
                printf(" + ");
            } else {
                printf("\n");
            }
        }
    }
}

struct node* mul(struct node* head1, struct node* head2) {
    struct node* p = head1;
    struct node* head3 = NULL;

    while (p != NULL) {
        struct node* pt = head2;  // Reset pt to the start of head2 for each iteration of p
        int a = p->coef;
        while (pt != NULL) {
            int b = pt->coef;
            head3 = create(head3, a * b, p->exp + pt->exp);
            pt = pt->next;
        }
        p = p->next;
    }

    return head3;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    head1 = create(head1, 5, 6);
    head1 = create(head1, 6, 4);
    head1 = create(head1, 2, 3);

    head2 = create(head2, 8, 6);
    head2 = create(head2, 3, 2);
    head2 = create(head2, 4, 1);
    head2 = create(head2, 5, 0);

    printf("First Polynomial: ");
    print(head1);

    printf("\nSecond Polynomial: ");
    print(head2);

    printf("\nResultant Polynomial: ");
    struct node* res = mul(head1, head2);
    print(res);

    return 0;
}

