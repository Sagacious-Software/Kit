#include <stdlib.h>
#include <stdint.h>

#include <kit/buffer.h>
#include <kit/util.h>

buffer_t *create_buffer_with_data (vec2_t dimensions,
                                   size_t stride,
                                   void *data,
                                   size_t size) {

    buffer_t *buffer = malloc (sizeof (buffer_t));
    buffer->dimensions = dimensions;
    buffer->stride = stride;
    buffer->data = data;
    buffer->size = size;

    return buffer;
}

buffer_t *create_buffer (vec2_t dimensions, size_t stride) {

    size_t size = dimensions.x * dimensions.y * stride;
    void *data = malloc (size);
    return create_buffer_with_data (dimensions, stride, data, size);
}

void destroy_buffer_without_data (buffer_t *buffer) {

    free (buffer);
}

void destroy_buffer (buffer_t *buffer) {

    free (buffer->data);
    destroy_buffer_without_data (buffer);
}

void *fill_buffer (buffer_t *buffer, void *data) {

    return memfill (buffer->data, data, buffer->size, buffer->stride);
}

void *get_buffer_address (buffer_t *buffer, vec2_t position) {

    size_t index = position.x + position.y * buffer->dimensions.x;
    size_t offset = index * buffer->stride;
    return (void *) ((uint8_t *) buffer->data + offset);
}
