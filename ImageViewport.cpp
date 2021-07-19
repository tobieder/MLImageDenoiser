#include "ImageViewport.h"

#include <QFileDialog>
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QApplication>

#include <QDebug>

// Zoom level is always at least 1, up to the defined max value
#define DEFAULT_ZOOM_LEVEL 10
#define MAX_ZOOM_LEVEL 20

ImageViewport::ImageViewport(QWidget* _parent)
    :QLabel(_parent)
{
    m_ZoomLevel = DEFAULT_ZOOM_LEVEL;


    // Load Image from CommandLine there is a command.
    if (QCoreApplication::arguments().count() == 2)
    {
        LoadImage(QCoreApplication::arguments()[1]);
        m_CurrentView = CurrentView::Input;
        SetImageSize(QString::number(m_ImageOrig.width()) + "x" + QString::number(m_ImageOrig.height()));
    }
}

void ImageViewport::SetImageOrig(QImage _image)
{
    m_ImageOrig = _image;
}

void ImageViewport::SetImageDenoised(QImage _image)
{
    m_ImageDenoised = _image;
}

void ImageViewport::DenoiseImage(QImage _image)
{
    oidn::DeviceRef device = oidn::newDevice();
    device.commit();

    float* colorPtr = new float[_image.width() * _image.height() * 3];

    // ----- Convert image to a format, readable by the denoising algorithm -----
    int counter = 0;

    for (int y = 0; y < _image.height(); y++)
    {
        for (int x = 0; x < _image.width(); x++)
        {
            QColor color = _image.pixel(x, y);
            colorPtr[counter + 0] = (float)color.red() / 255.0f;
            colorPtr[counter + 1] = (float)color.green() / 255.0f;
            colorPtr[counter + 2] = (float)color.blue() / 255.0f;

            counter += 3;
        }
    }

    // ------------------------------------------------------------------------

    float* outputPtr = new float[_image.width() * _image.height() * 3];

    // Creating the in- and outputs for the denoising filter
    // TODO: Allow for normal and albedo maps
    oidn::FilterRef filter = device.newFilter("RT");
    filter.setImage("color", colorPtr, oidn::Format::Float3, _image.width(), _image.height());
    filter.setImage("output", outputPtr, oidn::Format::Float3, _image.width(), _image.height());
    filter.commit();

    qint64 executionTime;
    QElapsedTimer timer;
    timer.start();
    
    filter.execute();

    executionTime = timer.elapsed();

    SetDenoisingTime(QString::number(executionTime) + "ms");
    
    const char* errorMessage;
    if (device.getError(errorMessage) != oidn::Error::None)
        qDebug() << "Error: " << errorMessage;
    else
    {
        // Display filtered image

        QImage filteredImage = QImage(_image.width(), _image.height(), _image.format());

        int counter = 0;
        for (int y = 0; y < _image.height(); y++)
        {
            for (int x = 0; x < _image.width(); x++)
            {
                QColor pixelColor = QColor( (int)(outputPtr[counter + 0] * 255), 
                                            (int)(outputPtr[counter + 1] * 255),
                                            (int)(outputPtr[counter + 2] * 255));
                
                counter += 3;
                
                filteredImage.setPixelColor(x, y, pixelColor);
            }
        }

        SetImageDenoised(filteredImage);
        DisplayImage(m_ImageDenoised);
        m_CurrentView = CurrentView::Denoised;
        OnImageDisplayedImageChanged((int)CurrentView::Denoised);
    }
}

void ImageViewport::LoadImage(QString _path)
{
    QImage img;
    bool valid = img.load(_path);

    if (valid)
    {
        m_ZoomLevel = DEFAULT_ZOOM_LEVEL;

        SetImageOrig(img);
        DisplayImage(m_ImageOrig);
        m_CurrentView = CurrentView::Input;
        OnImageDisplayedImageChanged((int)CurrentView::Input);

        SetImageSize(QString::number(img.width()) + "x" + QString::number(img.height()));
    }
    else
    {
        // Unable to load image.
    }
}

void ImageViewport::SaveImage(QString _path)
{
    m_ImageCurrent.save(_path);
}

void ImageViewport::ResizeImage(int _zoomLevel)
{
    QLabel::setPixmap(m_PixmapCurrent.scaled(QLabel::width() * ((float)_zoomLevel / (float)DEFAULT_ZOOM_LEVEL), QLabel::height() * ((float)_zoomLevel / (float)DEFAULT_ZOOM_LEVEL), Qt::KeepAspectRatio));
}

void ImageViewport::DisplayImage(QImage _image)
{

    m_ImageCurrent = _image;
    m_PixmapCurrent = QPixmap::fromImage(_image);
    QLabel::setPixmap(m_PixmapCurrent.scaled(QLabel::width(), QLabel::height(), Qt::KeepAspectRatio));

    ResizeImage(m_ZoomLevel);
}

void ImageViewport::OnMenuBarTriggeredAction(QAction* _action)
{
    if (_action->text() == QString("Load Image"))
    {
        OnBtnLoadImageClicked();
    }
    else if (_action->text() == QString("Save Image"))
    {
        OnBtnSaveImageClicked();
    }
    else
    {
        qWarning() << "Unknown _action->text()";
    }
}

void ImageViewport::OnBtnLoadImageClicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Choose"), "example_imgs/", tr("Images (*.png *.jpg *.jpeg *.bmp *.ppm)"));

    if (QString::compare(path, QString()) != 0)
    {
        LoadImage(path);
    }
    else
    {
        // Canceled loading the image.
    }
}

void ImageViewport::OnBtnSaveImageClicked()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save Image File"), QString(), tr("Images (*.png *.jpg *.jpeg *.bmp)"));

    SaveImage(path);
}

void ImageViewport::OnBtnDenoiseImageClicked()
{
    if (!m_ImageOrig.isNull())
    {
        DenoiseImage(m_ImageOrig);
    }
}

void ImageViewport::OnCmbViewSelectChanged(int _index)
{
    qDebug();
    qDebug() << "index: " << _index;
    qDebug();

    m_CurrentView = (CurrentView)_index;

    switch (m_CurrentView)
    {
    case CurrentView::Input:
        DisplayImage(m_ImageOrig);
        break;
    case CurrentView::Denoised:
        if (m_ImageDenoised.isNull() && !m_ImageOrig.isNull())
        {
            DenoiseImage(m_ImageOrig);
        }
        DisplayImage(m_ImageDenoised);
        break;
    default:
        break;
    }
}


#pragma region Events

void ImageViewport::resizeEvent(QResizeEvent* event)
{
    QLabel::setPixmap(m_PixmapCurrent.scaled(QLabel::width(), QLabel::height(), Qt::KeepAspectRatio));
}

void ImageViewport::wheelEvent(QWheelEvent* event)
{
    if (event->angleDelta().y() > 0)
    {
        m_ZoomLevel++;
    }
    else if(event->angleDelta().y() < 0)
    {
        m_ZoomLevel--;
    }

#pragma region Clamp Zoom Level

    if (m_ZoomLevel < 1)
    {
        m_ZoomLevel = 1;
    }
    else if (m_ZoomLevel > MAX_ZOOM_LEVEL)
    {
        m_ZoomLevel = MAX_ZOOM_LEVEL;
    }

#pragma endregion


    ResizeImage(m_ZoomLevel);
}

void ImageViewport::mousePressEvent(QMouseEvent* event)
{
    QApplication::setOverrideCursor(Qt::ClosedHandCursor);
}

void ImageViewport::mouseReleaseEvent(QMouseEvent* event)
{
    QApplication::restoreOverrideCursor();
}

void ImageViewport::mouseMoveEvent(QMouseEvent* event)
{
}

#pragma endregion
