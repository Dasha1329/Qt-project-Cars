#include "examplemodel.h"
#include <QFile>
ExampleModel::ExampleModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int ExampleModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return dataTable.size();
}

int ExampleModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    if(dataTable.empty())
        return 0;
    return dataTable.at(0).size();
}

QVariant ExampleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        return headerList[section];
    }
    return QVariant();
}

QVariant ExampleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();

        return dataTable.at(row).at(column);
    }
    return QVariant();
}

void ExampleModel::LoadDataFromFile(QString path)
{
    //QString path = "/Users/dl3/Desktop/titanic.csv";
    QFile inputFile(path);
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    QString firstline = inputStream.readLine();
    for (QString item : firstline.split(","))
    {
        headerList.append(item);
    }

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();

        QList<QString> dataRow;
        for (QString& item : line.split(",")) {
            dataRow.append(item);
        }
        dataTable.append(dataRow);
    }
    inputFile.close();
}

bool ExampleModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        int row = index.row();
        int col = index.column();
        dataTable[row][col] = value.toString();
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags ExampleModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void ExampleModel::appendRow(QList<QString> &row)
{
    size_t newRowNumber = rowCount();
    beginInsertRows(QModelIndex(), newRowNumber, newRowNumber);
    dataTable.append(row);
    endInsertRows();
}

void ExampleModel::saveDataTableToFile(QString path)
{
    QFile outputFile(path);
    outputFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream outputStream(&outputFile);

    bool first = true;
    for (QString& item : headerList)
    {
        if (first)
        {
            outputStream << item;
            first = false;
        }
        else
        {
            outputStream << ",";
            outputStream << item;
        }
    }
    outputStream << "\n";

    for (QList<QString>& row: dataTable)
    {
        bool first = true;
        for (QString& item : row)
        {
            if (first)
            {
                outputStream << item;
                first = false;
            }
            else
            {
                outputStream << ",";
                outputStream << item;
            }
        }
        outputStream << "\n";
    }
    outputFile.close();
}

void ExampleModel::removingRow(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    dataTable.removeAt(index);
    endRemoveRows();
}



