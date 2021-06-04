#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Contact.h"
#include "ContactManager.h"
#include "Treaps.h"
#include "Treaps.cpp"
#include "Error.h"

using namespace std;

int main()
{

    ContactManager obj;
    if (obj.loadFromFile(R"(D:\university\data structure\Ass4\Clion\all-contacts.txt)")) {
        while (true) {
            cout << "1-Display All contacts" << endl;
            cout << "2-Find contact by phone number" << endl;
            cout << "3-Find contact by name and print it's information" << endl;
            cout << "4-Add contact" << endl;
            cout << "5-Exit" << endl;
            char choose;
            cin >> choose;
            if (choose=='1') {
                cout << obj << endl;
            }
            else if (choose=='2') {
                string phoneNumber;
                cout << "Enter the phone number of the contact you want to find : ";
                cin >> phoneNumber;
                cout << endl;
                while (true) {
                    try {
                        obj.displayNumber(phoneNumber);
                        break;
                    }
                    catch (Error& e) {
                        cout << "The phone number format is " << e.what() << endl;
                        cout << "Enter the phone number again or enter 0 to stop : ";
                        cin >> phoneNumber;
                        cout << endl;
                        if (phoneNumber=="0") {
                            break;
                        }
                    }
                }
            }
            else if (choose=='3') {
                string contactName;
                cout << "Enter the contact name : ";
                cin.ignore();
                getline(cin, contactName);
                obj.displayAllNumbersForPerson(contactName);
            }
            else if (choose=='4') {
                string contactName, phoneNumber;
                cout << "Enter the Phone number : ";
                cin >> phoneNumber;
                cout << endl;
                cout << "Enter the contact name : ";
                cin.ignore();
                getline(cin, contactName);
                cout << endl;
                while (true) {
                    try {
                        if(obj.isAlreadyExist(phoneNumber))
                        {
                            cout<<"This number already exists and it will not be added."<<endl;
                            break;
                        }
                        obj.add(contactName, phoneNumber);
                        break;
                    }
                    catch (Error& e) {
                        cout << "The phone number format is " << e.what() << endl;
                        cout << "Enter the phone number again or enter 0 to stop : ";
                        cin >> phoneNumber;
                        cout << endl;
                        if (phoneNumber=="0") {
                            break;
                        }
                    }
                }
            }
            else if (choose=='5') {
                break;
            }
        }
    }
    else {
        cout << "Can't open the file" << endl;
    }
    return 0;
}