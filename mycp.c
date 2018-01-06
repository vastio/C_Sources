/*
 * Implementazione di filecopy portatile e bufferizzata
 */


#include <stdio.h>
#include <stdlib.h>


int fcopy(const char *src, const char *dest);
void print_usage(const char *prog_name);



// MAIN
int main(int argc, char *argv[]) {

	int retval;
	
	if (argc < 2)
		print_usage(argv[0]);

	// Copia del file con la gestione dell'errore
	if ((retval = fcopy(argv[1], argv[2])) < 0) {
		fprintf(stderr, "Error in filecopy: %d\n", retval);
		exit(EXIT_FAILURE);
	}
		
	return 0;
} /*-*/



/* print_usage()
 * print usage and exit
 */
void print_usage(const char *prog_name) {
	
	printf("\nUsage: \n");
	printf("\t%s  source_file dest_file\n\n", prog_name);
	
	exit(EXIT_SUCCESS);
} /*-*/



/* fcopy()
 * Esegue la copia del file
 */
int fcopy(const char *src, const char *dest) {

	
	
	return EXIT_SUCCESS;
} /*-*/
