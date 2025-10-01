#include <stdio.h>
#include <stdlib.h>

struct fou {
    int val;
    struct fou *next;
    struct fou *prev;
};

void insertHead(struct fou **tete, int val) {
    struct fou *newfou = (struct fou*) malloc(sizeof(struct fou));
    newfou->val = val;
    if (*tete == NULL) {
        newfou->next = newfou;
        newfou->prev = newfou;
        *tete = newfou;
    } else {
        struct fou *last = (*tete)->prev;
        newfou->next = *tete;
        newfou->prev = last;
        last->next = newfou;
        (*tete)->prev = newfou;
        *tete = newfou;
    }
}

void insertTail(struct fou **tete, int val) {
    struct fou *newfou = (struct fou*) malloc(sizeof(struct fou));
    newfou->val = val;
    if (*tete == NULL) {
        newfou->next = newfou;
        newfou->prev = newfou;
        *tete = newfou;
    } else {
        struct fou *last = (*tete)->prev;
        newfou->next = *tete;
        newfou->prev = last;
        last->next = newfou;
        (*tete)->prev = newfou;
    }
}

void display(struct fou *tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    struct fou *cur = tete;
    printf("Liste : ");
    do {
        printf("%d ", cur->val);
        cur = cur->next;
    } while (cur != tete);
    printf("\n");
}

int main() {
    struct fou *tete = NULL;
    insertHead(&tete, 10);
    insertHead(&tete, 20);
    insertTail(&tete, 30);
    insertTail(&tete, 40);
    display(tete);
    return 0;
}
