//#include <utility>
#include <iostream>
#include "Contact.h"
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

Contact::Contact()
{

}

Contact::Contact(string name2)
{
    name = name2;
}

void Contact::addPhoneNumber(string number)
{
    phone_numbers.addSorted(number);
}

string Contact::getName()
{

    return name;
}

bool Contact::operator<(const Contact& c)
{

    if (name<c.name) {
        return true;
    }
    return false;
}

bool Contact::operator==(const Contact& c)
{
    if (name==c.name) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& o, Contact& c)
{
    cout <<"The Contact name is :" << " " << c.name << endl;
    cout <<"The Phone Numbers of The contact are" << endl;
    cout << c.phone_numbers << "**************";
    return o;
}
bool Contact::operator>=(const Contact& c)
{

    if (name>=c.name) {
        return true;
    }
    return false;
}





