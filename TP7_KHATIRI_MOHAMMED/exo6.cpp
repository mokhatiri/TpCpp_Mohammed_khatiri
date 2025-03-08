// Manipulation de fichiers avec pointeurs
#include <iostream>
#include <fstream>

using namespace std;

/*
expected output:

Sauvegarde des données...
Lecture des données...
Contenu du fichier :
Bonjour, ceci est un test.
Mémoire du flux libérée.
*/

class Fichier{
    private:
        string nom;
    public:
        Fichier(string nom){
            this->nom = nom;
        }
        ~Fichier(){
            cout << "Mémoire du flux libérée." << endl;
        }
        void sauvegarder(string texte){
            ofstream fichier(nom, ios::out | ios::trunc);
            if(!fichier){
                cerr << "Erreur d'ouverture du fichier." << endl;
                return;
            }
            else{
                cout << "Sauvegarde des données..." << endl;
                fichier << texte;
                fichier.close();
            }
        }
        string lire(){
            string texte;
            ifstream fichier(nom, ios::in);
            if(!fichier){
                cerr << "Erreur d'ouverture du fichier." << endl;
            }else{
                getline(fichier, texte);
                fichier.close();
            }

            return texte;
        }
        void afficher(){
            cout << "Lecture des données..." << endl;
            cout << "Contenu du fichier :" << endl;
            try{
                cout << lire() << endl;
            }catch(const char* e){
                cerr << e << endl;
            }
        }
};

int main(){
    Fichier fichier("test.txt");
    fichier.sauvegarder("Bonjour, ceci est un test.");
    fichier.afficher();
    return 0;
}