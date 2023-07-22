#include "fpscaculator.h"
#include <QDateTime>

FPSCaculator::FPSCaculator()
{
    _times.clear();
}

int FPSCaculator::fps()
{
    return _fps;
}

void FPSCaculator::recalculate()
{
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    _times.push_back(currentTime);

    while (_times[0] < currentTime - 1000) {
        _times.pop_front();
    }
    _fps = _times.length();
    emit fpsChanged();
}
