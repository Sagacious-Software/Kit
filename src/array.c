#include <kit/array.h>

array_t *create_array (size_t n_allocated) {

    /* TODO: this needs uh, safety checks n stuff LOL */
    array_t *array = malloc (sizeof (array_t));
    array->contents    = calloc (n_allocated, sizeof (void *));
    array->n_allocated = n_allocated;
    array->n_elements  = 0;
    return array;
}

void destroy_array (array_t *array) {

    free (array->contents);
    free (array);
}

void add_array (array_t *array, void *element) {

    array->contents[array->n_elements++] = element;

    if (array->n_elements == array->n_allocated) {

        array->n_allocated *= 2;
        array->contents = realloc (array->contents,
                                   array->n_allocated * sizeof (void *));
    }
}
