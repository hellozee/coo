#ifndef COO_VECTOR_H
#define COO_VECTOR_H

#include <math.h>

typedef struct{
    double x,y,z;
}c_vector;

c_vector new_vector(double i, double j, double k);

static const c_vector i_cap = {1,0,0};
static const c_vector j_cap = {0,1,0};
static const c_vector k_cap = {0,0,1};

double vector_magnitude(c_vector v);
c_vector vector_normalize(c_vector v);
c_vector vector_negate(c_vector v);
c_vector vector_add(c_vector v1, c_vector v2);
c_vector vector_scalar_product(double factor, c_vector v);
double vector_dot_product(c_vector v1, c_vector v2);
c_vector vector_cross_product(c_vector v1, c_vector v2);

#endif
