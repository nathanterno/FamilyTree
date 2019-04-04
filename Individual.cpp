#include "Individual.h"

Individual::Individual() {
    this->parent = -1;
    for (int i = 0; i < 10; i++) {
        this->marriage[i] = -1;
    }
    this->visited = false;
    this->previous = -1;
}

void Individual::setParent(int parent) {
    this->parent = parent;
}

void Individual::setMarriage(int marriage[]) {
    for (int i = 0; i < 10; i++) {
        this->marriage[i] = marriage[i];
    }
}

int Individual::getParent() {
    return this->parent;
}

int* Individual::getMarriage() {
    return this->marriage;
}

void Individual::setVisited() {
    this->visited = true;
}

void Individual::resetVisited() {
    this->visited = false;
}

bool Individual::getVisited() {
    return this->visited;
}

void Individual::setPrevious(int previous) {
    this->previous = previous;
}

void Individual::resetPrevious() {
    this->previous = -1;
}

int Individual::getPrevious() {
    return this->previous;
}