#include "stopwatch.h"
#include <QModelIndex>

StopWatch::StopWatch(QLabel *l)
    : QObject{nullptr}
{
    time = new QTime(0, 0);
    timer = new QTimer();
    lastCircleTime = nullptr;
    QObject::connect(timer, &QTimer::timeout, this, [=](){
        time = new QTime(time->addMSecs(100));
        l->setText(time->toString("hh:mm:ss.zzz"));
    });

}

QAbstractListModel *StopWatch::getCirclesModel()
{
    return model;
}

QString StopWatch::circle()
{
    if (lastCircleTime == nullptr) {
        lastCircleTime = time;
        return time->toString("hh:mm:ss.zzz");
    } else {
        auto circleTime = lastCircleTime->msecsTo(*time);
        lastCircleTime = time;

        QTime t(0, 0);
        t = t.addMSecs(circleTime);
        return t.toString("hh:mm:ss.zzz");
    }
}

void StopWatch::start() {
    timer->start(100);
}

void StopWatch::clear()
{
    lastCircleTime = nullptr;
    time = new QTime(0, 0);
}

void StopWatch::stop() {
    timer->stop();
}
