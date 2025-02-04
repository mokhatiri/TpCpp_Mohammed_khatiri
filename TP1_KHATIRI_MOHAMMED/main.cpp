#ifndef EXO
    #define EXO 1
#endif

#include <iostream>

#if EXO == 1
// Aﬀichage d’un message
int main(){
    // simple usage of cout
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Bienvenue en C++!" << std::endl;
}
#elif EXO == 2
// Lecture et aﬀichage d’un entier
int main(){
    // using cout and cin
    // first since the input is a number, we specifie this before
    // by defining number as an int
    int number;
    std::cout << "Entrez un nombre : ";
    std::cin >> number;
    std::cout << "Vous avez entré : " << number << std::endl;
}
#elif EXO == 3
// Opérations mathématiques
int main(){
    // using cout and cin again
    std::cout << "Entrez deux nombres:";
    int number1, number2;
    std::cin >> number1 >> number2;

    // for every operation we just use the operands '+' '-' '*' '/'
    std::cout << "Somme: " << number1 + number2 << std::endl;
    std::cout << "Différence:" << number1 - number2 << std::endl;
    std::cout << "Produit:" << number1 * number2 << std::endl;

    // in the case of division, we need to convert the numbers to float before deviding
    std::cout << "Quotient:" << float(number1) / float(number2) << std::endl;
}
#elif EXO == 4
// Détection et correction d’erreurs de compilation
int main() {
    // the original code: std::cout << "Entrez un nombre:
    // the opened " wasn't closed and no ';' was added 
    std::cout << "Entrez un nombre:";
    int nombre;
    std::cin >> nombre;
    // the original code: std::cout << "Vous avez entré: " << nombre << std::endl
    // the ';' was missing
    std::cout << "Vous avez entré: " << nombre << std::endl;
    return 0;
}
#elif EXO == 5
// Conversion de température
int main(){
    // we say that: F = 9/5 * C + 32
    std::cout << "Entrez une température en degrés Celsius: ";
    // the variable celsius is a double
    double celsius;
    std::cin >> celsius;
    // we calculate the temperature in Fahrenheit using the formula
    double fahrenheit = 9.0 / 5.0 * celsius + 32;
    std::cout << "La température en degrés Fahrenheit est: " << fahrenheit << std::endl;
}
#else
// Error message for invalid EXO value
    #error "EXO must be between 1 and 5"
#endif