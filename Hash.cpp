//
// Created by Bryan Ngo on 8/5/16.
//

#include <iostream>
#include <vector>
#include "Hash.h"

using namespace std;

//
// Created by Bryan Ngo on 8/5/16.
//
//
// Format of file is Name:--> Number:--> Email:--> EmptyLine

#include <iostream>
#include <fstream>

using namespace std;

Hash::Hash() {

    for(int i = 0; i < tableSize; i++) {
        HashTable[i] = new contact;
        HashTable[i]->name = "empty";
        HashTable[i]->number = "empty";
        HashTable[i]->email = "empty";
        HashTable[i]->next = NULL;
    }

}

void Hash::getArea() {
    string areaCode;
    string areaCodeCurr;
    cout << "Please enter the area code: " << endl;
    cin >> areaCode;

    vector<contact*> contactList;

    for(int i = 0; i < tableSize; i++) {
        if(HashTable[i]->name == "empty")
            continue;
        else {
            for(contact *ptr = HashTable[i]; ptr; ptr = ptr->next) {
                areaCodeCurr += HashTable[i]->number.at(0);
                areaCodeCurr += HashTable[i]->number.at(1);
                areaCodeCurr += HashTable[i]->number.at(2);

                cout << "Comparing " << areaCodeCurr << " and " << areaCode << endl;

                if(!areaCode.compare(areaCodeCurr)) {
                    contactList.push_back(ptr);
                } // do the area codes match?
                areaCodeCurr.erase();
            }
        }
    }

   // printList(contactList);

} //

void Hash::printList(vector<contact*> &contactList) {

    cout << "Found " << contactList.size() << " contact(s):" << endl;

    for(int i = 0; i < contactList.size(); i++) {
        cout << "Name: " << contactList.at(i)->name << endl;
        cout << "Number: " << contactList.at(i)->number << endl;
        cout << "Email: " << contactList.at(i)->email << '\n' << endl;
    }

} // helper function used to print out all founded results

void Hash::lookUpName() {

    string name;

    vector<contact*> contactsList;

    cout << "Please enter the first, last, or full name: ";
    getline(cin, name);

    for(int i = 0; i < tableSize; i++) {
        if(HashTable[i]->name == "empty")
            continue;
        else {
            for(contact *ptr = HashTable[i]; ptr; ptr = ptr->next) {
                if(ptr->name.find(name) != string::npos)
                    contactsList.push_back(ptr);
                else
                    continue;
            }
        }
    }

    printList(contactsList);

}

void Hash::displayAll() {

    cout << "Printing directory..." << endl;

    for(int i = 0, letter = 65; i < tableSize; i++, letter++) {
        cout << "=========" << (char)letter << "=========" << endl;

        if(HashTable[i]->name == "empty") {
            cout << "No contacts starting with letter " << (char)letter << endl << endl;
            continue;
        }

        for(contact* curr = HashTable[i]; curr; curr = curr->next) {
            cout << "Name: " << curr->name << endl;
            cout << "Number: " << curr->number << endl;
            cout << "Email: " << curr->email << endl << endl;
        }
    }
} // display all data

void Hash::addContact(contact *temp, int index) {

    contact* ptr = HashTable[index];

    if(!(HashTable[index]->name).compare("empty"))
        HashTable[index] = temp;
    else {
        while(ptr->next) {
            ptr = ptr->next;
        } // find the end of the list
        ptr->next = temp;
    }

} // adds a contact to the list

int Hash::getHash(string name) {
    int index = (int)name.at(0) - 65;
    return index;
} // simple hash function to get index based on first name

string Hash::parseLine(string buffer) {

    size_t pos = buffer.find(" ");
    string temp = buffer.substr(pos + 1);

    if(!temp.compare("Name:") || !temp.compare("Number:") || !temp.compare("Email:")) {
        return "Field not provided"; // field not filled out
    } else {
        return temp;
    }
} // gets the line information

void Hash::read(string filename) {

    ifstream file(filename);
    string buffer;
    int index;

    for(int i = 0; getline(file, buffer); i++) {

        contact *curr = new contact;

        curr->name = parseLine(buffer);
        index = getHash(curr->name);
        getline(file, buffer);

        curr->number = parseLine(buffer);
        getline(file, buffer);

        curr->email = parseLine(buffer);
        getline(file, buffer); //get past the empty line
        addContact(curr, index);
    }
} // read in the file
