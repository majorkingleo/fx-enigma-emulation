#ifndef WHEEL_H
#define WHEEL_H

#include <fx.h>

class Wheel : public FXHorizontalFrame
{
    FXDECLARE( Wheel );

 public:
    enum {
	ID_DIAL = FXHorizontalFrame::ID_LAST,
	ID_LAST
    };

 private:
    Wheel() {}

    FXLabel       *text;
    FXDial        *dial;

 public:
    Wheel( FXComposite *p, FXColor c_background );

    long onValueChanged( FXObject *obj, FXSelector sel, void *ptr );

    void setValue( char c );
};

#endif
