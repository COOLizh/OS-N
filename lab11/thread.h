#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
Q_OBJECT
public:
    Thread (int, int);
    void run();

signals:
    void sendData(int x);

private:
    int x, speed;
    bool isLeft;
};

#endif // THREAD_H
