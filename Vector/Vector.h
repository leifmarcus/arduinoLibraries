#ifndef Vector_h
#define Vector_h

#include <Arduino.h>

class Vector
{
    public:
        Vector( int vX, int vY );
        int    x;
        int    y;
        void   sub( int xx, int yy );
        double magSq();
        double mag();
        double direction();
        double dot( double vx, double vy );
    private:

};

#endif
