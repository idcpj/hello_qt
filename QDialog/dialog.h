#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include<QMouseEvent>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QPixmap pix;
    QPoint firstPoint;
    QPoint endPoint;

    QPixmap tmpPix;
    bool isDrawing;


    qreal scale;
    QPushButton *button;

private slots:

    void zoomIn();

protected:

    void  paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *)override;


};
#endif // DIALOG_H
