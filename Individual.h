#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

class Individual {
public:
    Individual();
    void setParent(int parent);
    void setMarriage(int marriage[]);
    int getParent();
    int* getMarriage();
    void setVisited();
    void resetVisited();
    bool getVisited();
    void setPrevious(int previous);
    void resetPrevious();
    int getPrevious();

private:
    int parent;
    int marriage[10];
    bool visited;
    int previous;
};

#endif