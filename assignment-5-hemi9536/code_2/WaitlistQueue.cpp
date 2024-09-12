#include "WaitlistQueue.hpp"

using namespace std;

WaitlistQueue::WaitlistQueue(int qSize)
{
    /* Already implemented, don't change */
    qFront = qEnd = -1;
    qCapacity = qSize;
    queue = new string[qSize];
}

WaitlistQueue::~WaitlistQueue()
{
    //TODO
    delete [] queue;
}

void WaitlistQueue::enqueue(string value)
{
    //TODO
    if (isFull()) {
        cout << "Waitlist is full. Cannot enqueue." << endl;
    } else {
        if (++qEnd >= qCapacity) {
            qEnd = 0;
        }
        if (qFront < 0) {
            qFront = qEnd;
        }
        queue[qEnd] = value;
    }
}

void WaitlistQueue::dequeue()
{
    //cout << "Size:" << size() << endl;
    //TODO
    int s = size();
    if (s == 0) {
        cout << "Waitlist is empty. Cannot dequeue." << endl;
    } else {
        //queue[qFront] = "";
        if (++qFront >= qCapacity) {
            qFront = 0;
        }
        if (--s == 0) {
            qFront = -1;
            qEnd = -1;
        }
    }
}

string WaitlistQueue::peek()
{
    //TODO
    if (qFront < 0) {
        return "<EMPTY QUEUE>";
    }
    return queue[qFront];
}

void WaitlistQueue::resize(int newSize)
{
    //TODO
    string *arr = new string[newSize];
    int index = 0;
    while((index < newSize) && (size() > 0)) {
        arr[index++] = peek();
        dequeue();
    }
    qFront = (index > 0) ? 0 : -1;
    qEnd = (index > 0) ? index : -1;
    delete [] queue;
    queue = arr;
}

int WaitlistQueue::size()
{
    //TODO
    if (qFront < 0) {
        return 0;
    }
    if (qEnd >= qFront) {
        return qEnd - qFront + 1;
    }
    return qCapacity - qFront + qEnd + 1;
}

int WaitlistQueue::capacity()
{
    //TODO
    return qCapacity;
}

bool WaitlistQueue::isEmpty()
{
    //TODO
    return (size() == 0);
}

bool WaitlistQueue::isFull()
{
    //TODO
    return size() == qCapacity;
}