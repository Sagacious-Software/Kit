#include <kit/region.h>
#include <kit/util.h>

region_t make_region (double x, double y, double width, double height) {

    region_t region;
    region.offset.x     = x;
    region.offset.y     = y;
    region.dimensions.x = width;
    region.dimensions.y = height;
    return region;
}

region_t make_region_bounds (double left, double top, double right, double bottom) {

    return make_region (left, top, right - left, bottom - top);
}

bool region_equals (region_t a, region_t b) {

    return equals_vec2 (a.offset, b.offset) &&
           equals_vec2 (a.dimensions, b.dimensions);
}

vec2_t clip_vec2 (vec2_t vector, region_t region) {

    return make_vec2 (clip (vector.x, region.offset.x, region.offset.x + region.dimensions.x),
                      clip (vector.y, region.offset.y, region.offset.y + region.dimensions.y));
}

