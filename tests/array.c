#include <stdlib.h>
#include <time.h>

#include <kit/array.h>

#define N_VALUES 1024

int main (int argc, char **argv) {

    int i;

    /* some random values to test with */
    size_t values[N_VALUES];

    /* the dynamic array to test */
    array_t *array;

    /* seed the random generator */
    srand (time (NULL));

    /* initialize the array */
    array = create_array (1);

    /* initialize the random values */
    for (i = 0; i < N_VALUES; i++)
        values[i] = (rand () / (double) RAND_MAX) * sizeof (size_t);

    /* fill the dynamic array with the test values */
    for (i = 0; i < N_VALUES; i++)
        add_array (array, (void *) values[i]);

    /* check all of them */
    for (i = 0; i < N_VALUES; i++)
        if (values[i] != (size_t) array->contents[i])
            return EXIT_FAILURE;

    /* we made it fellas */
    return EXIT_SUCCESS;
}
