#include "Queue.h"

template<class T> Queue<T>::Queue() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
void Queue<T>::push(T x) {
    Node *t = new Node();
    t->data = x;
    t->next = tail;
    tail = t;
    size += 1;
}

template<class T>
bool Queue<T>::isEmpty() {
    return head == tail;
}

template<class T>
T Queue<T>::pop() {
    Node *u;
    if (isEmpty())
        throw EmptyQueueException();
    else {
        T x = head->data;
        u = head;
        head = head->next;
        free(u);
        size -= 1;
        return x;
    }
}

template<class T>
int Queue<T>::sizeOf() {
    return size;
}