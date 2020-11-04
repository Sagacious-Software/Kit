#ifndef COLOR_H
#define COLOR_H

typedef enum color_type_t {

    COLOR_RGB,
    COLOR_HSV,

    NUM_COLOR_TYPE

} color_type_t;

typedef struct rgb_color_t {

    double red;
    double green;
    double blue;

} rgb_color_t;

typedef struct hsv_color_t {

    double hue;
    double saturation;
    double value;

} hsv_color_t;

typedef struct color_t {

    color_type_t type;

    union {

        rgb_color_t rgb;
        hsv_color_t hsv;

    } colors;

} color_t;

color_t make_color     (color_type_t type);
color_t make_color_rgb (double red, double green, double blue);
color_t make_color_hsv (double hue, double saturation, double value);
rgb_color_t get_rgb_color (color_t color);
hsv_color_t get_hsv_color (color_t color);

color_t add_color      (color_t a, color_t b);
color_t subtract_color (color_t a, color_t b);
color_t multiply_color (color_t a, color_t b);
color_t divide_color   (color_t a, color_t b);

color_t add_color_scalar          (color_t color, double scalar);
color_t subtract_color_scalar     (color_t color, double scalar);
color_t multiply_color_scalar     (color_t color, double scalar);
color_t divide_color_scalar       (color_t color, double scalar);
color_t exponentiate_color_scalar (color_t color, double scalar);

rgb_color_t make_rgb_color (double red, double green, double blue);
rgb_color_t hsv_to_rgb_color (hsv_color_t color);
rgb_color_t interpolate_rgb_color (rgb_color_t a, rgb_color_t b, double n);

rgb_color_t add_rgb_color      (rgb_color_t a, rgb_color_t b);
rgb_color_t subtract_rgb_color (rgb_color_t a, rgb_color_t b);
rgb_color_t multiply_rgb_color (rgb_color_t a, rgb_color_t b);
rgb_color_t divide_rgb_color   (rgb_color_t a, rgb_color_t b);

rgb_color_t add_rgb_color_scalar          (rgb_color_t color, double scalar);
rgb_color_t subtract_rgb_color_scalar     (rgb_color_t color, double scalar);
rgb_color_t multiply_rgb_color_scalar     (rgb_color_t color, double scalar);
rgb_color_t divide_rgb_color_scalar       (rgb_color_t color, double scalar);
rgb_color_t exponentiate_rgb_color_scalar (rgb_color_t color, double scalar);

hsv_color_t make_hsv_color (double hue, double saturation, double value);
hsv_color_t rgb_to_hsv_color (rgb_color_t color);
hsv_color_t interpolate_hsv_color (hsv_color_t a, hsv_color_t b, double n);

#endif /* COLOR_H */
