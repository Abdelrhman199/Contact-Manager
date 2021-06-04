#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
#include "LinkedList.h"

using namespace std;

class Contact {
private:
    string name;
    LinkedList<string> phone_numbers;
public:
    Contact();

    Contact(string name);

    void addPhoneNumber(string number);

    string getName();

    bool operator<(const Contact& c);

    bool operator>=(const Contact& c);

    bool operator==(const Contact& c);

    friend ostream& operator<<(ostream& o, Contact& c);
};

#endif  /* CONTACT_H_ */
