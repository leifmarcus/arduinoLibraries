#ifndef Motors_h
#define Motors_h

#include <Arduino.h>
#include <Stepper.h>

class Motors
{
    public:
        Motors( int left[ 4 ], int right[ 4 ] );
        void forwards( int mm = 100 );
        void backwards();
        void turn( float degree );
        void turnTo( float degree );
    private:
        Stepper rightMotor;
        Stepper leftMotor;
        double currentDirection = 0;
        void _setDefaultSpeed();

};

#endif
