#include <fx.h>
#include "venigma.h"
#include "vsetup.h"

class MainWindow : public FXMainWindow
{
    FXDECLARE( MainWindow );
private:
    MainWindow() {}

public:
    enum {
	ID_KEYBOARD = FXMainWindow::ID_LAST,
	ID_LAST
    };

public:
    MainWindow( FXApp *app );
    ~MainWindow();
    
    long onKeyPressed( FXObject *obj, FXSelector sel, void *ptr);

    void create();
};

FXDEFMAP( MainWindow ) MainWindowMap[] = {
};

FXIMPLEMENT( MainWindow, FXMainWindow, MainWindowMap, ARRAYNUMBER( MainWindowMap ) );

MainWindow::MainWindow( FXApp *app )
    : FXMainWindow( app, "Button", NULL, NULL, DECOR_ALL, 0, 0, 800, 600 )
{
    FXVerticalFrame *content = new FXVerticalFrame( this, LAYOUT_FILL_X | LAYOUT_FILL_Y );

    FXTabBook *book = new FXTabBook( content, NULL, 0, LAYOUT_FILL_X | LAYOUT_FILL_Y );
    
    new FXTabItem( book, "M3 Enigma", 0, FRAME_RAISED );

    FXHorizontalFrame *f = new FXHorizontalFrame( book, LAYOUT_FILL_X | LAYOUT_FILL_Y | FRAME_RAISED );
    VEnigma *m3 = new VEnigma( f, VEnigma::TYPE_M3, NULL, 0, LAYOUT_FILL_Y | FRAME_SUNKEN );

    FXVerticalFrame *vf = new FXVerticalFrame( f, LAYOUT_FILL_X | LAYOUT_FILL_Y );
    new VSetup( vf, m3, NULL, 0 );
    new FXHorizontalSeparator( vf );
    new FXLabel( vf, "Output" );
    new FXText( vf, NULL, 0, FRAME_SUNKEN | LAYOUT_FILL_X | LAYOUT_FIX_HEIGHT, 0, 0, 300, 200 );
    new FXHorizontalSeparator( vf );
    new FXLabel( vf, "Input" );
    new FXText( vf, NULL, 0, FRAME_SUNKEN | LAYOUT_FILL_X | LAYOUT_FIX_HEIGHT, 0, 0, 300, 200 );


    new FXTabItem( book, "M4 Enigma", 0, FRAME_RAISED );
    f = new FXHorizontalFrame( book, LAYOUT_FILL_X | LAYOUT_FILL_Y | FRAME_RAISED );
    VEnigma *m4 = new VEnigma( f, VEnigma::TYPE_M4, NULL, 0, LAYOUT_FILL_Y | FRAME_RAISED );
    
    vf = new FXVerticalFrame( f, LAYOUT_FILL_X | LAYOUT_FILL_Y );
    new VSetup( vf, m4, NULL, 0 );
}

MainWindow::~MainWindow()
{

}

void MainWindow::create()
{
    FXMainWindow::create();
    show( PLACEMENT_SCREEN );
}

int main( int argc, char ** argv )
{
    FXApp app( "FOXEnigma", "genigma" );

    app.init( argc, argv );

    new MainWindow( &app );

    app.create();

    return app.run();
}
