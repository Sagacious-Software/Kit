#ifndef IMAGE_H
#define IMAGE_H

#include "buffer.h"
#include "color.h"
#include "pixel.h"

typedef struct image_t {

    pixel_format_t format;
    buffer_t *buffer;

} image_t;

image_t make_image (pixel_format_t format, buffer_t *buffer);

/* fill the entire image with a given color */
void fill_image (image_t image, color_t color);

/* TODO: move set_pixel & co from gosh wrt windows to kit wrt images */

#endif /* IMAGE_H */
