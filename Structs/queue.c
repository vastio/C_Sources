/**
 * Definizione della struttura dati queue: FIFO
 */


#include "structs.h"


static int size;



/* queue_is_empty()
 * Return 1 if queue is empty.
 * Return 0 if queue is NOT empty.
 */
int queue_is_empty(Nodo *head) {
	// Se head punta a NULL
	// allora lo stack e vuoto
	if (head == NULL)
		return 1;
	else
		return 0;
} /*-*/



/* enqueue()
 * Inserisce un elemento in coda
 * Return 1 se inserimento OK
 * Return < 0 se qualche problema
 */
int enqueue(Nodo **head, Nodo **tail, void *value, size_t d_size) {

	Nodo *newnodo, *temp;
	int i;

	// Allocazione memoria nuovo nodo
	if ((newnodo = (struct Nodo *) malloc(sizeof(struct Nodo))) == NULL)
		return -1;

	// Allocazione memoria dato da inserire nel nodo
	if ((newnodo->data = malloc(d_size)) == NULL)
		return -1;
	
	// Allocazione memoria per il dato da inserire nel nuovo nodo
	// Si assume che il tipo char sia un byte
	for (i = 0; i < d_size; i++)
		*(char *)(newnodo->data + i) = *(char *)(value + i);

	// Il nuovonodo punta a NULL ed incremento il contatore di nodi
	newnodo->next = NULL;
	size++;
	
	// Sistemazione del nodo nella lista
	if (*head == NULL && *tail == NULL) {
		// Coda vuota
		*head = newnodo;
		*tail = newnodo;
	}
	else {
		// Coda con elementi
		temp = *tail;
		temp->next = newnodo;
		*tail = newnodo;
	}
	
	return 1;
} /*-*/



/* dequeue()
 * Ritorna l'elemento in cima alla coda
 */
void *dequeue(Nodo **head) {

	Nodo *temp;
	void *value;

	temp = *head;
	*head = temp->next;
	value = temp->data;

	free(temp);
	size--;

	return value;
} /*-*/
