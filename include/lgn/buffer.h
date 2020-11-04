#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>

#include "vector.h"

typedef struct buffer_t {

    vec2_t dimensions;
    size_t stride;
    void *data;
    size_t size;

} buffer_t;

/* create a buffer and allocate memory to hold the data */
buffer_t *create_buffer_with_data (vec2_t dimensions,
                                   size_t stride,
                                   void *data,
                                   size_t size);

/* create a buffer object given already existing data */
buffer_t *create_buffer (vec2_t dimensions, size_t stride);

/* free the buffer object without freeing the data */
void destroy_buffer_without_data (buffer_t *buffer);

/* free the buffer object and the data */
void destroy_buffer (buffer_t *buffer);

void *fill_buffer (buffer_t *buffer, void *data);
void *get_buffer_address (buffer_t *buffer, vec2_t position);

#endif /* BUFFER_H */
