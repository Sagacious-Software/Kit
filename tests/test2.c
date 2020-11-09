#include <stdio.h>
#include <stdlib.h>

#include <kit/buffer.h>

int main (int argc, char **argv) {

    int i;

    buffer_t *buffer = create_buffer (make_vec2 (20, 10), 4);
    fill_buffer (buffer, "Oh my goodness");

    for (i = 0; i < 50; i++)
        printf ("%d = %c\n", i, ((char *) buffer->data)[i]);

    destroy_buffer (buffer);

    return ((char *) buffer->data)[21] == 'h' ? EXIT_SUCCESS : EXIT_FAILURE;
}
