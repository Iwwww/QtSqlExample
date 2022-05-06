#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool createConnection();

private slots:
    void submit();

private:
    Ui::MainWindow *ui;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
