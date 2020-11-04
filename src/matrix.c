#include <lgn/matrix.h>

mat3_t make_mat3_with_vec3 (vec3_t x, vec3_t y, vec3_t z) {

    mat3_t matrix;
    matrix.x = x;
    matrix.y = y;
    matrix.z = z;
    return matrix;
}

mat3_t make_mat3 (double xx, double xy, double xz,
                  double yx, double yy, double yz,
                  double zx, double zy, double zz) {

    vec3_t x = make_vec3 (xx, xy, xz);
    vec3_t y = make_vec3 (yx, yy, yz);
    vec3_t z = make_vec3 (zx, zy, zz);
    return make_mat3_with_vec3 (x, y, z);
}

mat3_t identity_mat3 () {

    return make_mat3 (1, 0, 0,
                      0, 1, 0,
                      0, 0, 1);
}

mat3_t transpose_mat3 (mat3_t matrix) {

    return make_mat3 (matrix.x.x, matrix.y.x, matrix.z.x,
                      matrix.x.y, matrix.y.y, matrix.z.y,
                      matrix.x.z, matrix.y.z, matrix.z.z);
}

mat3_t add_mat3 (mat3_t a, mat3_t b) {

    vec3_t x = add_vec3 (a.x, b.x);
    vec3_t y = add_vec3 (a.y, b.y);
    vec3_t z = add_vec3 (a.z, b.z);
    return make_mat3_with_vec3 (x, y, z);
}

mat3_t multiply_mat3 (mat3_t a, mat3_t b) {

    mat3_t c = transpose_mat3 (b);
    return make_mat3 (dot_vec3 (a.x, c.x), dot_vec3 (a.x, c.y), dot_vec3 (a.x, c.z),
                      dot_vec3 (a.y, c.x), dot_vec3 (a.y, c.y), dot_vec3 (a.y, c.z),
                      dot_vec3 (a.z, c.x), dot_vec3 (a.z, c.y), dot_vec3 (a.z, c.z));
}

vec3_t multiply_mat3_vec3 (mat3_t matrix, vec3_t vector) {

    return make_vec3 (dot_vec3 (matrix.x, vector),
                      dot_vec3 (matrix.y, vector),
                      dot_vec3 (matrix.z, vector));
}
