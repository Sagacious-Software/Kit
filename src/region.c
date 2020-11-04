#include <kit/region.h>

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
