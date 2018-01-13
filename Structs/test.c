/*
 * Programma di test delle strutture dati definite in structs.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

#define MAX_NUM 6



// MAIN for int in stack
int main(int argc, char *argv[]) {

	Nodo *head, *tail;
	int i, nums[MAX_NUM] = {12, 34, 5, 66, 90, 88, 22};

	head = tail = NULL;
	
	for (i = 0; i < MAX_NUM; i++) {
		if (enqueue(&head, &tail, &nums[i], sizeof(int)) < 0) {
			fprintf(stderr, "[!] Errore di push nello stack");
			exit(EXIT_FAILURE);
		}
	}

	// Stampa della lista
	while (!queue_is_empty(head))
		printf("%d ", *(int *) dequeue(&head));
	printf("\n");
	
	return 0;
}




// MAIN for string in stack
/*int main(int argc, char *argv[]) {

	Nodo *head = NULL;
	int i;
	char *word[MAX_NUM] = {"Casa", "Chiesa", "Cosa", "Ciao", "World", "Mondo"};

	for (i = 0; i < MAX_NUM; i++) {
		if (push(&head, word[i], sizeof(char) * strlen(word[i])) < 0) {
			fprintf(stderr, "[!] Errore di push nello stack.");
			exit(EXIT_FAILURE);
		}
	}

	printf("Elementi presenti nello stack: %d\n", stack_size());
	
	// Stampa della lista
	while (!stack_is_empty(head))
		printf("%s ", (char *) pop(&head));
	printf("\n");
	
	return 0;
} */


// MAIN for int in stack
/*int main(int argc, char *argv[]) {

	Nodo *head = NULL;
	int i, nums[MAX_NUM] = {12, 34, 5, 66, 90, 88, 22};
	
	for (i = 0; i < MAX_NUM; i++) {
		if (push(&head, &nums[i], sizeof(int)) < 0) {
			fprintf(stderr, "[!] Errore di push nello stack");
			exit(EXIT_FAILURE);
		}
	}

	// Stampa della lista
	while (!empty(head))
		printf("%d ", *(int *) pop(&head));
	printf("\n");
	
	return 0;
} */
