// Defining a class and creating an object
#include <iostream>
using namespace std;

/*
output attendue:

Joueur: Alice, Score: 100
Joueur: Bob, Score: 200
*/

class Joueur{
    private:
        // attributes
        string nom;
        int score;
    public:
        // constructor
        Joueur(string name = "_", int score = 0){
            this->nom = name;
            this->score = score;
        }
        // destructor
        ~Joueur(){}
        // methods
        void display(){
            cout << "Joueur: " << nom << ", Score: " << score << endl;
        }
};


int main(){
    Joueur joueur1("Alice", 100);
    Joueur joueur2("Bob", 200);
    joueur1.display();
    joueur2.display();
}