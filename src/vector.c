#include <math.h>

#include <kit/vector.h>
#include <kit/util.h>

vec2_t make_vec2 (double x, double y) {

    vec2_t vector;
    vector.x = x;
    vector.y = y;
    return vector;
}

vec2_t interpolate_vec2 (vec2_t a, vec2_t b, double n) {

    double x = interpolate (a.x, b.x, n);
    double y = interpolate (a.y, b.y, n);
    return make_vec2 (x, y);
}

vec2_t add_vec2 (vec2_t a, vec2_t b) {

    double x = a.x + b.x;
    double y = a.y + b.y;
    return make_vec2 (x, y);
}

vec2_t subtract_vec2 (vec2_t a, vec2_t b) {

    double x = a.x - b.x;
    double y = a.y - b.y;
    return make_vec2 (x, y);
}

vec2_t multiply_vec2 (vec2_t a, vec2_t b) {

    double x = a.x * b.x;
    double y = a.y * b.y;
    return make_vec2 (x, y);
}

vec2_t divide_vec2 (vec2_t a, vec2_t b) {
 
    double x = a.x / b.x;
    double y = a.y / b.y;
    return make_vec2 (x, y);
}

vec2_t add_vec2_scalar (vec2_t vector, double scalar) {

    double x = vector.x + scalar;
    double y = vector.y + scalar;
    return make_vec2 (x, y);
}

vec2_t subtract_vec2_scalar (vec2_t vector, double scalar) {

    double x = vector.x - scalar;
    double y = vector.y - scalar;
    return make_vec2 (x, y);
}

vec2_t multiply_vec2_scalar (vec2_t vector, double scalar) {

    double x = vector.x * scalar;
    double y = vector.y - scalar;
    return make_vec2 (x, y);
}

vec2_t divide_vec2_scalar (vec2_t vector, double scalar) {

    double x = vector.x / scalar;
    double y = vector.y / scalar;
    return make_vec2 (x, y);
}

double dot_vec2 (vec2_t a, vec2_t b) {

    return a.x * b.x + a.y * b.y;
}

double length_vec2 (vec2_t vector) {

    return sqrt (vector.x * vector.x + vector.y * vector.y);
}

vec2_t unit_vec2 (vec2_t vector) {

    return divide_vec2_scalar (vector, length_vec2 (vector));
}

bool equals_vec2 (vec2_t a, vec2_t b) {

    return a.x == b.x && a.y == b.y;
}

vec3_t make_vec3 (double x, double y, double z) {

    vec3_t vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}

vec3_t interpolate_vec3 (vec3_t a, vec3_t b, double n) {

    double x = interpolate (a.x, b.x, n);
    double y = interpolate (a.y, b.y, n);
    double z = interpolate (a.z, b.z, n);
    return make_vec3 (x, y, z);
}

vec3_t add_vec3 (vec3_t a, vec3_t b) {

    double x = a.x + b.x;
    double y = a.y + b.y;
    double z = a.z + b.z;
    return make_vec3 (x, y, z);
}

vec3_t subtract_vec3 (vec3_t a, vec3_t b) {

    double x = a.x - b.x;
    double y = a.y - b.y;
    double z = a.z - b.z;
    return make_vec3 (x, y, z);
}

vec3_t multiply_vec3 (vec3_t a, vec3_t b) {

    double x = a.x * b.x;
    double y = a.y * b.y;
    double z = a.z * b.z;
    return make_vec3 (x, y, z);
}

vec3_t divide_vec3 (vec3_t a, vec3_t b) {
 
    double x = a.x / b.x;
    double y = a.y / b.y;
    double z = a.z / b.z;
    return make_vec3 (x, y, z);
}

vec3_t add_vec3_scalar (vec3_t vector, double scalar) {

    double x = vector.x + scalar;
    double y = vector.y + scalar;
    double z = vector.z + scalar;
    return make_vec3 (x, y, z);
}

vec3_t subtract_vec3_scalar (vec3_t vector, double scalar) {

    double x = vector.x - scalar;
    double y = vector.y - scalar;
    double z = vector.z - scalar;
    return make_vec3 (x, y, z);
}

vec3_t multiply_vec3_scalar (vec3_t vector, double scalar) {

    double x = vector.x * scalar;
    double y = vector.y * scalar;
    double z = vector.z * scalar;
    return make_vec3 (x, y, z);
}

vec3_t divide_vec3_scalar (vec3_t vector, double scalar) {

    double x = vector.x / scalar;
    double y = vector.y / scalar;
    double z = vector.z / scalar;
    return make_vec3 (x, y, z);
}

double dot_vec3 (vec3_t a, vec3_t b) {

    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double length_vec3 (vec3_t vector) {

    return sqrt (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

vec3_t unit_vec3 (vec3_t vector) {

    return divide_vec3_scalar (vector, length_vec3 (vector));
}

bool equals_vec3 (vec3_t a, vec3_t b) {

    return a.x == b.x && a.y == b.y && a.z == b.z;
}
