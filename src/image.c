#include <stdint.h>

#include <kit/image.h>

image_t make_image (pixel_format_t format, buffer_t *buffer) {

    image_t image;
    image.format = format;
    image.buffer = buffer;
    return image;
}

void fill_image (image_t image, color_t color) {

    uint32_t background_color_packed;
    color_t background_color = make_color_rgb (1, 0.5, 0);
    pack_color (image.format, &background_color_packed, background_color);
    fill_buffer (image.buffer, &background_color_packed);
}
