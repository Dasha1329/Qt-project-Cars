#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>


class ExampleModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ExampleModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;  
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void LoadDataFromFile(QString path);
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;   
    void appendRow(QList<QString> &row);
    void saveDataTableToFile(QString path);
    void removingRow(int index);


private:
QList<QList<QString>> dataTable;
QList<QString> headerList;
};

#endif // EXAMPLEMODEL_H
