#include "keyboard.h"
#include "button.h"

FXDEFMAP( Keyboard ) KeyboardMap[] = {
    FXMAPFUNC( SEL_COMMAND, Keyboard::ID_BUTTON_PRESSED, Keyboard::onButtonPressed ),    
    FXMAPFUNC( SEL_PAINT, 0, Keyboard::onPaint ),
    FXMAPFUNC( SEL_CHANGED, Keyboard::ID_BUTTON_PRESSED, Keyboard::onChanged ),
    FXMAPFUNC( SEL_TIMEOUT, Keyboard::ID_TIMER, Keyboard::onTimeout )
};

FXIMPLEMENT( Keyboard, FXVerticalFrame, KeyboardMap, ARRAYNUMBER( KeyboardMap ) );

Keyboard::Keyboard( FXComposite *p, FXObject *tgt, FXSelector sel, FXColor c_back, FXColor c_border,
		    FXColor c_front, FXColor c_front_active, FXColor c_text_color )
    : FXVerticalFrame( p, LAYOUT_CENTER_X ),
      target( tgt ),
      message( sel ),
      last_pressed( 0 ),
      type( TYPE_KEYBOARD )
{
    for( int i = 0; i < NUM_FRAMES; ++i )
	frames[i] = 0;

    FXFrame *f;

    setBackColor( c_back );

    FXHorizontalFrame *content = contents[0] = new FXHorizontalFrame( this, LAYOUT_FILL_X );
    content->setBackColor( c_back );

    setButton( 'Q', new Button( content, "Q", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'W', new Button( content, "W", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'E', new Button( content, "E", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'R', new Button( content, "R", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'T', new Button( content, "T", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'Z', new Button( content, "Z", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'U', new Button( content, "U", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'I', new Button( content, "I", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'O', new Button( content, "O", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );

    content = contents[1] = new FXHorizontalFrame( this, LAYOUT_FILL_X );
    content->setBackColor( c_back );

    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'A', new Button( content, "A", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'S', new Button( content, "S", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'D', new Button( content, "D", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'F', new Button( content, "F", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'G', new Button( content, "G", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'H', new Button( content, "H", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'J', new Button( content, "J", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'K', new Button( content, "K", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );

    content = contents[2] = new FXHorizontalFrame( this, LAYOUT_FILL_X );
    content->setBackColor( c_back );

    setButton( 'P', new Button( content, "P", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'Y', new Button( content, "Y", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'X', new Button( content, "X", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'C', new Button( content, "C", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'V', new Button( content, "V", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'B', new Button( content, "B", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'N', new Button( content, "N", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'M', new Button( content, "M", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );
    f = new FXFrame( content, LAYOUT_FIX_WIDTH | FRAME_NONE, 0, 0, 10, 10 );  f->setBackColor( c_back ); addFrame( f );
    setButton( 'L', new Button( content, "L", this, ID_BUTTON_PRESSED, LAYOUT_FIX_WIDTH | LAYOUT_FIX_HEIGHT , 0, 0, 30, 30 ) );

    for( int i = 'A'; i <= 'Z'; ++i )
    {
	getButton( i )->setCBackground( c_back );
	getButton( i )->setCBorder( c_border );
	getButton( i )->setCFront( c_front );
	getButton( i )->setCFrontActive( c_front_active );
	getButton( i )->setCText( c_text_color );
    }
}

Keyboard::~Keyboard()
{
  getApp()->removeTimeout(this, Keyboard::ID_TIMER);
  // getApp()->removeTimeout( timer );
}

long Keyboard::onButtonPressed( FXObject * obj, FXSelector sel, void *p )
{
    for( long i = 'A'; i <= 'Z'; ++i )
	if( obj == (FXObject*) getButton( i ) )
	{
	    if( target )	    
		return target->handle( this, MKUINT( message, SEL_COMMAND ), (void*)i );
	    break;
	}

    return 0;
}

void Keyboard::pressButton( char c )
{
    if( c < 'A' || c > 'Z' )
	return;    

    if( last_pressed )
   	releaseButton( last_pressed );
    
    last_pressed = c;
    
    getButton( c )->setState( STATE_DOWN );
}

void Keyboard::releaseButton( char c )
{
    if( c < 'A' || c > 'Z' )
	return;

    getButton( c )->setState( STATE_UP );
}

void Keyboard::setType( Type t )
{
    type = t;

    Button::Type bt = Button::TYPE_BUTTON;

    if( type == TYPE_LAMPBOARD )
	bt = Button::TYPE_LIGHT;
    if( type == TYPE_PLUGBOARD )
	bt = Button::TYPE_PLUG;

    for( int i = 'A'; i <= 'Z'; ++i )
	getButton( i )->setType( bt );

    if( type == TYPE_PLUGBOARD )
      getApp()->addTimeout( this, ID_TIMER, 1000 );
}

void Keyboard::drawWire()
{
    if( type != TYPE_PLUGBOARD )
	return;
    
    FXDCWindow dc( this );
    
    dc.clipChildren( false );
    
    dc.setForeground( FXRGB( 255, 0, 0 ) );
    
    for( int i = 0; i < NUM_PAIRS; ++i )
	if( pairs[i].a )
	{
	    Button *a = getButton( pairs[i].a );
	    Button *b = getButton( pairs[i].b );
	    
	    int x1 = a->getX() + a->getWidth() / 2;
	    int y1 = a->getY() + a->getHeight() / 2;

	    int x2 = b->getX() + b->getWidth() / 2;
	    int y2 = b->getY() + b->getHeight() / 2;


	    bool found_a = false;
	    bool found_b = false;

	    for( int j = 0; j < NUM_ROWS; ++j )
	    {
		if( !found_a && contents[j]->containsChild( a ) )
		{
		    found_a = true;

		    x1 += contents[j]->getX();
		    y1 += contents[j]->getY();

		} 

		if( !found_b && contents[j]->containsChild( b ) ) 
		{
		    found_b = true;

		    x2 += contents[j]->getX();
		    y2 += contents[j]->getY();
		}
	    }

	    dc.drawLine( x1, y1, x2, y2 );
	}    
}

long Keyboard::onPaint( FXObject *obj, FXSelector sel, void *ptr )
{
    FXDCWindow dc( this );

    dc.setForeground( getBackColor() );
    dc.fillRectangle( 0, 0, width, height );

    if( type != TYPE_PLUGBOARD )
	return 1;   

    drawWire();

    return 1;
}

long Keyboard::onChanged( FXObject *obj, FXSelector sel, void *ptr )
{
    if( type != TYPE_PLUGBOARD )
	return 0;

    for( int i = 'A'; i <= 'Z'; ++i )
	if( obj == getButton( i ) )
	{
	    if( *((int*)ptr) == STATE_DOWN )
	    {
		if( !last_pressed )
		{
		    last_pressed = i;
		    break;
		} else {
		    for( int j = 0; j < NUM_PAIRS; ++j )
			if( !pairs[j].a )
			{
			    pairs[j].a = last_pressed;
			    pairs[j].b = i;

			    last_pressed = 0;
			    break;     
			}
		}
	    } else {

		for( int j = 0; j < NUM_PAIRS; ++j )
		    if( pairs[j].a == i || pairs[j].b == i )
		    {
			getButton( pairs[j].a )->setState( STATE_UP );
			getButton( pairs[j].b )->setState( STATE_UP );

			pairs[j].a = 0;
			pairs[j].b = 0;

			break;
		    }

		last_pressed = 0;
	    }

	    break;
	}
    

    forceUpdate();

    return 1;
}

void Keyboard::addFrame( FXFrame *f )
{
    for( int i = 0; i < NUM_FRAMES; ++i )
	if( !frames[i] )
	{
	    frames[i] = f;
	    break;
	}
}

void Keyboard::updateFrames()
{
    for( int i = 0; i < NUM_FRAMES; ++i )
	if( frames[i] )
	    frames[i]->update();
}

void Keyboard::forceUpdate()
{
    for( int i = 0 ; i < NUM_ROWS; ++i )
	contents[i]->update();

    for( int i = 'A'; i <= 'Z'; ++i )
	getButton( i )->update();

    updateFrames();

    update();
}

long Keyboard::onTimeout( FXObject *obj, FXSelector sel, void *ptr )
{
    if( type == TYPE_PLUGBOARD )
    {
      getApp()->addTimeout( this, ID_TIMER, 1000 );
	
	for( int i = 0; i < NUM_PAIRS; ++i )
	    if( pairs[i].a )
	    {	
		forceUpdate();	
		break;
	    }
    }

    return 1;
}
