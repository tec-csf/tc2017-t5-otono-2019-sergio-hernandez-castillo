/*
 * Sergio Hernandez Castillo - A01025210
 * Tarea 5: Geometria Computacional
*/

#include "transformaciones.h"

Transformaciones::Transformaciones()
{

}//Close Transformaciones

void Transformaciones::dibujar(bool & dibuja, QVector<QTransform> & vecTrans, double & xCentro, double & yCentro)
{
    dibuja=!dibuja;
    vecTrans.clear();
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);
}//Close dibujar

void Transformaciones::trasladar(QString & xStr, QString & yStr, QVector<QTransform> & vecTrans)
{
    if(!xStr.isEmpty() && !yStr.isEmpty())
    {
        double x = xStr.toDouble();
        double y = yStr.toDouble();
        QTransform translate;
        translate.translate(x, y);
        vecTrans.push_back(translate);
    }//Close if
}//Close trasladar

void Transformaciones::rotar(QString & gradosStr, QVector<QTransform> & vecTrans)
{
    if(!gradosStr.isEmpty())
    {
        double grados = gradosStr.toDouble();
        QTransform rotate;
        rotate.rotate(grados);
        vecTrans.push_back(rotate);
    }//Close if
}//Close rotar

void Transformaciones::zoomOut(QVector<QTransform> & vecTrans)
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    vecTrans.push_back(zoomOut);
}//Close zoomOut

void Transformaciones::zoomIn(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    vecTrans.push_back(zoomIn);
}//Close zoomIn

void Transformaciones::reflexHorizontal(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    vecTrans.push_back(zoomIn);
}//Close refelxHorizontal

void Transformaciones::reflexVertical(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    vecTrans.push_back(zoomIn);
}//Close refelxVertical
