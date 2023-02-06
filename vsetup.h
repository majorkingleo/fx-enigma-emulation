#ifndef VSETUP_H
#define VSETUP_H

#include <fx.h>

class VEnigma;

class VSetup : public FXMatrix
{
    FXDECLARE( VSetup );

 public:
    enum {
	ID_WHEEL_ORDER = FXMatrix::ID_LAST,
	ID_RING_SETTING,
	ID_STARTING_POS,
	ID_LAST
    };    

 private:
    VSetup() {}


    FXComboBox *w1;
    FXComboBox *w2;
    FXComboBox *w3;
    FXComboBox *w4;

    FXComboBox *r1;
    FXComboBox *r2;
    FXComboBox *r3;
    FXComboBox *r4;

    FXComboBox *s1;
    FXComboBox *s2;
    FXComboBox *s3;
    FXComboBox *s4;

    FXComboBox *reflector;

    VEnigma    *enigma;

    FXObject   *target;
    FXSelector message;

 public:

    VSetup( FXComposite *p, VEnigma *enigma, FXObject *tgt = NULL, FXSelector sel = 0, FXint opts = MATRIX_BY_COLUMNS );

    long onWheelChanged( FXObject *obj, FXSelector sel, void *p );
    long onStartChanged( FXObject *obj, FXSelector sel, void *p );
};

#endif
