#include "connection.h"

static bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("humankind");
    db.setHostName("localhost");
    db.setDatabaseName("hospital");
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
