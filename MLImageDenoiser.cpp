#include "MLImageDenoiser.h"

MLImageDenoiser::MLImageDenoiser(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.cmb_ViewSelect->addItem("Input");
    ui.cmb_ViewSelect->addItem("Denoised");
}
