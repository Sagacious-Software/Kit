#ifndef REGION_H
#define REGION_H

#include "vector.h"

typedef struct region_t {

    /* position from the top left corner */
    vec2_t offset;

    /* width and height of the region */
    vec2_t dimensions;

} region_t;

region_t make_region (double x, double y, double width, double height);
region_t make_region_bounds (double left, double top, double right, double bottom);

bool region_equals (region_t a, region_t b);

vec2_t clip_vec2 (vec2_t vector, region_t region);

#endif /* REGION_H */
