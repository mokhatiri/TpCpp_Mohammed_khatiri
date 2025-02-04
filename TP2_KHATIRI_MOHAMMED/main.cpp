#ifndef EXO
    #define EXO 1
#endif

#if EXO == 1
    // Utilisation des directives du préprocesseur
    #include <iostream>

    #define PI 3.14159265359

    int main(){
        #ifdef DEBUG
            std::cout << "debug macro exists" << std::endl;
        #endif

        return 0;
    }
#elif EXO == 2
    #include <iostream>
    // Utilisation de la fonction main
    int main(int argc, char* argv[]){

        // start from 1 rather then 0, since the argv[0] is the file name
        for(int i = 1; i < argc; i++){
            std::cout << "Argument " << i << ":  " << argv[i] << std::endl;
        }
        return 0;
    }
#elif EXO == 3
    // Espaces de noms et portée des variables
    #include <iostream>

    // Définition d'un espace de noms personnalisé
    namespace MonEspace {
        int valeur = 42;
    }

    int main() {
        // Utilisation de std::cout sans using namespace std
        std::cout << "Sans 'using namespace std':" << std::endl;
        std::cout << "Valeur dans MonEspace: " << MonEspace::valeur << std::endl;

        // Déclarer l'utilisation de l'espace de noms std
        using namespace std;

        // Utilisation de cout sans std::
        cout << "\nAvec 'using namespace std':" << endl;
        cout << "Valeur dans MonEspace: " << MonEspace::valeur << endl;

        return 0;
    }
#elif EXO == 4
    // Entrée et sortie avec cin et cout
    #include <iostream>

    int main(){
        // getting an integer from the user
        int entier;
        std::cout << "Entrez un entier: ";
        std::cin >> entier;
        // getting a float from the user
        float decimal;
        std::cout << "Entrez un nombre decimal: ";
        std::cin >> decimal;
        // printing the values
        std::cout << "Valeurs saisies:" << entier << " et " << decimal << std::endl;
    }
#else
    // throw an error if the EXO variable is not in the range of the defined EXO
    #error "EXO variable is not in the range of the defined EXOs"
#endif  