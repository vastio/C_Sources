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




/*
 * Prototipo funzioni dello stack
 */
int stack_is_empty(Nodo *head);
int push(Nodo **head, void *value, size_t d_size);
void *pop(Nodo **head);
void *peek(Nodo *head);
int stack_size(void);
//int search(Nodo *head, void *data);




/*
 * Prototipo funzioni della queue
 */
int queue_is_empty(Nodo *head);
int enqueue(Nodo **head, Nodo **tail, void *value, size_t d_size);
void *dequeue(Nodo **head);


#endif
