/**
 * Header file per la definizione delle strutture dati
 */

#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>



// Generico nodo dello stack
typedef struct Nodo {
	void *data;
	struct Nodo *next;
} Nodo;



// Prototipo funzioni dello stack
int stack_is_empty(Nodo *head);
int stack_push(Nodo **head, void *value, size_t d_size);
void *stack_pop(Nodo **head);
void *stack_peek(Nodo *head);
int stack_size(void);
int search(Nodo *head, void *data);



#endif
