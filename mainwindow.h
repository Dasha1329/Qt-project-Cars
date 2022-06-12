#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "examplemodel.h"
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ExampleModel *exampleModel;

private slots:
    void loadDataSlot();
    void addRowSlot();
    void aboutSlot();
    void saveFile();
    void deleteRowSlot();
    void changeCurrentRowSlot(const QModelIndex &index);

};

#endif // MAINWINDOW_H
