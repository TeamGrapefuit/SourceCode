#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphdialog.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    GraphDialog *newDialog;
};

#endif // MAINWINDOW_H
