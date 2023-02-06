#ifndef VENIGMA_H
#define VENIGMA_H

#include <fx.h>

class Keyboard;
class WheelBoard;

class VEnigma : public FXVerticalFrame
{
    FXDECLARE( VEnigma );
 public:
    enum {
	ID_KEYBOARD = FXVerticalFrame::ID_LAST,
	ID_LAST
    };

    enum Type {
	TYPE_M3,
	TYPE_M4
    };

 private:
    VEnigma() {}

    FXObject   *target;
    FXSelector  message;

    Keyboard   *keyboard;
    Keyboard   *plugboard;
    Keyboard   *lampboard;
    WheelBoard *wheelboard;

    Type type;

 public:
    VEnigma( FXComposite *p, Type type, FXObject *tgt, FXSelector sel, FXuint opts );

    long onKeyPressed( FXObject *obj, FXSelector sel, void *ptr);

    Type getType() const { return type; }

    void setWheelPos( const FXString &pos );
};

#endif
