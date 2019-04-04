#ifndef FAMILY_H
#define FAMILY_H

class Family {
public:
    Family();
    void setHusband(int husband);
    void setWife(int wife);
    void setChildren(int children[]);
    int getHusband();
    int getWife();
    int* getChildren();
    void setVisited();
    void resetVisited();
    bool getVisited();
    void setPrevious(int previous);
    void resetPrevious();
    int getPrevious();

private:
    int husband;
    int wife;
    int children[10];
    bool visited;
    int previous;
};

#endif