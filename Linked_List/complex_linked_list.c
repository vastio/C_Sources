/**
 * Svuluppo di funzioni complesse sulle linked list
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>



// Definizione dato
typedef struct User {
	char alias[15];
	int age;
} User;


// Definizione nodo della lista
typedef struct Nodo {
    struct User *user;
    struct Nodo *next;
} Nodo;



// Aggiunge un nuovo utente
User *add_new_user(void) {

    User *user;
	
    // Allocazione memoria
    if ((user = (struct User*) malloc(sizeof(struct User))) == NULL) {
        printf("[!!] Errore allocazione memoria");
        exit(EXIT_FAILURE);
    }
	
    printf("\n[=>] Inserisci alias: ");
    scanf("%15s", user->alias);
    printf("\n[=>] Inserisci eta: ");
    scanf("%d", &user->age);

    return user;
} /*-*/


// Stampa della list
void print_list(Nodo *head) {
    Nodo *temp = head;
    User *user;

    printf("\n[*************************]\n");
    while (temp != NULL) {
        user = temp->user;

        printf("----\n");
        printf("[<>] %s\n", user->alias);
        printf("[<>] %d\n", user->age);
        printf("\n----");

        temp = temp->next;
    }
    // Scorrimento e stampa della lista
    printf("\n[*************************]\n");
} /*-*/


// Aggiounge in testa alla lista un nuovo dato
int push(User *user, Nodo **head) {

    Nodo *new_nodo;

    // Allocaizone memoria nuovo nodo
    if ((new_nodo = (struct Nodo*) malloc(sizeof(struct Nodo))) == NULL) {
        printf("[!!] Errore allocazione memoria");
        exit(EXIT_FAILURE);
    }

    // Assegnazione dato
    new_nodo->user = user;

    // Sistemazione nodo in testa
    new_nodo->next = *head;
    *head = new_nodo;

    return 1;
} /*-*/


// Aggiunge in coda alla lista un nuovo dato
int pop(User *user, Nodo **head) {

  Nodo *new_nodo, *temp;

  // Allocaizone memoria nuovo nodo
  if ((new_nodo = (struct Nodo*) malloc(sizeof(struct Nodo))) == NULL) {
    printf("[!!] Errore allocazione memoria");
    exit(EXIT_FAILURE);
  }
  
  // Assegnazione dato
  new_nodo->user = user;

  // Sistemazione nodo in coda
  if (head == NULL) { // Lista ancora vuota
    new_nodo->next = *head;
    *head = new_nodo;
  }
  else { // Lista con elementi

    temp = *head;

    // Scorrimento della lista fino alla fine
    while (temp->next != NULL)
      temp = temp->next;

    // collocaizone nuovo nodo
    new_nodo->next = NULL;
    temp->next = new_nodo;
  }
  
  return 1;
} /*-*/



// Cerac per alias  
int search(char *name, Nodo *head) {

  Nodo *temp = head;
  int found = 0;

  while (temp != NULL) {

    if (strncmp(name, temp->user->alias, 15) == 0) {
      found = 1;
      break;
    }
    temp = temp->next;
  }
  
  return found;
} /*-*/



// MAIN
int main(int argc, char *argv[]) {

    char ch;
    char alias[15];
    Nodo *head = NULL;


    // Titolo
    printf("\n[****] <> Linked List <> [****]\n\n");

    // Menu
    while (ch != 'q') {
        printf("[1] Inserisci valore in testa.\n");
        printf("[2] Inserisci valore in coda.\n");
        printf("[3] Cerca per alias.\n");
        printf("[4] Elimina valore.\n");
        printf("[5] Reverse della lista.\n");
        printf("[6] Stampa lista.\n");
        printf("[q] ESCI.\n");

        printf("\n[=>] Scelta: ");
        scanf(" %c", &ch);

        switch (ch) {
        case '1' :
	  push(add_new_user(), &head);
	  break;
	case '2' :
	  pop(add_new_user(), &head);
	  break;
	case '3' :
	  printf("[=>] Inserisci alias da cercare: ");
	  scanf("%15s", alias);
	  if (search(alias, head))
	    printf("[*_*] Alias trovato nella lista.\n");
	  else
	    printf("[*-*] Alias non presente nella lista.\n");
	  break;
        case '6' :
	  print_list(head);
	  break;
        case 'q' :
	  printf("\n\n[.. :) ..] Bye Bye...\n\n");
	  break;
        }
    }

    return 0;
}
