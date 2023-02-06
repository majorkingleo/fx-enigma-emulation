#ifndef BUTTON_H
#define BUTTON_H

#include <fx.h>

class Button : public FXButton
{
    FXDECLARE( Button );
 public:

    enum Type {
	TYPE_BUTTON,
	TYPE_LIGHT,
	TYPE_PLUG
    };

private:

    FXColor c_back;
    FXColor c_border;
    FXColor c_front;
    FXColor c_pressed;
    FXColor c_text;

    Type type;

private:
    Button() {}    

public:
    Button( FXComposite *p, const FXString &text, FXObject *tgt = NULL, FXSelector sel = 0, FXuint opts = BUTTON_NORMAL,
	    FXint x = 0, FXint y = 0, FXint w = 0, FXint h = 0, FXint pl = DEFAULT_PAD, FXint pr = DEFAULT_PAD,
	    FXint pt = DEFAULT_PAD, FXint pb = DEFAULT_PAD );

    void setCBackground( FXColor c ) { c_back = c; }
    void setCBorder( FXColor c ) { c_border = c; }
    void setCFront( FXColor c ) { c_front = c; }
    void setCFrontActive( FXColor c ) { c_pressed = c; }
    void setCText( FXColor c ) { c_text = c; }

    void setType( Type t ) { type = t; }

    long onPaint( FXObject*, FXSelector, void * p);
    long onLeftButtonPress( FXObject*, FXSelector, void * p);
};


#endif
