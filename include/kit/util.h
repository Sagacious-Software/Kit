#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

/* https://stackoverflow.com/a/3437433 */
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* fill destination memory with a repeating pattern copied from source */
void *memfill (void *destination,
               void *source,
               size_t destination_size,
               size_t source_size);

/* interpolate between two values */
double interpolate (double a, double b, double n);

/* real modulo */
double modulo (double n, double m);

/* min and max */
double clip (double n, double min, double max);

/* print an error message and exit the program with failure code */
void vdie (const char *format, va_list arguments);
void die (const char *format, ...);

/* die with given error message if the given value is false */
void vassert (bool value, const char *format, va_list arguments);
void assert (bool value, const char *format, ...);

#endif /* UTIL_H */
