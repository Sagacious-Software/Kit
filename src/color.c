#include <math.h>

#include <lgn/color.h>
#include <lgn/util.h>

color_t make_color (color_type_t type) {

    color_t color;
    color.type = type;
    return color;
}

rgb_color_t get_rgb_color (color_t color) {

    switch (color.type) {

        case COLOR_HSV:
            return hsv_to_rgb_color (color.colors.hsv);

        default:
            return color.colors.rgb;
    }
}

hsv_color_t get_hsv_color (color_t color) {

    switch (color.type) {

        case COLOR_RGB:
            return rgb_to_hsv_color (color.colors.rgb);

        default:
            return color.colors.hsv;
    }
}

rgb_color_t make_rgb_color (double red, double green, double blue) {

    rgb_color_t color;
    color.red   = red;
    color.green = green;
    color.blue  = blue;
    return color;
}

rgb_color_t hsv_to_rgb_color (hsv_color_t color) {

    double red, green, blue;
    double max_channel, min_channel, delta;
    double hue = color.hue * 6;

    if (hue < 1) {

        red = 1;
        green = hue;
        blue = 0;

    } else if (hue < 2) {

        red = 2 - hue;
        green = 1;
        blue = 0;

    } else if (hue < 3) {

        red = 0;
        green = 1;
        blue = hue - 2;

    } else if (hue < 4) {

        red = 0;
        green = 4 - hue;
        blue = 1;

    } else if (hue < 5) {

        red = hue - 4;
        green = 0;
        blue = 1;

    } else if (hue < 6) {

        red = 1;
        green = 0;
        blue = 6 - hue;
    }

    max_channel = color.value;
    min_channel = max_channel * (1 - color.saturation);
    delta = max_channel - min_channel;

    red   = red   * delta + min_channel;
    green = green * delta + min_channel;
    blue  = blue  * delta + min_channel;

    return make_rgb_color (red, green, blue);
}

rgb_color_t interpolate_rgb_color (rgb_color_t a, rgb_color_t b, double n) {

    return make_rgb_color (interpolate (a.red,   b.red,   n),
                           interpolate (a.green, b.green, n),
                           interpolate (a.blue,  b.blue,  n));
}

rgb_color_t add_rgb_color (rgb_color_t a, rgb_color_t b) {

    return make_rgb_color (a.red   + b.red,
                           a.green + b.green,
                           a.blue  + b.blue);
}

rgb_color_t subtract_rgb_color (rgb_color_t a, rgb_color_t b) {

    return make_rgb_color (a.red   - b.red,
                           a.green - b.green,
                           a.blue  - b.blue);
}

rgb_color_t multiply_rgb_color (rgb_color_t a, rgb_color_t b) {

    return make_rgb_color (a.red   * b.red,
                           a.green * b.green,
                           a.blue  * b.blue);
}

rgb_color_t divide_rgb_color (rgb_color_t a, rgb_color_t b) {

    return make_rgb_color (a.red   / b.red,
                           a.green / b.green,
                           a.blue  / b.blue);
}

rgb_color_t add_rgb_color_scalar (rgb_color_t color, double scalar) {

    return make_rgb_color (color.red   + scalar,
                           color.green + scalar,
                           color.blue  + scalar);
}

rgb_color_t subtract_rgb_color_scalar (rgb_color_t color, double scalar) {

    return make_rgb_color (color.red   - scalar,
                           color.green - scalar,
                           color.blue  - scalar);
}

rgb_color_t multiply_rgb_color_scalar (rgb_color_t color, double scalar) {

    return make_rgb_color (color.red   * scalar,
                           color.green * scalar,
                           color.blue  * scalar);
}

rgb_color_t divide_rgb_color_scalar (rgb_color_t color, double scalar) {

    return make_rgb_color (color.red   / scalar,
                           color.green / scalar,
                           color.blue  / scalar);
}

rgb_color_t exponentiate_rgb_color_scalar (rgb_color_t color, double scalar) {

    return make_rgb_color (pow (color.red,   scalar),
                           pow (color.green, scalar),
                           pow (color.blue,  scalar));
}

hsv_color_t make_hsv_color (double hue, double saturation, double value) {

    hsv_color_t color;
    color.hue        = hue;
    color.saturation = saturation;
    color.value      = value;
    return color;
}

hsv_color_t rgb_to_hsv_color (rgb_color_t color) {

    double hue, saturation, value;

    double max_channel = MAX (color.red, MAX (color.green, color.blue));
    double min_channel = MIN (color.red, MIN (color.green, color.blue));
    double delta = max_channel - min_channel;

    if (delta == 0)
        hue = 0;
    else if (max_channel == color.red)
        hue = modulo ((color.green - color.blue) / delta / 6, 1);
    else if (max_channel == color.green)
        hue = ((color.blue - color.red) / delta + 2) / 6;
    else if (max_channel == color.blue)
        hue = ((color.red - color.green) / delta + 4) / 6;

    saturation = max_channel == 0 ? 0 : delta / max_channel;
    value = max_channel;

    return make_hsv_color (hue, saturation, value);
}

hsv_color_t interpolate_hsv_color (hsv_color_t a, hsv_color_t b, double n) {

    return make_hsv_color (interpolate (a.hue,        b.hue,        n),
                           interpolate (a.saturation, b.saturation, n),
                           interpolate (a.value,      b.value,      n));
}
