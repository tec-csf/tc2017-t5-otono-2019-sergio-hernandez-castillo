/*
 * Sergio Hernandez Castillo - A01025210
 * Tarea 5: Geometria Computacional
*/

#include "poligonos.h"
#include "ui_poligonos.h"
#include <QMessageBox>
#include <math.h>

Poligonos::Poligonos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poligonos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);

}//Close widget

Poligonos::~Poligonos()
{
    delete ui;
}//Close Poligonos

void dibujarPoligono(int lados, QPainter & painter)
{
    double radio = 100;
    double angulo = (double)360.0/(double)lados;

    int xi,yi,xf,yf;
    double val = M_PI / 180;
    angulo *= val;
    int a = 0;

    for(a = 1; a <= lados; a++)
    {
        xi = (radio * cos(angulo*a));
        yi = (radio * sin(angulo*a));

        xf = (radio * cos(angulo*(a+1)));
        yf = (radio * sin(angulo*(a+1)));

        painter.drawLine(xi, yi, xf, yf);
    }//Close for
}//Close dibujarPoligono

void Poligonos::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja)
    {
        QString ladosStr = ui->boxXfin->toPlainText();

        if (!ladosStr.isEmpty())
        {
            int lados = ladosStr.toInt();

            for(int i=0; i<vecTrans.size(); ++i)
            {
                painter.setTransform(vecTrans[i],true);
                dibujarPoligono(lados, painter);
            }//Close for

        }//Close if
    }//Close if
}//Close painEvent

void Poligonos::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();
}//Close button

void Poligonos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();
}//Close button

void Poligonos::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();
}//Close button

void Poligonos::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();
}//Close button

void Poligonos::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();
}//Close button

void Poligonos::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();
}//Close button

void Poligonos::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();
}//Close button
