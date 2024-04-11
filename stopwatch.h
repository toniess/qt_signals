#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>

#include <QLabel>
#include <QTimer>
#include <QTime>

#include <QAbstractListModel>


class StopWatch : public QObject
{
    Q_OBJECT
public:
    explicit StopWatch(QLabel* l);

    QAbstractListModel *getCirclesModel();
    QString circle();

    void start();
    void clear();

    void stop();

private:
    QTimer *timer;
    QTime *time;
    QTime *lastCircleTime;
    QAbstractListModel *model;
};

#endif // STOPWATCH_H
