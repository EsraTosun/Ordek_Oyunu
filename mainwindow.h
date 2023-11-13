#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QLabel>

#include "ordek.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event) override;
    void ordekOlustur();
    void vurulmaSayisi();
    QLabel *anaLabel;
    QLabel *vurulmaLabel;
    QLabel *kacanLabel;

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    ordek *ordeknesne;

};
#endif // MAINWINDOW_H
