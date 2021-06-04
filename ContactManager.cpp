#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Contact.h"
#include "ContactManager.h"
#include "Treaps.h"
#include "Treaps.cpp"


using namespace std;

ContactManager::ContactManager()
{
    newObj = nullptr;
}

bool ContactManager::loadFromFile(string fileName)
{
    ifstream file;
    file.open(fileName);
    string name, phone_number;
    if (file.fail()) {
        file.close();
        return false;
    }
    while (true) {

        file >> phone_number;
        file.ignore();
        getline(file, name);
        if (file.eof()) {
            break;
        }
        try {
            add(name, phone_number);
        }
        catch (Error& e) {
            cout << "The format of phone number of " << name << " " << e.what() << " " << phone_number << endl
                 << "^^^^^^^^^^^^^^^^^" << endl;
        }
    }
    file.close();
    return true;

}

void ContactManager::add(string name, string phone_number)
{
    LinkedList<Contact>::MyNode* temp = contacts.get(name);
    if (!error.isValid(phone_number)) { throw error; }
    if (temp==nullptr) {
        newObj = new Contact(name);
        newObj->addPhoneNumber(phone_number);
        contacts.addSorted(*newObj);
        tree.insert(phone_number, newObj);
        tree2.insert(name , (Contact *)contacts.get(name));
    }
    else {
        temp->value.addPhoneNumber(phone_number);
        tree.insert(phone_number, (Contact*)(temp));
    }
}

void ContactManager::displayNumber(string phone_number)
{
    if (!error.isValid(phone_number)) { throw error; }
    Contact* obj = tree.find(phone_number);
    if (obj==nullptr) {
        cout << "The Number you entered doesn't exist : ";
        cout << phone_number << endl;
    }
    else {
        cout << obj->getName()<< endl;
    }
}

ostream& operator<<(ostream& o, ContactManager& c)
{
    o << c.contacts << endl;
    return o;
}

void ContactManager::displayAllNumbersForPerson(string name)
{
    Contact* obj = tree2.find(name);
    if (obj==nullptr) {
        cout << "The name you entered doesn't exist : "<< name << endl;
    }
    else {
        cout << *obj << endl;
    }
}

bool ContactManager::isAlreadyExist(string value)
{
    Contact *check = tree.find(value);
    if(check!=nullptr)
    {
        delete check;
        return true;
    }
    delete check;
    return false;
}

