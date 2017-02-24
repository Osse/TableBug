#ifndef TABLEBUGDIALOG_H
#define TABLEBUGDIALOG_H

#include <QDialog>

namespace Ui {
class TableBugDialog;
}

class TableBugDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TableBugDialog(QWidget *parent = 0);
    ~TableBugDialog();

private:
    Ui::TableBugDialog *ui;
};

#endif // TABLEBUGDIALOG_H
