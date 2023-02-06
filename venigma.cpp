#include "venigma.h"

#include "wheel_board.h"
#include "keyboard.h"

FXDEFMAP( VEnigma ) VEnigmaMap[] = {
    FXMAPFUNC( SEL_COMMAND, VEnigma::ID_KEYBOARD, VEnigma::onKeyPressed )
};

FXIMPLEMENT( VEnigma, FXVerticalFrame, VEnigmaMap, ARRAYNUMBER( VEnigmaMap ) );


VEnigma::VEnigma( FXComposite *p, Type type, FXObject *tgt, FXSelector sel, FXuint opts )
    : FXVerticalFrame( p, opts ),
      target( tgt ),
      message( sel ),
      type( type )
{
    setBackColor( FXRGB( 0x7c, 0x30, 0x30 ) );

    if( type == TYPE_M3 )
	wheelboard = new WheelBoard( this, 3, FXRGB( 0x7c, 0x30, 0x30 ) );
    else
	wheelboard = new WheelBoard( this, 4, FXRGB( 0x7c, 0x30, 0x30 ) );

    FXHorizontalSeparator *sep = new FXHorizontalSeparator( this );
    sep->setBackColor( FXRGB( 0, 0, 0 ) );

    lampboard = new Keyboard( this, NULL, 0, FXRGB( 0x7c, 0x30, 0x30 ), FXRGB( 0, 0, 0 ), FXRGB( 0x7f, 0x82, 0x5d ), 
		  FXRGB( 0xea, 0xcc, 0x46 ), FXRGB( 0, 0, 0  ) );
    lampboard->setType( Keyboard::TYPE_LAMPBOARD );
    
    sep = new FXHorizontalSeparator( this );
    sep->setBackColor( FXRGB( 0, 0, 0 ) );

    keyboard = new Keyboard( this, this, ID_KEYBOARD, FXRGB( 0x7c, 0x30, 0x30 ), FXRGB( 0xc6, 0xc6, 0xc6 ), FXRGB( 0, 0, 0 ), 
		  FXRGB( 0x54, 0x54, 0x54 ), FXRGB( 0xc6, 0xc6, 0xc6 ) );
    keyboard->setType( Keyboard::TYPE_KEYBOARD );

    sep = new FXHorizontalSeparator( this );
    sep->setBackColor( FXRGB( 0, 0, 0 ) ) ;

    plugboard = new Keyboard( this, NULL, 0, FXRGB( 0x7c, 0x30, 0x30 ), FXRGB( 0, 0, 0 ), FXRGB( 0xc6, 0xc6, 0xc6 ),
		  FXRGB( 0x54, 0x54, 0x54 ), FXRGB( 0, 0, 0 ) );
    plugboard->setType( Keyboard::TYPE_PLUGBOARD );
}

long VEnigma::onKeyPressed( FXObject *obj, FXSelector sel, void *ptr)
{
  lampboard->pressButton( reinterpret_cast<long>(ptr) );
    
  return 1;
}

void VEnigma::setWheelPos( const FXString &pos )
{
    wheelboard->setWheels( pos );
}
