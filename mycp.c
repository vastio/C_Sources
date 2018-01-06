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

	FILE *src_fp, *dest_fp;
	char buffer[BUFSIZ];
	size_t n_read, n_write, tot_write = 0;

	
	// Apertura file sorgente
	if ((src_fp = fopen(src, "r")) == NULL)
		return -1;

	// Apertura file destinazione
	if ((dest_fp = fopen(dest, "w")) == NULL) {
		fclose(src_fp);
		return -2;
	}

	// Copia
	while ((n_read = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
		if (!ferror(src_fp)) {
			n_write = fwrite(buffer, 1, n_read, dest_fp);

			if (ferror(dest_fp)) {
				fclose(dest_fp);
				fclose(src_fp);
				return -3;
			}
		}
		else {
			fclose(dest_fp);
			fclose(src_fp);
			return -4;
		}
		
		tot_write += n_write;
		printf("[*] Copied %d bytes\r", tot_write);
	}
	printf("\n");
	
	// Chiusura file pointer
	fclose(src_fp);
	fclose(dest_fp);
	
	return 0;
} /*-*/
