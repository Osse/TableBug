#include "tablebugdialog.h"
#include "ui_tablebugdialog.h"

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>

class TableBugModel : public QAbstractTableModel
{
public:
    TableBugModel(QObject* parent) : QAbstractTableModel(parent)
    {
    }

    QVariant data(const QModelIndex &index, int role) const
    {
        if (index.column() > 1 || index.row() > 1)
            return QVariant();

        return QVariant::fromValue(internalData[index.row()][index.column()]);
    }

    int rowCount(const QModelIndex &parent) const
    {
        if (parent.isValid())
            return 0;
        else
            return 2;
    }

    int columnCount(const QModelIndex& /*parent*/) const
    {
        return 2;
    }

    Qt::ItemFlags flags(const QModelIndex& /*index*/) const
    {
        return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemNeverHasChildren;
    }

private:
    int internalData[2][2] = {{1, 2}, {3, 4}};

};

TableBugDialog::TableBugDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableBugDialog)
{
    ui->setupUi(this);

    auto model = new TableBugModel(this);
    ui->tableView->setModel(model);
}

TableBugDialog::~TableBugDialog()
{
    delete ui;
}
