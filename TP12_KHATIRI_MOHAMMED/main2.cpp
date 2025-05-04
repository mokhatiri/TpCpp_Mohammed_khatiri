#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main(){
    ifstream in_file("data.txt"); // we use (i)fstream for input
    ofstream out_file("report.txt"); // (o)fstream for output

    // in case of failure, for one of them
    if(!in_file || !out_file){
        cerr << "Erreur lors de l'ouverture des fichiers" << endl;
        return 1; // showing an error
    }

    // the header
    out_file << setw(20) << left << "Nom"
    << setw(10) << "Age" << setw(15) << "Salaire" << endl;

    string line;
    while(getline(in_file, line)){
        istringstream iss(line);
        string nom;
        int age;
        double salaire;
        if( iss >> nom >> age >> salaire){
            out_file << fixed << setprecision(2)
            << setw(20) << left << nom
            << setw(10) << age 
            << setw(15) << salaire 
            << endl;
        }
    }

    bool error = false;

    if (in_file.bad()) {
        // since the in_file fails anyway
        // so we check for .bad
        cerr << "Erreur de lecture du fichier" << endl;
        error = true;
    }
    if (out_file.fail()) {
        cerr << "Erreur d'écriture dans le fichier" << endl;
        error = true;
    } 

    // close the files
    in_file.close();
    out_file.close();

    if(!error){
        cout << "Rapport généré dans report.txt" << endl;
        return 0;
    }
    else{
        return 1;
    }
}