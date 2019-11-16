/*
 * Sergio Hernandez Castillo - A01025210
 * Tarea 5: Geometria Computacional
*/

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "poligonos.h"
#include "arcos.h"
#include "cubo.h"
#include "prismarec.h"
#include "prismatri.h"
#include "cono.h"

namespace Ui
{
class Dialog;
}//Close Ui

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Dialog *ui;
};//Close Dialog

#endif // DIALOG_H
