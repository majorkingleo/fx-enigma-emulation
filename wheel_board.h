#ifndef WHEEL_BOARD_H
#define WHEEL_BOARD_H

#include <fx.h>
#include <vector>

class Wheel;

class WheelBoard : public FXHorizontalFrame
{
    FXDECLARE( WheelBoard );

 private:
 WheelBoard() : wheel_num(1) {}

    const int wheel_num;

    std::vector<Wheel*> wheels;

 public:
    WheelBoard( FXComposite *p, int wheel_num, FXColor c_background );
    ~WheelBoard();

    void setWheels( const FXString &str );
};

#endif
