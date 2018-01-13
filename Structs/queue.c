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


