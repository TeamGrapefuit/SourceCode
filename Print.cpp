/* This file is for reference only and demonstrates how to 
print a screen.
The function should be copied into an implementation.
Do not use this file otherwise
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

QWidget * test;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test = this;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /* To use this function, add these includes:
     *
    #include <QPrinter>
    #include <QPrintDialog>
    #include <QPainter>
     *
     *
     Change '.pro' file to include these lines:

        greaterThan(QT_MAJOR_VERSION, 4){
         QT += widgets
         QT += printsupport
        }
     *
     *
     */
    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Print Document"));

    if (dialog->exec() != QDialog::Accepted)
        return;

    QPixmap pixmap = QPixmap::grabWidget(test, 0, 0, -1, -1);
    QPainter painter;
    painter.begin(&printer);
    painter.drawImage(0, 0, pixmap.toImage());
    painter.end();
}
