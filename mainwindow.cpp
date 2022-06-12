#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include "dialog.h"
#include "aboutdasha.h"
#include <QRegularExpression>
#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    exampleModel = new ExampleModel(this);
    ui->tableView->setModel(exampleModel);
    QObject::connect(ui->actionStudent, SIGNAL(triggered()), this, SLOT(aboutSlot()));
    QObject::connect(ui->PBLoadFromFile, SIGNAL(clicked()), this, SLOT(loadDataSlot()));
    QObject::connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveFile()));
    QObject::connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(changeCurrentRowSlot(QModelIndex)));
    QObject::connect(ui->AddRowButton, SIGNAL(clicked()), this, SLOT(addRowSlot()));
    QObject::connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteRowSlot()));


    QColor biruzovii = QColor::fromRgb(204,255,229);
    QColor koralovii = QColor::fromRgb(255,204,204);
    QColor lemon = QColor::fromRgb(255,255,204);
    if(biruzovii.isValid()) {
       QString qss = QString("background-color: %1").arg(biruzovii.name());
       ui->saveButton->setStyleSheet(qss);
    }
    if(biruzovii.isValid()) {
       QString qss = QString("background-color: %1").arg(biruzovii.name());
       ui->PBLoadFromFile->setStyleSheet(qss);
    }
    if(koralovii.isValid()) {
       QString qss = QString("background-color: %1").arg(koralovii.name());
       ui->deleteButton->setStyleSheet(qss);
    }
    if(lemon.isValid()) {
       QString qss = QString("background-color: %1").arg(lemon.name());
       ui->AddRowButton->setStyleSheet(qss);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDataSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/", "Data (*.csv)");
    delete exampleModel;
    exampleModel = new ExampleModel(this);
    exampleModel->LoadDataFromFile(fileName);
    ui->tableView->setModel(exampleModel);
}

void MainWindow::aboutSlot()
{
   AboutDasha d;
   d.exec();
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open File", "../", "Data (*.csv)");
    exampleModel->saveDataTableToFile(fileName);
}

void MainWindow::changeCurrentRowSlot(const QModelIndex &index)
{

    int row = index.row();

    QModelIndex carIndex = exampleModel->index(row, 0);
    QVariant carData = exampleModel->data(carIndex);
    ui->carLabel->setText(carData.toString());

    QModelIndex styleIndex = exampleModel->index(row, 1);
    QVariant styleData = exampleModel->data(styleIndex);
    ui->styleLabel->setText(styleData.toString());

    QModelIndex rangeIndex = exampleModel->index(row, 2);
    QVariant rangeData = exampleModel->data(rangeIndex);
    ui->rangeLabel->setText(rangeData.toString());

    QModelIndex transIndex = exampleModel->index(row, 3);
    QVariant transData = exampleModel->data(transIndex);
    ui->transmissionLabel->setText(transData.toString());

    QModelIndex vehicleIndex = exampleModel->index(row, 4);
    QVariant vehicleData = exampleModel->data(vehicleIndex);
    ui->vehicleLabel->setText(vehicleData.toString());

    QModelIndex priceIndex = exampleModel->index(row, 5);
    QVariant priceData = exampleModel->data(priceIndex);
    ui->priceLabel->setText(priceData.toString());

    QModelIndex ratingIndex = exampleModel->index(row, 6);
    QVariant ratingData = exampleModel->data(ratingIndex);
    ui->ratingLabel->setText(ratingData.toString());
}

void MainWindow::addRowSlot()
{
    Dialog d(this);
    if (d.exec() == QDialog::Accepted)
    {
        QList<QString> aaa = d.getNewRow();
        exampleModel->appendRow(aaa);
    }
}

void MainWindow::deleteRowSlot()
{
        int rowIndex = ui->tableView->currentIndex().row();
        exampleModel->removingRow(rowIndex);
}










