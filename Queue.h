#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
public:
    Queue();
    void insert(Node* node);
    bool isEmpty();
    Node* top();
    void pop();

private:
    Node* theTop;
    Node* theBottom;
};

#endif