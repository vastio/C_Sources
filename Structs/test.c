/*
 * Programma di test delle strutture dati definite in structs.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

#define MAX_NUM 5




// MAIN for string
int main(int argc, char *argv[]) {

	Nodo *head = NULL;
	int i;
	char *word[MAX_NUM] = {"Casa", "Chiesa", "Cosa", "Ciao", "World"};

	for (i = 0; i < MAX_NUM; i++) {
		if (stack_push(&head, word[i], sizeof(char) * strlen(word[i])) < 0) {
			fprintf(stderr, "[!] Errore di push nello stack.");
			exit(EXIT_FAILURE);
		}
	}
	
	// Stampa della lista
	while (!empty(head))
		printf("%s ", (char *) stack_pop(&head));
	printf("\n");
	
	return 0;
}


// MAIN for int
/*int main(int argc, char *argv[]) {

	Nodo *head = NULL;
	int i, nums[MAX_NUM] = {12, 34, 5, 66, 90, 88, 22};
	
	for (i = 0; i < MAX_NUM; i++) {
		if (stack_push(&head, &nums[i], sizeof(int)) < 0) {
			fprintf(stderr, "[!] Errore di push nello stack");
			exit(EXIT_FAILURE);
		}
	}

	// Stampa della lista
	while (!empty(head))
		printf("%d ", *(int *) stack_pop(&head));
	printf("\n");
	
	return 0;
} */
