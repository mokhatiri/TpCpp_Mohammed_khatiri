#ifndef EXO
    #define EXO 4
#endif

#if EXO == 1
    // Utilisation des directives du préprocesseur
    #include <iostream>

    #define PI 3.14159265359
    #define DEBUG
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
        for(int i = 0; i < argc; i++){
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
    
#else

#endif