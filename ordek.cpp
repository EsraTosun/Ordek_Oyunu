#include "ordek.h"

#include <QDebug>  //Konsola veri yazdırmak için
#include <QRandomGenerator>

#include <QTimer>
#include <QEventLoop>

int vurulmaSayisi=0;
int kacanOrdek=0;

#include "mainwindow.h";

ordek::ordek(int x,MainWindow *frm,QLabel *frmLabel,QWidget *parent) : QLabel(parent)
{
    anaFrm = frm;
    setGeometry(x, 10, 50, 50);
    //setFrameShape(QFrame::Box);   //Labelin çizgileri gözüksün diye
    setMouseTracking(true);   //Etiketi tıklanabilir yapın
    QImage resim(":/res/ordek.png");
    setPixmap(QPixmap::fromImage(resim));
    setScaledContents(true); // Resmi QLabel boyutuna sığdır
    hareketKontrol = true;
    zaman = new QTimer(this);
    connect(zaman, SIGNAL(timeout()), this, SLOT(hareketlendir()));
    zaman->start(100);
    show();
    //connect(this, SIGNAL(labelClicked()), this, SLOT(onLabelClicked()));
}

ordek::ordek(MainWindow *frm,QWidget *parent) : QLabel(parent)
{
    anaFrm = frm;
}

ordek::ordek(QWidget *parent) : QLabel(parent)
{
}

void ordek::hareketlendir()
{
    setGeometry(x(), y() + 10, width(), height());
    if(y()> anaFrm->anaLabel->height())
    {
        kacanOrdek++;
        anaFrm->kacanLabel->setText(QString::number(kacanOrdek));
        delete this;
    }
}

void ordek::ordekOlustur(MainWindow *frm)
{

    while(true)
    {
        anaFrm=frm;
        qDebug() << anaFrm->anaLabel->width()*4.8;
        int sayi=QRandomGenerator::global()->bounded(anaFrm->anaLabel->width()-40);
        ordek *ordekk = new ordek(sayi,frm,frm->anaLabel,frm->anaLabel);

        QEventLoop loop;
        QTimer timer;
        timer.setSingleShot(true);

        QObject::connect(&timer, &QTimer::timeout, [&]() {
            qDebug() << "Duraklama süresi bitti, işlemlere devam ediliyor...";
            // İkinci işlemler
            loop.quit(); // Event loop'u sonlandır
        });
        // İlk işlemlerden sonra duraklama süresi (örneğin, 2 saniye)
        int duraklamaSuresi = 500;
        timer.start(duraklamaSuresi);
        loop.exec(); // Event loop'u başlat
        qDebug() <<"aaaa";

    }
}


void ordek :: mousePressEvent(QMouseEvent *event)
{
    qDebug()<< "bbbbbbb";
    QImage resim(":/res/vurulma.png");
    setPixmap(QPixmap::fromImage(resim));
    vurulmaSayisi++;
    anaFrm->vurulmaLabel->setText(QString::number(vurulmaSayisi));
    qDebug()<< "bbbbbbb";


    qDebug() << "Tıklandı!!!!";

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);

    QObject::connect(&timer, &QTimer::timeout, [&]() {
        qDebug() << "Duraklama süresi bitti, işlemlere devam ediliyor...";
        // İkinci işlemler
        loop.quit(); // Event loop'u sonlandır
    });
    // İlk işlemlerden sonra duraklama süresi (örneğin, 2 saniye)
    int duraklamaSuresi = 500;
    timer.start(duraklamaSuresi);
    loop.exec(); // Event loop'u başlat
    delete this;
}
