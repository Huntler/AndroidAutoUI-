#ifndef CLIENTWORKER_H
#define CLIENTWORKER_H

#include <QObject>
#include <QThread>
#include <string>

class ClientWorker : public QObject
{
    Q_OBJECT
    QThread worker;


public:
   bool bridge_running = false;

public slots:
    void awaitBridge(QString param);

signals:
    void gotResult(QString result);
};

#endif // CLIENTWORKER_H
