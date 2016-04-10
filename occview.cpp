#include "occview.h"

#include "occtwindow.h"

//OCC libraries
#include <Aspect_DisplayConnection.hxx>

#include <Graphic3d_GraphicDriver.hxx>
#include <OpenGl_GraphicDriver.hxx>

#include <TCollection_AsciiString.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <V3d_TypeOfSurfaceDetail.hxx>
#include <Standard_Type.hxx>

OccView::OccView(QWidget *parent)
    : QWidget(parent)
{

    Handle_Aspect_DisplayConnection aDisplayConnection;
    Handle_OpenGl_GraphicDriver aGraphicDriver;

    // 1. Create a 3D viewer.
    aDisplayConnection = new Aspect_DisplayConnection (qgetenv ("DISPLAY").constData());
    aGraphicDriver = new OpenGl_GraphicDriver(aDisplayConnection);

    mViewer = new V3d_Viewer(aGraphicDriver, Standard_ExtString("Visu3D"));
    mViewer->SetDefaultLights();
    mViewer->SetLightOn();

    // 3. Create an interactive context.
    mContext = new AIS_InteractiveContext(mViewer);
    mContext->SetDisplayMode(AIS_Shaded);

    if ( mView.IsNull() )
        mView = mContext->CurrentViewer()->CreateView();

    Handle(OcctWindow) hWnd = new OcctWindow( this );

    mView->SetWindow (hWnd);
    if ( !hWnd->IsMapped() )
    {
        hWnd->Map();
    }

//    mView->SetBackgroundColor (Quantity_NOC_BLACK);
    mView->MustBeResized();

    //Eixo x, y, z
    mView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);
#if 0
    Handle(OpenGl_GraphicDriver) aGraphicDriver;

    if(aGraphicDriver.IsNull())
    {
        Handle(Aspect_DisplayConnection) aDisplayConnection;
        aGraphicDriver = new OpenGl_GraphicDriver(aDisplayConnection);
    }

    TCollection_ExtendedString a3DName ("Visu3D");

    mViewer = new V3d_Viewer (aGraphicDriver,
                              a3DName.ToExtString(),
                              "",
                              1000.0,
                              V3d_XposYnegZpos,
                              Quantity_NOC_GRAY30,
                              V3d_ZBUFFER,
                              V3d_GOURAUD,
                              V3d_WAIT,
                              Standard_True,
                              Standard_True,
                              V3d_TEX_NONE);

    mViewer->SetDefaultLights();
    mViewer->SetLightOn();


    mContext = new AIS_InteractiveContext(mViewer);

    if ( mView.IsNull() )
        mView = mContext->CurrentViewer()->CreateView();

    Handle(OcctWindow) hWnd = new OcctWindow( this );
    mView->SetWindow (hWnd);
    if ( !hWnd->IsMapped() )
    {
        hWnd->Map();
    }

    mView->SetBackgroundColor(Quantity_NOC_BLACK);
    mView->MustBeResized();
#endif

}

void OccView::paintEvent(QPaintEvent *)
{
    mView->Redraw();
}

void OccView::resizeEvent(QResizeEvent *)
{
    mView->MustBeResized();
}
