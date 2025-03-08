// Gestion d'un système de notes
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Etudiant{
    private:
        string nom;
        vector<double> notes;
    public:
        Etudiant(string nom, vector<double> notes){
            this->nom = nom;
            this->notes = notes;
        }
        void afficher(){
            cout << "Nom : " << nom << endl;
            cout << "Notes : ";
            for(long unsigned i = 0; i < notes.size(); i++){
                cout << notes[i];
                if(i != notes.size() - 1){
                    cout << ", ";
                }
            }
            cout << endl;
        }
        double moyenne(){
            double somme = 0;
            for(long unsigned i = 0; i < notes.size(); i++){
                somme += notes[i];
            }
            return somme / notes.size();
        }
};

int main(){
    Etudiant* etudiant = new Etudiant("Karim", {15, 18, 12});
    etudiant->afficher();
    cout << "Moyenne : " << etudiant->moyenne() << endl;
    delete etudiant;
    return 0;
}