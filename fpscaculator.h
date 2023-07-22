#ifndef FPSCACULATOR_H
#define FPSCACULATOR_H

#include <QObject>

class FPSCaculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int fps READ fps NOTIFY fpsChanged)

public:
    FPSCaculator();
    int fps();
    void recalculate();
private:
    int _fps;
    QVector<qint64> _times;
signals:
    void fpsChanged();
};

Q_DECLARE_METATYPE(FPSCaculator*)

#endif // FPSCACULATOR_H
