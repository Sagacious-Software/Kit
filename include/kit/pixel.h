#ifndef PIXEL_H
#define PIXEL_H

#include "color.h"

typedef enum pixel_format_t {

    PIXEL_RGBA32,
    PIXEL_ABGR32,
    PIXEL_BGRA32,

    NUM_PIXEL_FORMAT

} pixel_format_t;

void pack_color (pixel_format_t format, void *destination, color_t color);
color_t unpack_color (pixel_format_t format, void *source);

void pack_rgba32_color (void *destination, color_t color);
color_t unpack_rgba32_color (void *source);

void pack_abgr32_color (void *destination, color_t color);
color_t unpack_abgr32_color (void *source);

void pack_bgra32_color (void *destination, color_t color);
color_t unpack_bgra32_color (void *source);

#endif /* PIXEL_H */
