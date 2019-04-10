#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QPointF>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);

    void timerEvent(QTimerEvent *);
    double position;
    double timerId;

    void paintEvent(QPaintEvent *);
    double h=height();
    double w=width();

    QPointF pstart, pcenter, pnew;
    int angle, angle0, angle1, angle2, angle3;
    QPointF quay(QPointF p, QPointF c, int deta);
    void animationGalaxy(QPainter& painter);
    void animationTest(QPainter& painter);

    int mode=0;
};

#endif // GRAPHICS_H
