#include "logger.h"


FILE *file_fp;
int log_level;




/* get_date()
 * Return string date for logging
 */
static char *get_date(char *date, size_t size) {

	time_t t = time(NULL);
	struct tm *tmp = localtime(&t);

	strftime(date, size, "%Y-%m-%d %H:%M:%S", tmp);

	return date;
} /*-*/



/* open_logger()
 * Open logile ready to write
 */
int open_logger(const char *logfile, int level) {

	if ((file_fp = fopen(logfile, "a")) ==  NULL) {
		fprintf(stderr, "[!] Error to open logfile: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	// Setting log_level
	log_level = level;
	
	return 1;
} /*-*/



/* logger()
 * Logging function
 */
int logger(int level, const char *format, ...) {

	char log_string[128];
	char date[128];

	if (level <= log_level) {
		// Composizione stringa
		va_list arglist;
		va_start(arglist, format);
		vsnprintf(log_string, sizeof(log_string), format, arglist);
		va_end(arglist);

		// Write to logfile
		fprintf(file_fp, "[%s] %s\n", get_date(date, sizeof(date)), log_string);
		fflush(file_fp);

		// Print output if debug
		if (log_level == LOG_FULL_DEBUG)
			fprintf(stdout, "[%s] %s\n", get_date(date, sizeof(date)), log_string);
	}

	return 1;
} /*-*/



/* close_logger()
 * Close logfile
 */
void close_logger() {
	fclose(file_fp);
} /*-*/
