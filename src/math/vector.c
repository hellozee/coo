#include "vector.h"

Vector new_vector(double i, double j, double k){
    Vector vec;
    vec.x = i;
    vec.y = j;
    vec.z = k;
    return vec;
}

double vector_magnitude(Vector v){
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector vector_normalize(Vector v){
    double magnitude = vector_magnitude(v);
    return new_vector(v.x/magnitude, v.y/magnitude, v.z/magnitude);
}

Vector vector_negate(Vector v){
    return new_vector(-1 * v.x, -1 * v.y, -1 * v.z); 
}

Vector vector_add(Vector v1, Vector v2){
    return new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector vector_scalar_product(double factor, Vector v){
    return new_vector(v.x * factor, v.y * factor, v.z * factor);
}

double vector_dot_product(Vector v1, Vector v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector vector_cross_product(Vector v1, Vector v2){
    Vector v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v2.x * v1.z - v1.x * v2.z;
    v.z = v1.x * v2.z - v1.z * v2.x;
    return v;
}
