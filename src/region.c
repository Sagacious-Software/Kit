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

/* TODO: rename clamp */
vec2_t clip_vec2 (vec2_t vector, region_t region) {

    return make_vec2 (clip (vector.x, region.offset.x, region.offset.x + region.dimensions.x),
                      clip (vector.y, region.offset.y, region.offset.y + region.dimensions.y));
}

region_t intersect_region (region_t a, region_t b)  {

    /* TODO: make bounds representation and use that instead */
    return make_region_bounds (MAX (a.offset.x, b.offset.x),
                               MAX (a.offset.y, b.offset.y),
                               MIN (a.offset.x + a.dimensions.x,
                                    b.offset.x + b.dimensions.x),
                               MIN (a.offset.y + a.dimensions.y,
                                    b.offset.y + b.dimensions.y));
}
