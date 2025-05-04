#pragma once
#include <iostream>

class Additionneur {
private:
    int valeur;
public:
    Additionneur(int v) : valeur(v) {}

    void operator()(int &n) const {
        n += valeur;
        std::cout << n << " ";
    }
};