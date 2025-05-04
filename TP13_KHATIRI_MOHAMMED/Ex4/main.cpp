#include "Livre.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Livre::Livre(const std::string& titre, int pages) : titre(titre), pages(pages) {}

std::string Livre::getTitre() const {
    return titre;
}

int Livre::getPages() const {
    return pages;
}

std::ostream& operator<<(std::ostream& os, const Livre& livre) {
    os << livre.getTitre() << " - " << livre.getPages() << " pages";
    return os;
}

int main() {
    std::vector<Livre> livres = {
        Livre("C++ Moderne", 350),
        Livre("Apprendre Python", 500),
        Livre("Algorithmique", 450)
    };

    std::cout << "À partir des livres :" << std::endl;
    std::cout << "“‘ ";
    for (const auto& livre : livres)
        std::cout << livre << " ";
    std::cout << "“‘\n" << std::endl;

    std::cout << "- Tri par titre :" << std::endl;
    std::sort(livres.begin(), livres.end(), [](const Livre& a, const Livre& b) {
        return a.getTitre() < b.getTitre();
    });
    for (const auto& livre : livres)
        std::cout << livre << std::endl;

    std::cout << "\n- Tri par nombre de pages décroissant :" << std::endl;
    std::sort(livres.begin(), livres.end(), [](const Livre& a, const Livre& b) {
        return a.getPages() > b.getPages();
    });
    for (const auto& livre : livres)
        std::cout << livre << std::endl;

    return 0;
}
