// Gestion d'un inventaire avec pointeurs dynamiques
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

using namespace std;

class Objet{
    private:
        string nom;
        int quantité;
    public:
        Objet(string n = "_", int q = 0);
        ~Objet(){};
        void afficher();
        void decrementer(int n = 1);
        void incrementer(int n = 1);
        void Unify(Objet* o);
        string getNom();
};
Objet::Objet(string n, int q){
    nom = n;
    quantité = q;
}
void Objet::afficher(){
    cout << nom << " (x" << quantité << ") ";
}
void Objet::decrementer(int n){
    if(quantité > 0) quantité-=n;
}
void Objet::incrementer(int n){
    quantité+=n;
}
string Objet::getNom(){
    return nom;
}

class Inventaire{
    private:
        unordered_map<string,unique_ptr<Objet>> objets;
    public:
        Inventaire(){};
        ~Inventaire();
        void ajouter(string nom = "_", int quantité = 0);
        void supprimer1(string nom);
        void supprimerAll(string nom);
        void afficher();
};

Inventaire::~Inventaire(){
    cout << "Mémoire de l'inventaire libérée." << endl;
}
void Inventaire::ajouter(string nom, int quantité){
    if(objets.find(nom) == objets.end()){
        Objet *o = new Objet(nom, quantité);
        objets[nom] = unique_ptr<Objet>(o);
    }else{
        objets[nom]->incrementer(quantité);
    }

    cout << "Ajout de ";
    objets[nom]->afficher();
    cout << endl;
}
void Inventaire::supprimer1(string nom){
    if (objets.find(nom) != objets.end())
        objets[nom]->decrementer();
}
void Inventaire::supprimerAll(string nom){
    if (objets.find(nom) != objets.end())
        objets.erase(nom);
}
void Inventaire::afficher(){
    cout << "Inventaire:" << endl;
    for(const auto& pair : objets){
        cout << "- ";
        pair.second->afficher();
        cout << endl;
    }
}

int main(){
    Inventaire i;
    i.ajouter("Pomme", 3);
    i.ajouter("Epée", 1);
    i.afficher();
    return 0;
}