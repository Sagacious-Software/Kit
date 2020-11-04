#include <stdint.h>

#include <kit/pixel.h>

void pack_color (pixel_format_t format, void *destination, color_t color) {

    switch (format) {
        case PIXEL_RGBA32:
            pack_rgba32_color (destination, color);
        case PIXEL_ABGR32:
            pack_abgr32_color (destination, color);
        default:
            /* TODO: warning? */
            return;
    }
}

color_t unpack_color (pixel_format_t format, void *source) {

    switch (format) {
        case PIXEL_RGBA32:
            return unpack_rgba32_color (source);
        case PIXEL_ABGR32:
            return unpack_abgr32_color (source);
        default:
            /* TODO: warning? */
            return make_color (COLOR_RGB);
    }
}

void pack_rgba32_color (void *destination, color_t color) {

    rgb_color_t rgb_color = get_rgb_color (color);
    uint8_t *pointer = destination;
    *(pointer++) = (uint8_t) (rgb_color.red   * 255);
    *(pointer++) = (uint8_t) (rgb_color.green * 255);
    *(pointer++) = (uint8_t) (rgb_color.blue  * 255);
    *(pointer++) = 0;
}

color_t unpack_rgba32_color (void *source) {

    color_t color = make_color (COLOR_RGB);
    uint8_t *pointer = source;
    double red   = *(pointer++) * 255;
    double green = *(pointer++) * 255;
    double blue  = *(pointer++) * 255;
    color.colors.rgb = make_rgb_color (red, green, blue);
    return color;
}

void pack_abgr32_color (void *destination, color_t color) {

    rgb_color_t rgb_color = get_rgb_color (color);
    uint8_t *pointer = destination;
    *(pointer++) = 0;
    *(pointer++) = (uint8_t) (rgb_color.blue  * 255);
    *(pointer++) = (uint8_t) (rgb_color.red   * 255);
    *(pointer++) = (uint8_t) (rgb_color.green * 255);
}

color_t unpack_abgr32_color (void *source) {

    color_t color = make_color (COLOR_RGB);
    uint8_t *pointer = source;
    double blue  = *(++pointer) * 255;
    double red   = *(++pointer) * 255;
    double green = *(++pointer) * 255;
    color.colors.rgb = make_rgb_color (red, green, blue);
    return color;
}
