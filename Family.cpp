#include "Family.h"

Family::Family() {
    this->husband = -1;
    this->wife = -1;
    for (int i = 0; i < 10; i++) {
        this->children[i] = -1;
    }
    this->visited = false;
    this->previous = -1;
}

void Family::setHusband(int husband) {
    this->husband = husband;
}

void Family::setWife(int wife) {
    this->wife = wife;
}

void Family::setChildren(int children[]) {
    for (int i = 0; i < 10; i++) {
        this->children[i] = children[i];
    }
}

int Family::getHusband() {
    return this->husband;
}

int Family::getWife() {
    return this->wife;
}

int* Family::getChildren() {
    return this->children;
}

void Family::setVisited() {
    this->visited = true;
}

void Family::resetVisited() {
    this->visited = false;
}

bool Family::getVisited() {
    return this->visited;
}

void Family::setPrevious(int previous) {
    this->previous = previous;
}

void Family::resetPrevious() {
    this->previous = -1;
}

int Family::getPrevious() {
    return this->previous;
}