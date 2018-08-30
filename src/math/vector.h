#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

typedef struct{
    double x,y,z;
}Vector;

Vector new_vector(double i, double j, double k);

double vector_magnitude(Vector v);
Vector vector_normalize(Vector v);
Vector vector_negate(Vector v);
Vector vector_add(Vector v1, Vector v2);
Vector vector_scalar_product(double factor, Vector v);
double vector_dot_product(Vector v1, Vector v2);
Vector vector_cross_product(Vector v1, Vector v2);

#endif
