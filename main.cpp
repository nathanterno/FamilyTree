#include <iostream>
#include <fstream>
#include "Database.h"

using namespace std;

int main(int argc, char** argv) {
    const int ARGUMENTS = 2;
    
    // check the command line argument, an input file name is needed
    if (argc != ARGUMENTS)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }   

        // check if the input file can be opened successfully
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.good())
    {
        cout << "Cannot open the file named " << argv[1] << endl;
        return 2;
    }  
    
    // read in the terms from the input file
    // line by line and store into Autocomplete object
    Database familyGraph;
    string next;
    string temp;

    infile >> next;

    bool breakNow = false;
    while (breakNow == false)
    {
        //Add person to personList
        if (next == "Insert") {
            int number;
            infile >> number;
            infile >> temp;
            int parent;
            infile >> parent;
            if (parent == 0) {
                parent = -1;
            }
            int marriages[10];
            for (int p = 0; p < 10; p++) {
                marriages[p] = -1;
            }
            int i = 0;
            infile >> temp;
            while (temp == "Marriage" && i < 10) {
                infile >> marriages[i];
                if (infile >> temp) {

                }
                else {
                    breakNow = true;
                }
                i++;
            }
            familyGraph.Insert(number, parent, marriages);
            next = temp;
        }
        //Add family to familyList
        else if (next == "Family") {
            int number;
            infile >> number;
            infile >> temp;
            int husband;
            infile >> husband;
            if (husband == 0) {
                husband = -1;
            }
            infile >> temp;
            int wife;
            infile >> wife;
            if (wife == 0) {
                wife = -1;
            }
            int children[10];
            for (int w = 0; w < 10; w++) {
                children[w] = -1;
            }
            int j = 0;
            infile >> temp;
            while (temp == "Child" && j < 10) {
                infile >> children[j];
                if (infile >> temp) {
                }
                else {
                    breakNow = true;
                }
                j++;
            }
            familyGraph.Family(number, husband, wife, children);
            next = temp;
        }
        //Checks both lists for consistency
        else if (next == "Check") {
            familyGraph.Check();
            if (infile >> next) {
            }
            else {
                breakNow = true;
            }
        }
        //Relates one person to another by traversing the graph
        else if (next == "Relate") {
            int personOne;
            infile >> personOne;
            int personTwo;
            infile >> personTwo;
            familyGraph.Relate(personOne, personTwo);
            if (infile >> next) {
            }
            else {
                breakNow = true;
            }
        }
    }
}