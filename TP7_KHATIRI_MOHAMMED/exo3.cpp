// Constructeur et Destructeurs
#include <iostream>

using namespace std;

class Joueur{
    private:
        string nom;
        int score;
    public:
        Joueur(string n = "_", int a = 0);
        ~Joueur();
        void afficher();
};

Joueur::Joueur(string n, int a){
    cout << "Constructeur appelé" << endl;
    nom = n;
    score = a;
}
Joueur::~Joueur(){
    cout << "Destruction appelé " << endl;
}
void Joueur::afficher(){
    cout << "Joueur: " << nom << ", Score: " << score << endl;
}

int main(){
    Joueur *j1 = new Joueur("Alice", 100);
    j1->afficher();
    delete j1;
}