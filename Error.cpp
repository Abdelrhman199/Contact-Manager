//
// Created by Mohamed on 4/30/2019.
//

#include "Error.h"
#include <iostream>
//#include <wsman.h>

using namespace std;
const char* Error::what() const noexcept
{
    return "Is Incorrect";
}

bool Error::isValid(string phone_number)
{
    if (phone_number.size()!=11 && phone_number.size()!=10) {
        return false;
    }
    if (phone_number.size()==11) {
        for (int i = 0; i<11; i++) {
            if ((int) phone_number[i]<48 || (int) phone_number[i]>57) { return false; }
        }
        int checkFirstThree = (int) phone_number[0]+(int) phone_number[1]+(int) phone_number[2];
        if (checkFirstThree>=145 && checkFirstThree<=150) {
            if (checkFirstThree==148 || checkFirstThree==149) {
                return false;
            }
        }
        else { return false; }
    }
    else if (phone_number.size()==10) {
        for (int i = 0; i<10; i++) {
            if ((int) phone_number[i]<48 || (int) phone_number[i]>57) { return false; }
        }
        int checkFirstTwo = (int) phone_number[0]+(int) phone_number[1];
        if (checkFirstTwo!=98) { return false; }
    }
    return true;
}

