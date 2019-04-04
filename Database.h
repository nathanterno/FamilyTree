#ifndef DATABASE_H
#define DATABASE_H

#include "Individual.h"
#include "Family.h"
#include "Node.h"
#include "Queue.h"

class Database {
public:
    Database();
    void Insert(int number, int parent, int marriage[10]);
    void Family(int number, int husband, int wife, int children[10]);
    bool Check();
    void Relate(int personOne, int personTwo);
    void Reset();

private:
    class Individual personList[100];
    class Family familyList[100];
};

#endif