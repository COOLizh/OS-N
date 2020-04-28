#include "thread.h"

Thread::Thread(QString txt)
{
    this->text = txt;
}

void Thread::run()
{
    while(true) {
        emit sendData(text);
        sleep(1);
    }
}
