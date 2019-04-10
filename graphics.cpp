#include "graphics.h"
#include <QPainter>
#include <math.h>
#include <QString>

graphics::graphics(QWidget *parent):
    QWidget(parent)
{
    position=0;
    timerId=startTimer(10);
    angle=0;
}

void graphics::timerEvent(QTimerEvent *){
    position += 10;
    angle+=1;
    angle0 += 10;
    angle1 += 5;
    angle2 += 7;
    angle3 += 1;
    repaint();
}

QPointF graphics::quay(QPointF p, QPointF c, int deta){ //Quay diem p quanh diem c voi goc la deta
    QPointF pnew;
    double goc=deta*M_PI/180;
    pnew.setX(c.x()+(p.x()-c.x())*cos(goc) - (p.y()-c.y())*sin(goc));
    pnew.setY(c.y()+(p.x()-c.x())*sin(goc) + (p.y()-c.y())*cos(goc));
    return pnew;
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    animationGalaxy(painter);
}


void graphics::animationGalaxy(QPainter &painter){
    int r0=150, r1=200, r2=100,h=height()/2, w=width()/2;
    pcenter.setX(w);
    pcenter.setY(h);
    pstart.setX(pcenter.x());
    pstart.setY(pcenter.y()-300);
    pnew=quay(pstart, pcenter, angle);

    QString bg = "F:/Study/CT203 - Computer Graphic/Galaxy/Galaxy/background.png";
    QString sun = "F:/Study/CT203 - Computer Graphic/Galaxy/Galaxy/the-sun.png";
    QString mercury = "F:/Study/CT203 - Computer Graphic/Galaxy/Galaxy/mercury.png";
    QString venus = "F:/Study/CT203 - Computer Graphic/Galaxy/Galaxy/venus.png";
    QString earth = "F:/Study/CT203 - Computer Graphic/Galaxy/Galaxy/the-earth.png";
    QString moon = "F:/Study/CT203 - Computer Graphic/Galaxy/Galaxy/the-moon.png";
    QString mars = "F:/Study/CT203 - Computer Graphic/Galaxy/Galaxy/the-mars.png";

    painter.drawPixmap(0, 0, width(), height(), QPixmap(bg)); //Background
    painter.drawPixmap(width()/2-r0/2, height()/2-r0/2, r0, r0, QPixmap(sun));//The Sun
    painter.drawPixmap(pnew.x()-r1/8, pnew.y()-r1/8, r1/4, r1/4, QPixmap(earth));//The Earth

    //Mercury
    QPointF mestart(pcenter.x()-150, pcenter.y());
    QPointF menew=quay(mestart, pcenter, angle2);
    painter.drawPixmap(menew.x()-r1/16, menew.y()-r1/16, r1/8, r1/8, QPixmap(mercury));

    //Venus
    QPointF vstart(pcenter.x()-200, pcenter.y());
    QPointF vnew=quay(vstart, pcenter, angle1);
    painter.drawPixmap(vnew.x()-r1/12, vnew.y()-r1/12, r1/6, r1/6, QPixmap(venus));

    //The Moon
    QPointF qstart(pnew.x()-50, pnew.y());
    QPointF qnew=quay(qstart, pnew, angle0);
    painter.drawPixmap(qnew.x()-r2/12, qnew.y()-r2/12, r2/6, r2/6, QPixmap(moon));

    //The Mars
//    QPointF mastart(pcenter.x()-400, pcenter.y());
//    QPointF manew=quay(mastart, pcenter, angle3);
//    painter.drawPixmap(manew.x()-r1/6, manew.y()-r1/6, r1/3, r1/3, QPixmap(mars));
}


