#ifndef IMAGE_H
#define IMAGE_H

#include "buffer.h"
#include "pixel.h"

typedef struct image_t {

    pixel_format_t format;
    buffer_t *buffer;

} image_t;

image_t make_image (pixel_format_t format, buffer_t *buffer);

#endif /* IMAGE_H */
