#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp_x;
    int exp_y;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp_x, int exp_y) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp_x = exp_x;
    newNode->exp_y = exp_y;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** poly, int coeff, int exp_x, int exp_y) {
    struct Node* newNode = createNode(coeff, exp_x, exp_y);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addNode(struct Node** poly, int coeff, int exp_x, int exp_y) {
    if (coeff == 0) return;
    struct Node* temp = *poly;
    struct Node* prev = NULL;
    while (temp != NULL && (temp->exp_x > exp_x || (temp->exp_x == exp_x && temp->exp_y > exp_y))) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL && temp->exp_x == exp_x && temp->exp_y == exp_y) {
        temp->coeff += coeff;
        if (temp->coeff == 0) {
            if (prev == NULL) {
                *poly = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
        }
    } else {
        struct Node* newNode = createNode(coeff, exp_x, exp_y);
        if (prev == NULL) {
            newNode->next = *poly;
            *poly = newNode;
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
    }
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    for (struct Node* t1 = poly1; t1 != NULL; t1 = t1->next) {
        for (struct Node* t2 = poly2; t2 != NULL; t2 = t2->next) {
            int coeff = t1->coeff * t2->coeff;
            int exp_x = t1->exp_x + t2->exp_x;
            int exp_y = t1->exp_y + t2->exp_y;
            addNode(&result, coeff, exp_x, exp_y);
        }
    }
    return result;
}

void printPolynomial(struct Node* poly) {
    struct Node* temp = poly;
    while (temp != NULL) {
        if (temp->coeff > 0 && temp != poly) printf(" + ");
        if (temp->coeff < 0) printf(" - ");
        printf("%dx^%dy^%d", abs(temp->coeff), temp->exp_x, temp->exp_y);
        temp = temp->next;
    }
    printf("\n");
}

void inputPolynomial(struct Node** poly) {
    int n, coeff, exp_x, exp_y;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient, exponent of x, and exponent of y (space-separated): ");
        scanf("%d %d %d", &coeff, &exp_x, &exp_y);
        appendNode(poly, coeff, exp_x, exp_y);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    printf("Enter the first polynomial:\n");
    inputPolynomial(&poly1);

    printf("Enter the second polynomial:\n");
    inputPolynomial(&poly2);

    struct Node* result = multiplyPolynomials(poly1, poly2);

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    printf("Product: ");
    printPolynomial(result);

    return 0;
}