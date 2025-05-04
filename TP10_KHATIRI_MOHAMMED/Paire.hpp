#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class PaireBase {
public:
    virtual void afficher() const = 0;
    virtual ~PaireBase() = default;
};

template<typename T, typename U>
class Paire : public PaireBase {
protected:
    T premier;
    U second;
public:
    Paire(const T& a, const U& b) : premier(a), second(b) {}

    void afficher() const override {
        if constexpr (std::is_same<U, bool>::value) {
            std::cout << premier << " : " << (second ? "vrai" : "faux") << std::endl;
        } else {
            std::cout << premier << " : " << second << std::endl;
        }
    }
};

template<typename T>
class Paire<T, int> : public PaireBase {
private:
    T premier;
    int second;
public:
    Paire(const T& a, int b) : premier(a), second(b) {}

    void afficher() const override {
        std::cout << premier << " : " << second << " (entier) " << std::endl;
    }
};