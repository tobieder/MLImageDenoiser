/********************************************************************************
** Form generated from reading UI file 'MLImageDenoiser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MLIMAGEDENOISER_H
#define UI_MLIMAGEDENOISER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ImageViewport.h"

QT_BEGIN_NAMESPACE

class Ui_MLImageDenoiserClass
{
public:
    QAction *actionLoad_Image;
    QAction *actionSave_Image;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    ImageViewport *lbl_ImageView;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QComboBox *cmb_ViewSelect;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btn_denoiseImage;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MLImageDenoiserClass)
    {
        if (MLImageDenoiserClass->objectName().isEmpty())
            MLImageDenoiserClass->setObjectName(QString::fromUtf8("MLImageDenoiserClass"));
        MLImageDenoiserClass->resize(1419, 741);
        MLImageDenoiserClass->setCursor(QCursor(Qt::ArrowCursor));
        MLImageDenoiserClass->setTabShape(QTabWidget::Rounded);
        actionLoad_Image = new QAction(MLImageDenoiserClass);
        actionLoad_Image->setObjectName(QString::fromUtf8("actionLoad_Image"));
        actionSave_Image = new QAction(MLImageDenoiserClass);
        actionSave_Image->setObjectName(QString::fromUtf8("actionSave_Image"));
        centralWidget = new QWidget(MLImageDenoiserClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lbl_ImageView = new ImageViewport(centralWidget);
        lbl_ImageView->setObjectName(QString::fromUtf8("lbl_ImageView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_ImageView->sizePolicy().hasHeightForWidth());
        lbl_ImageView->setSizePolicy(sizePolicy);
        lbl_ImageView->setMinimumSize(QSize(1280, 720));
        lbl_ImageView->setMaximumSize(QSize(99999, 99999));
        lbl_ImageView->setCursor(QCursor(Qt::OpenHandCursor));
        lbl_ImageView->setStyleSheet(QString::fromUtf8("background: #ebebeb"));
        lbl_ImageView->setAlignment(Qt::AlignCenter);
        lbl_ImageView->setMargin(0);

        horizontalLayout->addWidget(lbl_ImageView);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 5, 3, 5);
        cmb_ViewSelect = new QComboBox(centralWidget);
        cmb_ViewSelect->setObjectName(QString::fromUtf8("cmb_ViewSelect"));

        verticalLayout->addWidget(cmb_ViewSelect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 60));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox);

        btn_denoiseImage = new QPushButton(centralWidget);
        btn_denoiseImage->setObjectName(QString::fromUtf8("btn_denoiseImage"));
        btn_denoiseImage->setMinimumSize(QSize(130, 0));

        verticalLayout->addWidget(btn_denoiseImage);


        horizontalLayout->addLayout(verticalLayout);

        MLImageDenoiserClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MLImageDenoiserClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1419, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MLImageDenoiserClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_Image);
        menuFile->addAction(actionSave_Image);

        retranslateUi(MLImageDenoiserClass);
        QObject::connect(btn_denoiseImage, SIGNAL(clicked()), lbl_ImageView, SLOT(OnBtnDenoiseImageClicked()));
        QObject::connect(cmb_ViewSelect, SIGNAL(currentIndexChanged(int)), lbl_ImageView, SLOT(OnCmbViewSelectChanged(int)));
        QObject::connect(lbl_ImageView, SIGNAL(OnImageDisplayedImageChanged(int)), cmb_ViewSelect, SLOT(setCurrentIndex(int)));
        QObject::connect(lbl_ImageView, SIGNAL(SetDenoisingTime(QString)), label_2, SLOT(setText(QString)));
        QObject::connect(lbl_ImageView, SIGNAL(SetImageSize(QString)), label_4, SLOT(setText(QString)));
        QObject::connect(menuBar, SIGNAL(triggered(QAction*)), lbl_ImageView, SLOT(OnMenuBarTriggeredAction(QAction*)));

        QMetaObject::connectSlotsByName(MLImageDenoiserClass);
    } // setupUi

    void retranslateUi(QMainWindow *MLImageDenoiserClass)
    {
        MLImageDenoiserClass->setWindowTitle(QCoreApplication::translate("MLImageDenoiserClass", "MLImageDenoiser", nullptr));
        actionLoad_Image->setText(QCoreApplication::translate("MLImageDenoiserClass", "Load Image", nullptr));
        actionSave_Image->setText(QCoreApplication::translate("MLImageDenoiserClass", "Save Image", nullptr));
        lbl_ImageView->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MLImageDenoiserClass", "Stats", nullptr));
        label_3->setText(QCoreApplication::translate("MLImageDenoiserClass", "Img-Size:", nullptr));
        label_4->setText(QString());
        label->setText(QCoreApplication::translate("MLImageDenoiserClass", "Time:", nullptr));
        label_2->setText(QString());
        btn_denoiseImage->setText(QCoreApplication::translate("MLImageDenoiserClass", "Denoise Image", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MLImageDenoiserClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MLImageDenoiserClass: public Ui_MLImageDenoiserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MLIMAGEDENOISER_H
