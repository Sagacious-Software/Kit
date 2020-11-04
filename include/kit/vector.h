#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct vec2_t {

    double x;
    double y;

} vec2_t;

vec2_t make_vec2 (double x, double y);
vec2_t interpolate_vec2 (vec2_t a, vec2_t b, double n);

vec2_t add_vec2      (vec2_t a, vec2_t b);
vec2_t subtract_vec2 (vec2_t a, vec2_t b);
vec2_t multiply_vec2 (vec2_t a, vec2_t b);
vec2_t divide_vec2   (vec2_t a, vec2_t b);

vec2_t add_vec2_scalar      (vec2_t vector, double scalar);
vec2_t subtract_vec2_scalar (vec2_t vector, double scalar);
vec2_t multiply_vec2_scalar (vec2_t vector, double scalar);
vec2_t divide_vec2_scalar   (vec2_t vector, double scalar);

double dot_vec2 (vec2_t a, vec2_t b);
double length_vec2 (vec2_t vector);
vec2_t unit_vec2 (vec2_t vector);

bool equals_vec2 (vec2_t a, vec2_t b);

typedef struct vec3_t {

    double x;
    double y;
    double z;

} vec3_t;

vec3_t make_vec3 (double x, double y, double z);
vec3_t interpolate_vec3 (vec3_t a, vec3_t b, double n);

vec3_t add_vec3      (vec3_t a, vec3_t b);
vec3_t subtract_vec3 (vec3_t a, vec3_t b);
vec3_t multiply_vec3 (vec3_t a, vec3_t b);
vec3_t divide_vec3   (vec3_t a, vec3_t b);

vec3_t add_vec3_scalar      (vec3_t vector, double scalar);
vec3_t subtract_vec3_scalar (vec3_t vector, double scalar);
vec3_t multiply_vec3_scalar (vec3_t vector, double scalar);
vec3_t divide_vec3_scalar   (vec3_t vector, double scalar);

double dot_vec3 (vec3_t a, vec3_t b);
double length_vec3 (vec3_t vector);
vec3_t unit_vec3 (vec3_t vector);

bool equals_vec3 (vec3_t a, vec3_t b);

#endif /* VECTOR_H */
