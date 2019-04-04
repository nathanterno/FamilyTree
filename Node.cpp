#include "Node.h"

using namespace std;

Node::Node() {
    this->data = -1;
    this->next = nullptr;
}

void Node::setData(int data) {
    this->data = data;
}

int Node::getData() {
    return this->data;
}

void Node::setNext(Node* next) {
    this->next = next;
}

Node* Node::getNext() {
    return this->next;
}