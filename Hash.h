//
// Created by Bryan Ngo on 8/5/16.
//

#include <iostream>
#include <vector>
using namespace std;


#ifndef CONTACTDIRECTORY_HASH_H
#define CONTACTDIRECTORY_HASH_H


class Hash {

    static const unsigned long tableSize = 26;

    struct contact {
        string name;
        string number;
        string email;
        contact* next;
    };

    contact* HashTable[tableSize];

public:
    Hash();
    int getHash(string name); // returns index for desired contact
    void read(string filename); // reads in the text file
    void addContact(contact* temp, int index); // adds contact to hash table
    string parseLine(string buffer); // reads in line from file

    //menu options
    void displayAll();
    void lookUpName();
    void printList(vector<contact*> &contactList);
    void getArea(); // gets all contacts with given area code
};

#endif //CONTACTDIRECTORY_HASH_H
