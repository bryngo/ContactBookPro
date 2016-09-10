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

void printError() {

    cout << "\n" << "///////////////////////////////////////////////////////////////////" << endl <<
                    "==//ERROR//== Please enter a valid option. Thank you! ==//ERROR//==" << endl <<
                    "///////////////////////////////////////////////////////////////////" << "\n\n";
}

int main() {

    Hash hash;
    hash.read("/Users/Bryan1/Projects/ClionProjects/ContactDirectory/contactsREAL.txt");
    string input;
    bool stay = true;

    while(stay) {

        printMenu();
        cin >> input;
        cin.ignore();

        if(input.length() > 1) {
            printError();
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
                break;
            default:
                printError();
                continue;
        }

    }

    return 0;
}
