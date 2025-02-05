#ifndef EXO
    #define EXO 6
#endif

#if EXO == 1
    // Analyse de la mémoire d’un tableau
    #include <iostream>

    int main(){
        // define a table of 10 integers
        int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        // print the size of the table
        // using sizeof()
        std::cout << "Taille totale du tableau : " << sizeof(tab) << " bytes" << std::endl;
        // the size of the first element is the same as any element in the table
        std::cout << "Taille d'un élément du tableau : " << sizeof(tab[0]) << " bytes" << std::endl;
        // the total size = size of one element * number of elements
        std::cout << "Nombre d'éléments : " << sizeof(tab) / sizeof(tab[0]) << std::endl;
        
        return 0;
    }

#elif EXO == 2
    // Estimation pour le service de nettoyage de tapis
    #include <iostream>

    int main(){
        std::cout << "Estimate for carpet cleaning service" << std::endl;
        // ask the user for the number of small and big pieces to clean
        int smallPieces, bigPieces;
        std::cout << "Number of small rooms: ";
        std::cin >> smallPieces;
        std::cout << "Number of big rooms: ";
        std::cin >> bigPieces;
        // calculate the total price
        std::cout << "Price per small room: 250dh" << std::endl;
        std::cout << "Price per big room: 350dh" << std::endl;
        // the coost is the number of small pieces * 250 + the number of big pieces * 350
        std::cout << "Cost : " << (smallPieces * 250) + (bigPieces * 350) << "dh" << std::endl;
        // the tax is 6% of the total price
        std::cout << "Tax: " << float((smallPieces * 250) + (bigPieces * 350)) * 0.06 << "dh" << std::endl;
        std::cout << "==========================================" << std::endl;
        // the total price is the cost + the tax (106%)
        std::cout << "Total estimate: " << float((smallPieces * 250) + (bigPieces * 350)) * 1.06 << "dh" << std::endl;
        // the estimate is valid for 30 days
        std::cout << "This estimate is valid for 30 days" << std::endl;
        
        return 0;
    }
#elif EXO == 3
    // Calcul de la factorielle à la compilation avec constexpr
    #include <iostream>

    // define the function factorial
    // the function is constexpr because it is called at compile-time
    constexpr unsigned long long factorial(unsigned int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }

    // FACT_5 is a constant that is calculated at compile-time
    // it stocks the result of the factorial of 5
    constexpr unsigned long long FACT_5 = factorial(5);

    // verifying the result at compile time
    static_assert(FACT_5 == 120, "La factorielle de 5 doit être 120");

    int main() {
        // show the result to the user
        std::cout << "Factorielle de 5: " << FACT_5 << std::endl;
    
        return 0;
    }
#elif EXO == 4
    // Variables Globales et Locales
    #include <iostream>

    // define a global variable
    int value = 100;

    int main(){
        // define a local variable
        int value = 50;
        // print the value of the local variable        
        std::cout << "Valeur locale: " << value << std::endl;
        // print the value of the global variable using :: operator
        std::cout << "Valeur globale: " << ::value << std::endl;
    
        return 0;
    }
#elif EXO == 5
    // Utilisation avancée des constantes
    #include <iostream>

    int main(){
        // define a constant
        const int mounths_in_year = 12;
        // define a compiled constant
        constexpr double circle_radius = 7.0;
        // define a constant using a macro
        #define PI 3.14159
        // calculate the area of a circle
        double area = PI * circle_radius * circle_radius;
        
        // print the results
        std::cout << "Nombre de mois dans une annee: " << mounths_in_year << std::endl;
        std::cout << "Rayon du cercle: " << circle_radius << std::endl;
        std::cout << "Aire du cercle: " << area << std::endl;

        return 0;
    }
#elif EXO == 6
    // Détection d’overflow lors d’une multiplication
    #include <iostream>
    #include <limits>

    int safeMultiply(int a, int b){
        // check using std::numeric_limits for overflow possiblity after multiplication
        if (std::numeric_limits<int>::max() / a < b){
            std::cerr << "Overflow detected!" << std::endl;
            return 0;
        }
        return a * b;
    }

    #ifndef TEST
     #define TEST 1
    #endif


    int main(){
        #if TEST == 1
            int a = 30000;
            int b = 1000;
            int result = safeMultiply(a, b);

            std::cout << "Result: " << result << std::endl;
        #elif TEST == 2
            int a = 300000;
            int b = 10000;
            int result = safeMultiply(a, b);

            std::cout << "Result: " << result << std::endl;
        #else
            // throw an error if the TEST variable is not in the range of the defined TEST
            #error "TEST variable is not in the range of the defined TEST"
        #endif

        return 0;
    }
#else
    // throw an error if the EXO variable is not in the range of the defined EXO
    #error "EXO variable is not in the range of the defined EXOs"
#endif  