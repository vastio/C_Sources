/**
 * Implementazione di una semplice linked list
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node *next;
} Node;


// Add a value to start of the list
int push(Node **head, int num) {

    Node *new_node;

    // Alloca spazio per il nuovo nodo
    if ((new_node = (Node *) malloc(sizeof(Node))) == NULL) {
        printf("[!] Errore allocazione memoria per il nuovo nodo!");
        exit(EXIT_FAILURE);
    }

    // Assegna il valore al nuovo nodo
    new_node->value = num;

    // Collegamento in testa
    new_node->next = *head;
    *head = new_node;

    return 1;
} /*-*/


// Inserisce un valore in coda alla lista
int pop(Node **head, int num) {

    Node *new_node, *tmp_node;

    // Alloca spazio per il nuovo nodo
    if ((new_node = (Node *) malloc(sizeof(Node))) == NULL) {
        printf("[!] Errore allocazione memoria per il nuovo nodo!");
        exit(EXIT_FAILURE);
    }

    new_node-> value = num;

    // Caso di lista ancora vuota
    if (*head == NULL) {
        new_node->next = *head;
        *head = new_node;
    } // Caso di lista con elementi
    else {
        tmp_node = *head;

        // Scorre la lista fino all'ultimo nodo
        while (tmp_node->next != NULL)
            tmp_node = tmp_node->next;

        new_node->next = NULL;
        tmp_node->next = new_node;
    }
    return 1;
} /*-*/


// Stampa l'intera lista
void print_list(Node *head) {

    Node *tmp = head;
    char ch;

    printf("\n***************\n");
    while (tmp != NULL) {
        printf(" %d ", tmp->value);

        tmp = tmp->next;
    }
    printf("\n***************\n");
    printf("Premi 'q' un tasto per uscire: ");
    scanf(" %c", &ch);
}


// MAIN
int main(int argc, char *argv) {

    Node *head = NULL;  // Testa della lista
    char ch;
    int num;

    printf("\n[****] Implementazione di una linked list in C [****]\n\n");

    // MENU
    while (ch != '9') {
        printf("\n\n[**] Menu [**]\n");
        printf("[1] Inserisci un  valore in testa.\n");
        printf("[2] Inserisci un  valore in coda.\n");
        printf("[5] Stampa intera lista.\n");
        printf("[9] Esci!\n\n");

        printf("Scelta: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1' :
                printf("Inserisci il valore da inserire in testa: ");
                scanf("%d", &num);
                push(&head, num);
                break;
            case '2' :
                printf("Inserisci il valore da inserire in coda: ");
                scanf("%d", &num);
                pop(&head, num);
                break;
            case '5' :
                printf("[**] Stampa lista [**]\n");
                print_list(head);
                break;
            case '9' :
                printf("Bye Bye...\n");
                break;
        }
    }

    return 0;
}
