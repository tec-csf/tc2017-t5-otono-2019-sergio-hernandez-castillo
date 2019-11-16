/*
 * Sergio Hernandez Castillo - A01025210
 * Tarea 5: Geometria Computacional
*/

#include "cubo.h"
#include "ui_cubo.h"
#include <math.h>

Cubo::Cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cubo)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}//Close widget

Cubo::~Cubo()
{
    delete ui;
}//Close Cubo

void dibujaCubo(QPainter &painter)
{
    int medida = 25;

    int x1 = -medida;
    int y1 = medida;
    int x2 = medida;
    int y2 = medida;
    int x3 = -medida;
    int y3 = -medida;
    int x4 = medida;
    int y4 = -medida;

    int distancia = (x2-x1)/2;

    int _x1 = x1 + distancia;
    int _y1 = y1 - distancia;
    int _x2 = x2 + distancia;
    int _y2 = y2 - distancia;
    int _x3 = x3 + distancia;
    int _y3 = y3 - distancia;
    int _x4 = x4 + distancia;
    int _y4 = y4 - distancia;

    painter.drawLine(x1, y1, x2, y2);
    painter.drawLine(x1, y1, x3, y3);
    painter.drawLine(x2, y2, x4, y4);
    painter.drawLine(x3, y3, x4, y4);
    painter.drawLine(_x1, _y1, _x2, _y2);
    painter.drawLine(_x1, _y1, _x3, _y3);
    painter.drawLine(_x2, _y2, _x4, _y4);
    painter.drawLine(_x3, _y3, _x4, _y4);
    painter.drawLine(x1, y1, _x1, _y1);
    painter.drawLine(x2, y2, _x2, _y2);
    painter.drawLine(x3, y3, _x3, _y3);
    painter.drawLine(x4, y4, _x4, _y4);
}//Close dibujaCubo

void Cubo::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja)
    {
        for(int i=0; i<vecTrans.size(); ++i)
        {
            painter.setTransform(vecTrans[i],true);
            dibujaCubo(painter);
        }//Close for
    }//Close if
}//Close paintEvent

void Cubo::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();
}//Close button

void Cubo::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();
}//Close button

void Cubo::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();
}//Close button

void Cubo::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();
}//Close button

void Cubo::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();
}//Close button

void Cubo::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();
}//Close button

void Cubo::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();
}//Close button
