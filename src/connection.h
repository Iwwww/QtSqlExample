#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QMessageBox>

class connection : public QObject
{
    Q_OBJECT
public:
    static bool createConnection();
};

#endif // CONNECTION_H
