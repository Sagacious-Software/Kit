#include <lgn/image.h>

image_t make_image (pixel_format_t format, buffer_t *buffer) {

    image_t image;
    image.format = format;
    image.buffer = buffer;
    return image;
}
