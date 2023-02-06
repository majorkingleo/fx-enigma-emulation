#include "button.h"

FXDEFMAP( Button ) ButtonMap[] = {
    FXMAPFUNC( SEL_PAINT, 0, Button::onPaint ),
    FXMAPFUNC( SEL_LEFTBUTTONPRESS, 0, Button::onLeftButtonPress )
};

FXIMPLEMENT( Button, FXButton, ButtonMap, ARRAYNUMBER( ButtonMap ) );

Button::Button( FXComposite *p, const FXString &text, FXObject *tgt, FXSelector sel, FXuint opts, FXint x, FXint y, FXint w,
		FXint h, FXint pl, FXint pr, FXint pt, FXint pb )
    : FXButton( p, text, NULL, tgt, sel, opts, x, y, w, h, pl, pr, pt, pb )
{
    c_back = FXRGB( 0x7c, 0x30, 0x30 );
    c_border = FXRGB( 0, 0, 0 );
    c_front = FXRGB( 0xea, 0xcc, 0x46 );
    c_pressed = FXRGB( 0x7f, 0x82, 0x5d );
    type = TYPE_BUTTON;
}

long Button::onPaint( FXObject*, FXSelector, void * ptr)
{
    FXEvent *ev = (FXEvent*)ptr;

    const int b = 3;
    int left, right, top, bottom;

    if( width > height )
    {
	left = right = (width - height) / 2;
	top = bottom =  0;
    }
    else
    {
	left = right = 0;
	top = bottom = (height - width) / 2;
    }

    

    FXDCWindow dc( this, ev );

    dc.setForeground( c_back );
    dc.fillRectangle( 0, 0, width, height );

    dc.setForeground( c_border );
    dc.fillArc( border + left, border + top, 
		width - border*2 - left - right, 
		height - border*2 - top - bottom, 
		0, 360 * 64 );

    if( state == STATE_DOWN )
	dc.setForeground( c_pressed );
    else
	dc.setForeground( c_front );

    dc.fillArc( border + b + left, border + b + top, 
		width - b * 2 - border*2 - right - left, 
		height - b * 2 - border*2 - top - bottom, 
		0, 360 * 64 );

    int tw = font->getTextWidth( label.text(), label.length());
    int th = font->getFontHeight();

    dc.setForeground( c_border );
    dc.setFont( font );
    dc.drawText( width / 2 - tw / 2, height / 2 + th / 2 , label.text(), label.length() );

    return 1;
}

long Button::onLeftButtonPress( FXObject* obj, FXSelector sel, void * p)
{
    if( type == TYPE_BUTTON )
	return FXButton::onLeftBtnPress( obj, sel, p );
    if( type == TYPE_PLUG )
    {
	if( state == STATE_DOWN )
	    setState( STATE_UP );
	else
	    setState( STATE_DOWN );

	target->handle( this, MKUINT( message, SEL_CHANGED ), &state );

	return 1;
    }

    return 0;
}
