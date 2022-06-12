#ifndef ABOUTDASHA_H
#define ABOUTDASHA_H

#include <QDialog>

namespace Ui {
class AboutDasha;
}

class AboutDasha : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDasha(QWidget *parent = nullptr);
    ~AboutDasha();

private:
    Ui::AboutDasha *ui;
    void paintEvent(QPaintEvent *event);
    void paintEvent2(QPaintEvent *event);
};

#endif // ABOUTDASHA_H
