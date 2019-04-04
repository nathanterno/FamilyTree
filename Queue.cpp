#include "Queue.h"

Queue::Queue() {
    this->theTop = nullptr;
    this->theBottom = nullptr;
}

void Queue::insert(Node* node) {
    if (this->theTop == nullptr) {
        this->theTop = node;
        this->theBottom = node;
    }
    else {
        this->theBottom->setNext(node);
        this->theBottom = node;
    }
}

bool Queue::isEmpty() {
    if (this->theTop == nullptr) {
        return true;
    }
    return false;
 }

Node* Queue::top() {
    return this->theTop;
}

void Queue::pop() {
    this->theTop = this->theTop->getNext();
}