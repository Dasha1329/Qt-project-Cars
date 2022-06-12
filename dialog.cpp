#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QObject::connect(ui->OkButton, SIGNAL(clicked()), this, SLOT(saveAddedRow()));
    QObject::connect(ui->CancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void Dialog::saveAddedRow()
{
    newRow.push_back(ui->CarlineEdit->text());
    newRow.push_back(ui->StylelineEdit->text());
    newRow.push_back(ui->RangelineEdit->text());
    newRow.push_back(ui->TransmissionlineEdit->text());
    newRow.push_back(ui->VehicleTypelineEdit->text());
    newRow.push_back(ui->PriceRangelineEdit->text());
    newRow.push_back(ui->RatinglineEdit->text());
    accept();
}
const QList<QString>& Dialog::getNewRow()
{
    return newRow;
}

Dialog::~Dialog()
{
    delete ui;
}
