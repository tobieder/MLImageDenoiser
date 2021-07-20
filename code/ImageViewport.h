#pragma once

#include <QtCore/qobject.h>

#include <QLabel>
#include <QWheelEvent>
#include <QAction>

#include <OpenImageDenoise/oidn.hpp>

enum CurrentView { Input, Denoised };

class ImageViewport : public QLabel
{
	Q_OBJECT

public:
	ImageViewport(QWidget* _parent);

	void SetImageOrig(QImage _image);
	void SetImageDenoised(QImage _image);
	void DenoiseImage(QImage _image);

private:
	void LoadImage(QString _path);
	void SaveImage(QString _path);
	void ResizeImage(int _zoomLevel);

	void DisplayImage(QImage _image);

private slots:
	void OnMenuBarTriggeredAction(QAction* _action);
	void OnBtnLoadImageClicked();
	void OnBtnSaveImageClicked();
	void OnBtnDenoiseImageClicked();

	void OnCmbViewSelectChanged(int _index);

signals:
	void OnImageDisplayedImageChanged(int _index);
	void SetImageSize(QString _size);
	void SetDenoisingTime(QString _time);

private:
	QImage m_ImageOrig;
	QImage m_ImageDenoised;

	QImage m_ImageCurrent;
	QPixmap m_PixmapCurrent;

	CurrentView m_CurrentView;

	int m_ZoomLevel;

protected:
	void resizeEvent(QResizeEvent* event);
	void wheelEvent(QWheelEvent* event);

	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
};

