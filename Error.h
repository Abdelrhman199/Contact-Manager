//
// Created by Mohamed on 4/30/2019.
//

#ifndef CLION_ERROR_H
#define CLION_ERROR_H

#include <iostream>
using namespace std;
class Error: public exception {
public:
    const char* what() const noexcept override;
    bool isValid(string phone_number);
};

#endif //CLION_ERROR_H
