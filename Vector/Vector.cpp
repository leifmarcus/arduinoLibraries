#include <Arduino.h>
#include <math.h>
#include "Vector.h"

Vector::Vector( int vX, int vY )
{
    x = vX;
    y = vY;
}

void Vector::sub( int xx, int yy )
{
    x = x - xx;
    y = y - yy;
}

double Vector::magSq()
{
    return pow( x, 2 ) + pow( y, 2 );
}
double Vector::mag()
{
    return sqrt( magSq() );
}

double Vector::dot( double vx, double vy )
{
    return x * vx + y * vy;
}

double Vector::direction()
{
    return atan2( y, x ) * 180 / PI;
}
