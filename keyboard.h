#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <fx.h>

class Button;

class Keyboard : public FXVerticalFrame
{
    FXDECLARE( Keyboard );
 public:

    enum {
	ID_BUTTON_PRESSED = FXVerticalFrame::ID_LAST,
	ID_TIMER,
	ID_LAST
    };

    enum Type {
	TYPE_LAMPBOARD,
	TYPE_KEYBOARD,
	TYPE_PLUGBOARD	
    };

 protected:
    FXObject   *target;
    FXSelector message;
    char       last_pressed;
    Type       type;

    struct Pair
    {
	char a;
	char b;

	Pair() : a(0), b(0) {}
    };

    static const int NUM_BUTTONS = 26;
    static const int NUM_PAIRS = NUM_BUTTONS / 2;
    static const int NUM_ROWS = 3;
    static const int NUM_FRAMES = 26;

    Pair  pairs[NUM_PAIRS];

    Button *buttons[NUM_BUTTONS];
    FXHorizontalFrame *contents[NUM_ROWS];

    FXFrame *frames[NUM_FRAMES];

 private:
    Keyboard() {}

 public:
    Keyboard( FXComposite *p, FXObject *tgt = NULL, FXSelector sel = 0,
	      FXColor c_background = FXRGB( 0x7c, 0x30, 0x30 ),
	      FXColor c_border = FXRGB( 0, 0, 0 ),
	      FXColor c_front = FXRGB( 0xea, 0xcc, 0x46 ),
	      FXColor c_front_active = FXRGB( 0x7f, 0x82, 0x5d ),
	      FXColor c_text_color = FXRGB( 0, 0, 0 ) );
    ~Keyboard();

    long onButtonPressed( FXObject * obj, FXSelector sel, void *p );
    void pressButton( char c );
    void releaseButton( char c );

    void setType( Type t );

    long onPaint( FXObject *obj, FXSelector sel, void *ptr );
    long onChanged( FXObject *obj, FXSelector sel, void *ptr );
    long onTimeout( FXObject *obj, FXSelector sel, void *ptr );

    void drawWire();

 private:
    Button* getButton( char c ) { return buttons[ c - 'A' ]; }
    void    setButton( char c, Button *b ) { buttons[ c - 'A' ] = b; }
    void    addFrame( FXFrame *f );
    void    updateFrames();
    void    forceUpdate();
};

#endif
