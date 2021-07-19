#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MLImageDenoiser.h"

class MLImageDenoiser : public QMainWindow
{
    Q_OBJECT

public:
    MLImageDenoiser(QWidget *parent = Q_NULLPTR);

private:
    Ui::MLImageDenoiserClass ui;
};
