#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

/* a dynamic array of pointers */
typedef struct array_t {

    /* the array contents */
    void **elements;

    /* used number of elements */
    size_t n_elements;

    /* allocated number of elements */
    size_t n_allocated;

} array_t;

/* initialize an array */
/* NOTE: n_allocated must be > 0 */
array_t *initialize_array (array_t *array, size_t n_allocated);

/* terminate an array */
array_t *terminate_array (array_t *array);

/* insert a pointer into the array */
void add_array (array_t *array, void *element);

#endif /* ARRAY_H */
