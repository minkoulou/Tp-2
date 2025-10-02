#include<stdio.h>
#include<stdlib.h>

struct cellule {
    int a;
    struct cellule *suivant;
} cellule;

typedef struct cellule *liste;

int main() {
    liste l = NULL, p, n;

    
    printf("entrer l'element a inserer en tete : ");
    scanf("%d", &cellule.a);
    p = malloc(sizeof(cellule));
    if (l == NULL) {
        l = p;
        p->suivant = l;
        printf("%d->\n", cellule.a);
    } else {
        if (p->suivant != l) {
            p = p->suivant;
        } else {
            if (p->suivant == l) {
                n = p;
                p->suivant = n;
            }
        }
    }


    printf("entrer l'element a inserer en fin : ");
    scanf("%d", &cellule.a);
    p = malloc(sizeof(cellule));
    if (l == NULL) {
        l = p;
        p->suivant = l;
        printf("%d->\n", cellule.a);
    } else {
        p->suivant;
        l = p;
    }
    

    return 0;
}