#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
Q_OBJECT
public:
    Thread (QString);
    void run();

signals:
    void sendData(QString str);

private:
    QString text;
};

#endif // THREAD_H
