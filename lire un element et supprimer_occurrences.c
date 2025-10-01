
#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud de la liste
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insérer un élément à la fin de la liste
void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Afficher la liste
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Supprimer toutes les occurrences d’une valeur
void deleteOccurrences(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    // Cas où la valeur est au début de la liste
    while (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }

    // Parcours du reste de la liste
    while (temp != NULL) {
        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Programme principal
int main() {
    Node* head = NULL;
    int n, i, val, elem;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i+1);
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    printf("\nListe avant suppression :\n");
    printList(head);

    printf("\nEntrez la valeur a supprimer : ");
    scanf("%d", &elem);

    deleteOccurrences(&head, elem);

    printf("\nListe apres suppression de %d :\n", elem);
    printList(head);

    return 0;
}
