#include "vsetup.h"
#include "venigma.h"

FXDEFMAP( VSetup ) VSetupMap[] = {
    FXMAPFUNC( SEL_COMMAND, VSetup::ID_WHEEL_ORDER, VSetup::onWheelChanged ),
    FXMAPFUNC( SEL_COMMAND, VSetup::ID_STARTING_POS, VSetup::onStartChanged )
};

FXIMPLEMENT( VSetup, FXMatrix, VSetupMap, ARRAYNUMBER( VSetupMap ) );

VSetup::VSetup( FXComposite *p, VEnigma *enigma, FXObject *tgt, FXSelector sel, FXint opts )
    : FXMatrix( p, 4, opts |= MATRIX_BY_COLUMNS ),
      enigma( enigma ),
      target( tgt ),
      message( sel )
{
    int wheels = 5;

    if( enigma->getType() == VEnigma::TYPE_M4 )
    {
	setNumColumns( 5 );
	wheels = 8;
    }
    else
	w4 = r4 = s4 = reflector = 0;

    new FXLabel( this, "Wheel order:" );

    if( enigma->getType() == VEnigma::TYPE_M4 )
    {
	w4 = new FXComboBox( this, 5, this, ID_WHEEL_ORDER, FRAME_SUNKEN );
	w4->appendItem( "Betha" );
	w4->appendItem( "Gamma" );
    }

    w1 = new FXComboBox( this, 2, this, ID_WHEEL_ORDER, FRAME_SUNKEN );
    w2 = new FXComboBox( this, 2, this, ID_WHEEL_ORDER, FRAME_SUNKEN );
    w3 = new FXComboBox( this, 2, this, ID_WHEEL_ORDER, FRAME_SUNKEN );

    for( int i = 0; i < wheels; ++i )
    {
	w1->appendItem( FXString().format( "%d", i + 1 ) );
	w2->appendItem( FXString().format( "%d", i + 1 ) );
	w3->appendItem( FXString().format( "%d", i + 1 ) );
    }

    w2->setCurrentItem( 1 );
    w3->setCurrentItem( 2 );

    new FXLabel( this, "Ring setting:" );

    if( enigma->getType() == VEnigma::TYPE_M4 )
    {
	r4 = new FXComboBox( this, 2, this, ID_RING_SETTING, FRAME_SUNKEN );

	for( int i = 'A'; i <= 'Z'; ++i )
	    r4->appendItem( FXString().format( "%c", (char)i) );
    }


    r1 = new FXComboBox( this, 2, this, ID_RING_SETTING, FRAME_SUNKEN );
    r2 = new FXComboBox( this, 2, this, ID_RING_SETTING, FRAME_SUNKEN );
    r3 = new FXComboBox( this, 2, this, ID_RING_SETTING, FRAME_SUNKEN );
   

    for( int i = 'A'; i <= 'Z'; ++i )
	r1->appendItem( FXString().format( "%c", (char)i) );

    for( int i = 'A'; i <= 'Z'; ++i )
	r2->appendItem( FXString().format( "%c", (char)i) );

    for( int i = 'A'; i <= 'Z'; ++i )
	r3->appendItem( FXString().format( "%c", (char)i) );

    new FXLabel( this, "Starting position:" );

    if( enigma->getType() == VEnigma::TYPE_M4 )
    {
	s4 = new FXComboBox( this, 2, this, ID_STARTING_POS, FRAME_SUNKEN );

	for( int i = 'A'; i <= 'Z'; ++i )
	    s4->appendItem( FXString().format( "%c", (char)i) );
    }

    s1 = new FXComboBox( this, 2, this, ID_STARTING_POS, FRAME_SUNKEN );
    s2 = new FXComboBox( this, 2, this, ID_STARTING_POS, FRAME_SUNKEN );
    s3 = new FXComboBox( this, 2, this, ID_STARTING_POS, FRAME_SUNKEN );

    for( int i = 'A'; i <= 'Z'; ++i )
	s1->appendItem( FXString().format( "%c", (char)i) );
    
    for( int i = 'A'; i <= 'Z'; ++i )
	s2->appendItem( FXString().format( "%c", (char)i) );
    
    for( int i = 'A'; i <= 'Z'; ++i )
	s3->appendItem( FXString().format( "%c", (char)i) );

    if( enigma->getType() == VEnigma::TYPE_M4 )
    {
	new FXLabel( this, "Reflector:" );
	reflector = new FXComboBox( this, 2, NULL, 0, FRAME_SUNKEN );
	reflector->appendItem( "B" );
	reflector->appendItem( "C" );
    }

    
}

long VSetup::onWheelChanged( FXObject *obj, FXSelector sel, void *p )
{
    int a = w1->getCurrentItem();
    int b = w2->getCurrentItem();
    int c = w3->getCurrentItem();
    
    if( a == b || a == c || b == c )
    {
	FXMessageBox::error( this, MBOX_OK, "Setup error", "You can not use the same wheel twice!" );	
    }

    return 1;
}

long VSetup::onStartChanged( FXObject *obj, FXSelector sel, void *p )
{
    FXString pos;

    if( enigma->getType() == VEnigma::TYPE_M4 )
	pos += 'A' + (char) s4->getCurrentItem();

    pos += 'A' + (char) s1->getCurrentItem();
    pos += 'A' + (char) s2->getCurrentItem();
    pos += 'A' + (char) s3->getCurrentItem();

    enigma->setWheelPos( pos );

    return 1;
}
