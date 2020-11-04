#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct mat3_t {

    vec3_t x;
    vec3_t y;
    vec3_t z;

} mat3_t;

mat3_t make_mat3_with_vec3 (vec3_t x, vec3_t y, vec3_t z);
mat3_t make_mat3 (double xx, double xy, double xz,
                  double yx, double yy, double yz,
                  double zx, double zy, double zz);

mat3_t identity_mat3 ();
mat3_t transpose_mat3 (mat3_t matrix);

mat3_t add_mat3           (mat3_t a, mat3_t b);
mat3_t multiply_mat3      (mat3_t a, mat3_t b);
vec3_t multiply_mat3_vec3 (mat3_t matrix, vec3_t vector);

#endif /* MATRIX_H */
