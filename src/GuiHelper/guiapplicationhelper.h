#ifndef GUIAPPLICATIONHELPER_H
#define GUIAPPLICATIONHELPER_H

#include <QObject>

class GuiApplicationHelper : public QObject
{
    Q_OBJECT
public:
    GuiApplicationHelper();

    static QColor adjustColor(const QColor &base, qint8 hueFloat, qint8 saturationFloat, qint8 lightnessFloat,
                                  qint8 redFloat, qint8 greenFloat, qint8 blueFloat, qint8 alphaFloat);
};

#endif // GUIAPPLICATIONHELPER_H
