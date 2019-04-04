#include <iostream>
#include "Database.h"

using namespace std;

Database::Database() {
    for (int i = 0; i < 100; i++) {
        class Individual nextInd;
        this->personList[i] = nextInd;
    }
    for (int j = 0; j < 100; j++) {
        class Family nextFam;
        this->familyList[j] = nextFam;
    }
}

//Adds a person to the graph
void Database::Insert(int number, int parent, int marriage[10]) {
    personList[number].setParent(parent);
    personList[number].setMarriage(marriage);
}

//Adds a family to the graph
void Database::Family(int number, int husband, int wife, int children[10]) {
    familyList[number].setHusband(husband);
    familyList[number].setWife(wife);
    familyList[number].setChildren(children);
}


//Checks the graph for consistency
bool Database::Check() {
    bool check = true;
    //check each person in personList to see if the appropriate family vertices
    //point back at them
    for (int i = 1; i < 100; i++) {
        int* marriages = personList[i].getMarriage();
        for (int n = 0; n < 10; n++) {
            int marriage = marriages[n];
            if (marriage > 0 && marriage < 100) {
                int husband = familyList[marriage].getHusband();
                int wife = familyList[marriage].getWife();
                if (husband != i && wife != i) {
                    cout << "Individual " << i << " points to marriage ";
                    cout << marriage << " family but there is no backpointer";
                    cout << endl;
                    check = false;
                }
            }
        }
        int parent = personList[i].getParent();
        if (parent > 0 && parent < 100) {
            int* children = familyList[parent].getChildren();
            bool checkChildren = false;
            for (int j = 0; j < 10; j++) {
                if (children[j] == i) {
                    checkChildren = true;
                    break;
                }
            }
            if (checkChildren == false) {
                cout << "Individual " << i << " points to parent family ";
                cout << parent << " but there is no backpointer" << endl;
                check = false;
            }
        }
    }

    //check each family in familyList to see if the appropriate person vertices
    //point back at them
    for (int k = 1; k < 100; k++) {
        int husband = familyList[k].getHusband();
        if (husband > 0 && husband < 100) {
            int* marriages = personList[husband].getMarriage();
            bool marriageBackPoint = false;
            for (int p = 0; p < 10; p++) {
                if (marriages[p] == k) {
                    marriageBackPoint = true;
                }
            }
            if (marriageBackPoint == false) {
                cout << "Family " << k << " points to husband individual ";
                cout << husband << " but there is no backpointer" << endl;
                check = false;
            }
        }
        int wife = familyList[k].getWife();
        if (wife > 0 && wife < 100) {
            int* marriages = personList[wife].getMarriage();
            bool marriageBackPoint = false;
            for (int p = 0; p < 10; p++) {
                if (marriages[p] == k) {
                    marriageBackPoint = true;
                }
            }
            if (marriageBackPoint == false) {
                cout << "Family " << k << " points to wife individual ";
                cout << wife << " but there is no backpointer" << endl;
                check = false;
            }
        }
        int* children = familyList[k].getChildren();
        for (int m = 0; m < 10; m++) {
            int child = children[m];
            if (child > 0 && child < 100) {
                if (personList[child].getParent() != k) {
                cout << "Family " << k << " points to child individual ";
                cout << child << " but there is no backpointer" << endl;
                check = false;
                break;
                }
            }
        }
    }

    if (check == true) {
        cout << "The data are consistent" << endl;
        return true;
    }
    return false;
}

//Relates one person to another by traversing the graph via the shortest path
void Database::Relate(int personOne, int personTwo) {
    Node* firstNode = new Node();
    firstNode->setData(personTwo);

    Queue queue;
    queue.insert(firstNode);
    
    int currPerson;
    int currFamily;
    int parent;
    int* marriages;
    int husband;
    int wife;
    int* children;

    //Work outwards from the ending point to the starting point in a
    //breath-first-search-esque way
    while (queue.isEmpty() == false) {
        currPerson = queue.top()->getData();
        personList[currPerson].setVisited();
        queue.pop();

        if (currPerson == personOne) {
            break;
        }

        parent = personList[currPerson].getParent();
        if (parent > 0 && parent < 100 &&
            familyList[parent].getVisited() == false) {
            familyList[parent].setPrevious(currPerson);
            familyList[parent].setVisited();
            husband = familyList[parent].getHusband();
            if (husband > 0 && husband < 100 &&
                personList[husband].getVisited() == false) {
                personList[husband].setPrevious(parent);
                Node* husbandNode = new Node();
                husbandNode->setData(husband);
                queue.insert(husbandNode);
            }
            wife = familyList[parent].getWife();
            if (wife > 0 && wife < 100 &&
                personList[wife].getVisited() == false) {
                personList[wife].setPrevious(parent);
                Node* wifeNode = new Node();
                wifeNode->setData(wife);
                queue.insert(wifeNode);
            }
            children = familyList[parent].getChildren();
            for (int i = 0; i < 10; i++) {
                if (children[i] > 0 && children[i] < 100 &&
                    children[i] != currPerson) {
                    personList[children[i] ].setPrevious(parent);
                    Node* childNode = new Node();
                    childNode->setData(children[i]);
                    queue.insert(childNode);
                }
            }
        }

        marriages = personList[currPerson].getMarriage();
        for (int j = 0; j < 10; j++) {
            if (marriages[j] > 0 && marriages[j] < 100 &&
                familyList[marriages[j] ].getVisited() == false) {
                familyList[marriages[j] ].setPrevious(currPerson);
                familyList[marriages[j] ].setVisited();

                husband = familyList[marriages[j] ].getHusband();
                if (husband > 0 && husband < 100 &&
                    personList[husband].getVisited() == false) {
                    personList[husband].setPrevious(marriages[j]);
                    Node* husbandNode = new Node();
                    husbandNode->setData(husband);
                    queue.insert(husbandNode);
                }
                wife = familyList[marriages[j] ].getWife();
                if (wife > 0 && wife < 100 &&
                    personList[wife].getVisited() == false) {
                    personList[wife].setPrevious(marriages[j]);
                    Node* wifeNode = new Node();
                    wifeNode->setData(wife);
                    queue.insert(wifeNode);
                }
                children = familyList[marriages[j] ].getChildren();
                for (int i = 0; i < 10; i++) {
                    if (children[i] > 0 && children[i] < 100 &&
                        children[i] != currPerson) {
                        personList[children[i] ].setPrevious(marriages[j]);
                        Node* childNode = new Node();
                        childNode->setData(children[i]);
                        queue.insert(childNode);
                    }
                }
            }
        }
    }

    if (currPerson != personOne) {
        cout << "Individual " << personOne << " and individual " << personTwo;
        cout << " are not related!" << endl;
        return;
    }

    //Work "backwards" now from the starting point to the ending point
    cout << "Individual " << personOne;
    int currVal = personList[personOne].getPrevious();
    while (currVal != -1) {
        cout << " family " << currVal;
        currVal = familyList[currVal].getPrevious();
        cout << " individual " << currVal;
        currVal = personList[currVal].getPrevious();
    }

    cout << endl;
    Reset();
}

//Resets the state of being visited as well as the previous value for each
//person and family
void Database::Reset() {
    for (int i = 0; i < 100; i++) {
        personList[i].resetVisited();
        personList[i].resetPrevious();
        familyList[i].resetVisited();
        familyList[i].resetPrevious();
    }
}