/*
 * Logger.h
 */

#ifndef _LOGGER_H_
#define _LOGGER_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>



// Livelli di logging
#define LOG_NOLOG -1     // No error
#define LOG_ERROR 0      // Error
#define LOG_WARNING 1    // Warning
#define LOG_INFO 2       // Info
#define LOG_DEBUG 3      // Debug
#define LOG_FULL_DEBUG 4 // Print debug in output  


// Define logfile
#define LOGFILE "./logs/monit.log"



// Definizione prototipi
int open_logger(const char *logfile, int level);
int logger(int level, const char *format, ...);
void close_logger();


#endif
