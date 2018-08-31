#include "vector.h"

c_vector 
new_vector(double i, double j, double k)
{
    c_vector vec;
    vec.x = i;
    vec.y = j;
    vec.z = k;
    return vec;
}

double 
vector_magnitude(c_vector v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

c_vector 
vector_normalize(c_vector v)
{
    double magnitude = vector_magnitude(v);
    return new_vector(v.x/magnitude, v.y/magnitude, v.z/magnitude);
}

c_vector 
vector_negate(c_vector v)
{
    return new_vector(-1 * v.x, -1 * v.y, -1 * v.z); 
}

c_vector 
vector_add(c_vector v1, c_vector v2)
{
    return new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

c_vector 
vector_scalar_product(double factor, c_vector v)
{
    return new_vector(v.x * factor, v.y * factor, v.z * factor);
}

double 
vector_dot_product(c_vector v1, c_vector v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

c_vector 
vector_cross_product(c_vector v1, c_vector v2)
{
    c_vector v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v2.x * v1.z - v1.x * v2.z;
    v.z = v1.x * v2.z - v1.z * v2.x;
    return v;
}
