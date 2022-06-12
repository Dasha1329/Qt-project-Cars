#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    const QList<QString>& getNewRow();

private slots:
    void saveAddedRow();


private:
    QList<QString> newRow;
    Ui::Dialog *ui;
};

#endif // ADDROWDIALOG_H
