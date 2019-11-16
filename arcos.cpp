/*
 * Sergio Hernandez Castillo - A01025210
 * Tarea 5: Geometria Computacional
*/

#include "arcos.h"
#include "ui_arcos.h"
#include <QMessageBox>
#include <math.h>

#define PI 3.14159265

Arcos::Arcos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arcos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}//Close Arcos

Arcos::~Arcos()
{
    delete ui;
}//Close Arcos

void puntosCirculo(int & x, int & y, int & angulo, QPainter & painter)
{
    int oct = (angulo - (angulo % 45)) / 45;
    double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
    double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

    if (oct > 0 || (oct == 0 && y > limit1))
    {
        painter.drawPoint(x,-y);
    }//Close if

    if (oct > 1 || (oct == 1 && y <= limit2))
    {
        painter.drawPoint(y,-x);
    }//Close if

    if (oct > 2 || (oct == 2 && y > limit1))
    {
        painter.drawPoint(y,x);
    }//Close if

    if (oct > 3 || (oct == 3 && y <= limit2))
    {
        painter.drawPoint(x,y);
    }//Close if

    if (oct > 4 || (oct == 4 && y > limit1))
    {
        painter.drawPoint(-x,y);
    }//Close if

    if (oct > 5 || (oct == 5 && y <= limit2))
    {
        painter.drawPoint(-y,x);
    }//Close if

    if (oct > 6 || (oct == 6 && y > limit1))
    {
        painter.drawPoint(-y,-x);
    }//Close if

    if (oct > 7 || (oct == 7 && y <= limit2))
    {
        painter.drawPoint(-x,-y);
    }//Close if
}//Close puntosCirculo

void dibujarArco(int angulo, int radio, QPainter & painter)
{
    int x = 0;
    int y = radio;
    double p = 5.0/4.0-y;

    puntosCirculo(x, y, angulo, painter);

    while(y > x)
    {
        if(p < 0)
        {
            p += 2.0 * x + 3.0;
        }//Close if

        else
        {
            p += 2.0 * (x - y) + 5.0;
            y--;
        }//Close else

        x++;

        puntosCirculo(x, y, angulo, painter);
    }//Close while
}//Close dibujarArco

void Arcos::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja)
    {
        QString radioStr = ui->boxRadio->toPlainText();
        QString anguloStr = ui->boxAngulo->toPlainText();

        int angulo = anguloStr.toInt();
        int radio = radioStr.toInt();

        if (!radioStr.isEmpty() && !anguloStr.isEmpty())
        {
            for(int i=0; i<vecTrans.size(); ++i)
            {
                painter.setTransform(vecTrans[i],true);
                dibujarArco(angulo, radio,  painter);
            }//Close for
        }//Close if
    }//Close if
}//Close paintEvent

void Arcos::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}//cierre del boton dibujar

void Arcos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();
}//Close button

void Arcos::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();
}//Close button

void Arcos::on_pushButton_4_clicked()
{
    trans.zoomIn(vecTrans);

    update();
}//Close button

void Arcos::on_pushButton_5_clicked()
{
    trans.zoomOut(vecTrans);

    update();
}//Close button

void Arcos::on_pushButton_6_clicked()
{
    trans.reflexVertical(vecTrans);

    update();
}//Close button

void Arcos::on_pushButton_7_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();
}//Close button
