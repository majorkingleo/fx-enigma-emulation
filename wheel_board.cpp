#include "wheel_board.h"
#include "wheel.h"

FXDEFMAP( WheelBoard ) WheelBoardMap[] = {
};

FXIMPLEMENT( WheelBoard, FXHorizontalFrame, WheelBoardMap, ARRAYNUMBER( WheelBoardMap ) );

WheelBoard::WheelBoard( FXComposite *p, int wn, FXColor c_back )
    : FXHorizontalFrame( p, LAYOUT_CENTER_X ),
      wheel_num( wn )
{
    setBackColor( c_back );

    wheels.resize(wheel_num);

    for( int i = 0; i < wheel_num; ++i )
	wheels[i] = new Wheel( this, c_back );
}

WheelBoard::~WheelBoard()
{
  for( unsigned i = 0; i <wheels.size(); i++ )
    delete wheels[i];
}

void WheelBoard::setWheels( const FXString &str )
{
    if( str.length() >= wheel_num )
    {
	for( int i = 0; i < wheel_num; ++i )
	    wheels[i]->setValue( str[i] );
    }
}
