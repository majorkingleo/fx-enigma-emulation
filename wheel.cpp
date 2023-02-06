#include "wheel.h"

FXDEFMAP( Wheel ) WheelMap[]= {
    FXMAPFUNC( SEL_CHANGED, Wheel::ID_DIAL, Wheel::onValueChanged )
};

FXIMPLEMENT( Wheel, FXHorizontalFrame, WheelMap, ARRAYNUMBER( WheelMap ) );

Wheel::Wheel( FXComposite *p, FXColor c_back )
    : FXHorizontalFrame( p )
{
    setBackColor( c_back );

    text = new FXLabel( this, "A", NULL, LAYOUT_CENTER_Y | LAYOUT_FIX_WIDTH, 0, 0, 20 );
    text->setBackColor( FXRGB( 255, 255, 255 ) );

    dial = new FXDial( this, this, ID_DIAL, DIAL_VERTICAL | LAYOUT_FIX_HEIGHT | DIAL_CYCLIC, 0, 0, 0, 100, 0, 0, 0, 0 );
    dial->setRange( 'A', 'Z' );
}

long Wheel::onValueChanged( FXObject *obj, FXSelector sel, void *ptr )
{
    text->setText( FXString().format( "%c", (char)dial->getValue() ) );
    return 1;
}

void Wheel::setValue( char c )
{
    if( c < 'A' || c > 'Z' )
	return;

    text->setText( FXString().format( "%c", c ) );
    dial->setValue( c );
}
