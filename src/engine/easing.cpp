#include "easing.h"
#include "../constants.h"
#include <math.h>
double easeInBounce(double x) {
    return 1 - easeOutBounce(1 - x);
}

double easeOutBounce(double x) {
    double n1 = 7.5625;
    double d1 = 2.75;

    if (x < 1 / d1) {
        return n1 * x * x;
    } else if (x < 2 / d1) {
        return n1 * (x -= 1.5 / d1) * x + 0.75;
    } else if (x < 2.5 / d1) {
        return n1 * (x -= 2.25 / d1) * x + 0.9375;
    } else {
        return n1 * (x -= 2.625 / d1) * x + 0.984375;
    }
}

double easeOutElastic(double x)  {
    double c4 = (2 * MATH_PI ) / 3;
    if(x == 0) return 0;
    if(x == 1) return 1;
    return pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
}

double easeInOutBack(double x) {
    double c1 = 1.70158;
    double c2 = c1 * 1.525;
    if (x < 0.5)
    {
      return (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2;
    }
    else {
      return (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
    }
}

double easeInExpo(double x)
{
    return x == 0.0 ? 0.0 : pow(2, 10 * x - 10);
}

