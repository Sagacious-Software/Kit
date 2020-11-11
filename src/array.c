#include <kit/array.h>

array_t *initialize_array (array_t *array, size_t n_allocated) {

    array->elements    = calloc (n_allocated, sizeof (void *));
    array->n_elements  = 0;
    array->n_allocated = n_allocated;
    return array;
}

array_t *terminate_array (array_t *array) {

    free (array->elements);
    return array;
}

void add_array (array_t *array, void *element) {

    array->elements[array->n_elements++] = element;

    if (array->n_elements == array->n_allocated) {

        array->n_allocated *= 2;
        array->elements = realloc (array->elements,
                                   array->n_allocated * (sizeof (void *)));
    }
}
