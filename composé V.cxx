#include <stdio.h>
#include <stdlib.h>

// Structure de la liste
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau noeud
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation de mémoire\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour insérer un élément dans la liste triée
Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// Fonction pour afficher la liste
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insertion de quelques éléments dans la liste
    head = insertNode(head, 5);
    head = insertNode(head, 10);
    head = insertNode(head, 15);
    head = insertNode(head, 20);

    printf("Liste triée : ");
    printList(head);

    // Insertion d'un nouvel élément
    head = insertNode(head, 12);

    printf("Liste triée après insertion : ");
    printList(head);

    return 0;
}