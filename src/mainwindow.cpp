#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (createConnection()) {
        qDebug() << "Database connected successfully";
    } else {
        qDebug() << "Database connection error";
    }

    model = new QSqlTableModel(this);
    model->setTable("humans");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("First name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Age"));

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

    connect(ui->pushButton_add, SIGNAL(released()), this, SLOT(submit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::submit() {
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: no description"));
//                             tr("The database reported an error: %1")
//                             .arg(model->lastError().text()));
    }
}

bool MainWindow::createConnection() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("humankind");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("");
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    return true;
}
