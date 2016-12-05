#include <Arduino.h>
#include <Stepper.h>
#include <math.h>
#include "Motors.h"

 #define  PI 3.14159265358979323846
// Global constants for the stepper motor 28BYJ-48
const int SPEED = 15;   // default speed (360° in 4sec)
const int SPR   = 2048; // default Steps per Revolition for 28BYJ-48
const int WHEEL_DIAMETER  = 57;   // basic wheel diameter
const int WHEEL_PERIMETER = WHEEL_DIAMETER * PI;
const int SPMM  = SPR / WHEEL_PERIMETER;
const int WHEEL_DISTANCE = 120;

/*
 *  Motors Constructor
 *
 *  construct Motors object
 *  with single motors as initializers
 *
 *  @param {int} left - the left side motor
 *  @param {int} right - the right site motor
 */
Motors::Motors( int left[ 4 ], int right[ 4 ] )
    :
    rightMotor( SPR, right[ 0 ], right[ 2 ], right[ 1 ], right[ 3 ] ),
    leftMotor( SPR, left[ 0 ], left[ 2 ], left[ 1 ], left[ 3 ] )
{
    currentDirection = 0;
    _setDefaultSpeed();
}
/*
 *  private set Speed
 *
 *  sets the default speed left and right motor.
 */
void Motors::_setDefaultSpeed()
{
    rightMotor.setSpeed( SPEED );
    leftMotor.setSpeed( SPEED );
}

void Motors::turn( float degree )
{
    double perimeter = WHEEL_DISTANCE * PI;

    double steps = perimeter / 360 * abs( degree ) * SPMM;

    int step = 1;

    Serial.println( currentDirection );

    if ( degree < 0 ) {
        step = -1;
    }

    for ( int i = 1; i <= (int)steps; i++ )
    {
        rightMotor.step( step );
        leftMotor.step( step );
    }
}

void Motors::turnTo( float degree )
{
    double newDegree = degree - currentDirection;

    if ( newDegree < -180 )
    {
        newDegree = newDegree + 360;
    }

    turn( newDegree );

    currentDirection = degree;
}

void Motors::forwards( int mm = 100 )
{
    double steps = mm * SPMM;


    Serial.print( "mm: " );
    Serial.println( mm );
    Serial.print( "steps: " );
    Serial.println( steps );

    for ( int i = 1; i <= (int)steps; i++ )
    {
        rightMotor.step( 1 );
        leftMotor.step( -1 );
    }
}

void Motors::backwards()
{
    for ( int i = 1; i <= SPR; i++ )
    {
        rightMotor.step( -1 );
        leftMotor.step( 1 );
    }
}
