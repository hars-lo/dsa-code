#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coef;
    int exp;
    struct Node* next;
};
struct Node* insert(struct Node* poly, int coef, int exp) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;

    if (poly == NULL || exp > poly->exp) {
        temp->next = poly;
        poly = temp;
        return poly;
    }

    struct Node* current = poly;
    while (current->next != NULL && current->next->exp >= exp) {
        current = current->next;
    }

    if (current->exp == exp) {
        current->coef += coef;
        free(temp); // Avoid memory leak
        return poly;
    }

    temp->next = current->next;
    current->next = temp;
    return poly;
}

void print(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Node* current = poly;

    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL && current->next->coef > 0) {
            printf(" + ");
        }
        current = current->next;
    }

    printf("\n");
}

struct Node* add(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            result = insert(result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            result = insert(result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            result = insert(result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        result = insert(result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insert(result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}
int main() {
    struct Node* poly1 = NULL;
    poly1 = insert(poly1, 12, 4);
    poly1 = insert(poly1, 2, 2);
    poly1 = insert(poly1, 10, 0);

    struct Node* poly2 = NULL;
    poly2 = insert(poly2, 9, 3);
    poly2 = insert(poly2, 8, 2);
    poly2 = insert(poly2, 1, 1);

    printf("First polynomial: ");
    print(poly1);

    printf("Second polynomial: ");
    print(poly2);
    struct Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);
    return 0;
}

	
