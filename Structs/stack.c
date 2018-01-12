/**
 * Definizione della struttura dati stack: LIFO
 */

#include "structs.h"


/* empty()
 * Return 1 if stack is empty.
 * Return 0 if stack is NOT empty.
 */
int empty(Nodo *head) {
	// Se head punta a NULL
	// allora lo stack e vuoto
	if (head == NULL)
		return 1;
	else
		return 0;
} /*-*/



/* stack_push()
 * Inserisce un elemento in testa allo stack.
 * Return 1 se inserimnento OK.
 * Return valore < 0 se incontra un errore
 */
int stack_push(Nodo **head, void *value, size_t d_size) {

	Nodo *newnodo;
	int i;
	
	// Allocazione memoria nuovo nodo
	if ((newnodo = (struct Nodo *) malloc(sizeof(struct Nodo))) == NULL)
		return -1;

	// Allocazione memoria dato da inserire nel nodo
	if ((newnodo->data = malloc(d_size)) == NULL)
		return -1;

	// Copia per byte del valore nel nuovo nodo
	for (i = 0; i < d_size; i++)
		*(char *)(newnodo->data + i) = *(char *)(value + i);

	// Sistemazione del nodo in testa alla lista
	newnodo->next = *head;
	*head = newnodo;
	
	return 1;
} /*-*/
