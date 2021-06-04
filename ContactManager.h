#ifndef CONTACT_MANAGER_H_
#define CONTACT_MANAGER_H_

#include <iostream>
#include "LinkedList.h"
#include "Contact.h"
#include "ContactManager.h"
#include "Treaps.h"
#include "Error.h"

using namespace std;


class ContactManager{
private:
    LinkedList<Contact> contacts;
    Treaps<string, Contact*> tree;
    Treaps<string, Contact*> tree2;
    Contact* newObj;
    Error error;
public:
    ContactManager();

    bool loadFromFile( string fileName);

    void add(string name, string phone_number);

    void displayNumber( string phone_number);

    void displayAllNumbersForPerson( string name);

    bool isAlreadyExist(string value);

    friend ostream& operator<<(ostream& o, ContactManager& c);
};

#endif  /* CONTACT_MANAGER_H_ */
