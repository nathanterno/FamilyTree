#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    void setData(int data);
    int getData();
    void setNext(Node* next);
    Node* getNext();

private:
    int data;
    Node* next;
};

#endif