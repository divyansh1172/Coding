#include <stdio.h>
#include <math.h>
#define PI 3.14
#define area_tri(a, b, c) (sqrt(((a)+(b)+(c))/2.0 * ((((a)+(b)+(c))/2.0)-(a)) * ((((a)+(b)+(c))/2.0)-(b)) * ((((a)+(b)+(c))/2.0)-(c))))
#define peri_tri(a, b, c) ((a) + (b) + (c))

#define area_squ(x) ((x) * (x))
#define peri_squ(x) (4 * (x))

#define area_circ(r) (PI * (r) * (r))
#define peri_circ(r) (2 * PI * (r))
