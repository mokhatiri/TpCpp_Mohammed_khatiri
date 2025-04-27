#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Conteneur {
    private:
        size_t max_length;
        vector<T> elements;
    public:
        Conteneur(size_t length) : max_length(length) {}
        void ajouter(T new_elem) {
            if(elements.size() < max_length) elements.push_back(new_elem);
            else cout << "Capavité depassée" << endl;
        }
        T obtenir(size_t index) const {
            if (index >= elements.size()) {
                std::cerr << "Erreur : index invalide." << std::endl;
                return T();
            }
            return elements[index];
        }
};