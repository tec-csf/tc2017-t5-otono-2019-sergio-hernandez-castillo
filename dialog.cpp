/*
 * Sergio Hernandez Castillo - A01025210
 * Tarea 5: Geometria Computacional
*/

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}//Close widget

Dialog::~Dialog()
{
    delete ui;
}//Close Dialog


void Dialog::on_pushButton_clicked()
{
    Poligonos poligonos;
    poligonos.setModal(true);
    poligonos.exec();
}//Close button

void Dialog::on_pushButton_2_clicked()
{
    Arcos arcos;
    arcos.setModal(true);
    arcos.exec();
}//Close button

void Dialog::on_pushButton_3_clicked()
{
    Cubo cubo;
    cubo.setModal(true);
    cubo.exec();
}//Close button

void Dialog::on_pushButton_4_clicked()
{
    PrismaRec prismaRectangular;
    prismaRectangular.setModal(true);
    prismaRectangular.exec();
}//Close button

void Dialog::on_pushButton_5_clicked()
{
    PrismaTri prismaTriangular;
    prismaTriangular.setModal(true);
    prismaTriangular.exec();
}//Close button

void Dialog::on_pushButton_6_clicked()
{
    Cono cono;
    cono.setModal(true);
    cono.exec();
}//Close button
