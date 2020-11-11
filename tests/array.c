#include <stdlib.h>
#include <time.h>

#include <kit/array.h>

#define N_VALUES 1024

int main (int argc, char **argv) {

    int i;

    /* some random values to test with */
    size_t values[N_VALUES];

    /* the dynamic array to test */
    array_t array;
    
    /* access to the array contents */
    size_t *elements;

    /* seed the random generator */
    srand (time (NULL));

    /* initialize the array */
    initialize_array (&array, 1);

    /* set the elements alias */
    elements = (size_t *) array.elements;

    /* initialize the random values */
    for (i = 0; i < N_VALUES; i++)
        values[i] = (rand () / (double) RAND_MAX) * sizeof (size_t);

    /* fill the dynamic array with the test values */
    for (i = 0; i < N_VALUES; i++)
        add_array (&array, (void *) values[i]);

    /* check all of them */
    for (i = 0; i < N_VALUES; i++)
        if (values[i] != elements[i])
            return EXIT_FAILURE;

    /* cleanup */
    terminate_array (&array);

    /* we made it fellas */
    return EXIT_SUCCESS;
}
