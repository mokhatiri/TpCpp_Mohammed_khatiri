#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

int main() {
    std::ofstream out_file("output.txt");

    if (!out_file) {
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Entrez des nombres flottants (ligne vide pour arrêter) :\n";

    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) break;

        std::istringstream iss(line);
        double num;
        if (iss >> num) {
            out_file << std::fixed << std::setprecision(2)
                     << std::setw(10) << std::left << num << std::endl;
        } else {
            std::cerr << "Entrée non valide ignorée." << std::endl;
        }
    }

    out_file.close();
    std::cout << "Nombres enregistrés dans output.txt" << std::endl;
    return 0;
}