/*
 * Sergio Hernandez Castillo - A01025210
 * Tarea 5: Geometria Computacional
*/

#include "prismatri.h"
#include "ui_prismatri.h"
#include <math.h>

PrismaTri::PrismaTri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaTri)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}//Close widget

PrismaTri::~PrismaTri()
{
    delete ui;
}//Close PrismaTri

void dibujarPrismaTri(QPainter & painter)
{
    int medida = 25;
    int medida2 = medida*2;
    int medida3 = 70;

    int x1 = 0;
    int y1 = -medida2;
    int x2 = -medida;
    int y2 = -medida3;
    int x3 = medida;
    int y3 = -medida3;
    int _x1 = 0;
    int _y1 = -medida2+medida2;
    int _x2 = -medida;
    int _y2 = -medida3+medida2;
    int _x3 = medida;
    int _y3 = -medida3+medida2;

    painter.drawLine(x1,y1,x2,y2);
    painter.drawLine(x1,y1,x3,y3);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(_x1,_y1,_x2,_y2);
    painter.drawLine(_x1,_y1,_x3,_y3);
    painter.drawLine(_x2,_y2,_x3,_y3);
    painter.drawLine(x1,y1,_x1,_y1);
    painter.drawLine(x2,y2,_x2,_y2);
    painter.drawLine(_x3,_y3,x3,y3);
}//Close dibujarPrismaTri

void PrismaTri::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if(dibuja)
    {
        for(int i=0; i<vecTrans.size(); ++i)
        {
            painter.setTransform(vecTrans[i],true);
            dibujarPrismaTri(painter);
        }//Close for
    }//Close if
}//Close paintEvent

void PrismaTri::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();
}//Close button

void PrismaTri::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();
}//Close button

void PrismaTri::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();
}//Close button

void PrismaTri::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();
}//Close button

void PrismaTri::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();
}//Close button

void PrismaTri::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();
}//Close button

void PrismaTri::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();
}//Close button
