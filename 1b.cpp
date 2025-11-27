#include <iostream>
#include <cmath>
#include <numbers>


int main (){
    double x, y, z, a, b, c, s, a1, a2, a3, c1, c2;
    double e = exp(1.0);
    double exponent = 2;

    printf ("Введите x:");
    scanf ("%lf", &x);
    printf ("Введите y:");
    scanf ("%lf", &y);
    printf ("Введите z:");
    scanf ("%lf", &z);

    a1 = x-y;
    a2 = fabs(a1);
    a3 = x+y;
    a = pow(e,a2) * pow(a2, a3);

    b = a/atan(x)+ atan(z);

    c1 = pow (log(y), exponent);
    c2 = pow (x, 6) + c1;
    c = pow (c2, 1/3); 

    s= b + c;

    printf ("Результат s= %.4f\n", s);
    return 0;
}