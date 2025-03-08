// Gestion d'objets avec pointeurs
#include <iostream>
using namespace std;

class Joueur{
    private:
        string nom;
        int score;
    public:
        Joueur(string nom, int score){
            this->nom = nom;
            this->score = score;
        }
        ~Joueur(){
            cout << "Objet dynamique supprimé." << endl;
        }
        void afficher(){
            cout << "Nom : " << nom << endl;
            cout << "Score : " << score << endl;
        }
};

int main(){
    Joueur *j1 = new Joueur("Alice", 100);
    j1->afficher();
    delete j1;
}