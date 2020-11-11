#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

/* a dynamic array of pointers */
typedef struct array_t {

    /* the array contents */
    void **contents;

    /* allocated number of elements */
    size_t n_allocated;

    /* used number of elements */
    size_t n_elements;

} array_t;

/* array constructor */
/* NOTE: n_allocated must be > 0 */
array_t *create_array (size_t n_allocated);

/* array destructor */
void destroy_array (array_t *array);

/* insert a pointer into the array */
void add_array (array_t *array, void *element);

#endif /* ARRAY_H */
