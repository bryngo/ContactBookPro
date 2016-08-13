#include <iostream>

#include "hash.h"
using namespace std;

void printMenu() {

    cout << "============ Welcome to Bryan Ngo's Contact Directory! ============" << endl
         << "=================== Please choose an option... ===================" << endl;

    cout << endl << "Menu:" << endl
         << "a: Print out entire directory" << endl
         << "s: Search for a contact" << endl
         << "c: Search for all contacts with a specific area code" << endl
         << "q: Quit" << endl;
}

int main() {

    Hash hash;
    hash.read("/Users/Bryan1/ClionProjects/ContactDirectory/contacts.txt");
    string input;
    bool stay = true;

    while(stay) {

        printMenu();
        getline(cin, input);

        if(input.length() > 1) {
            cout << "Please enter a single character input" << endl;
            continue;
        }

        switch((int)input.at(0)) {
            case 'a' :
                hash.displayAll();
                continue;
            case 's' :
                hash.lookUpName();
                continue;
            case 'c' :
                hash.getArea();
                continue;
            case 'q' :
                stay = false;
            default:
                cout << "Please enter a valid option. Thank you!" << endl;
                continue;
        }
    }
    return 0;
}
