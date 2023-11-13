#ifndef ORDEK_H
#define ORDEK_H

#include <QLabel>
#include <QMouseEvent>

class MainWindow;


class ordek : public QLabel
{
    Q_OBJECT
public:
    ordek(int x,MainWindow *frm,QLabel *frmLabel,QWidget *parent = nullptr);
    ordek(MainWindow *frm,QWidget *parent = nullptr);
    ordek(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void ordekOlustur(MainWindow *frm);
    MainWindow* anaFrm;


private:
    //Ui::ordek *ui;
    QTimer *zaman;
    bool hareketKontrol;

private slots:
    void hareketlendir();


signals:

};

#endif // ORDEK_H
