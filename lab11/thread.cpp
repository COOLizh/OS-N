#include "thread.h"

Thread::Thread(int x, int speed)
{
    this->x = x;
    this->speed = speed;
    this->isLeft = false;
}

void Thread::run()
{
    while(true) {
        usleep(100000);
        !isLeft ? x += speed : x -= speed;
        if(x >= 340 || x <= 0) {isLeft = !isLeft;}
        emit sendData(x);
    }
}
