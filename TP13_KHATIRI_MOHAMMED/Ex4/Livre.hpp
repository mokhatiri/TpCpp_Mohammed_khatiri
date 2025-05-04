#pragma once
#include <string>
#include <iostream>

class Livre {
private:
    std::string titre;
    int pages;

public:
    Livre(const std::string& titre, int pages);
    std::string getTitre() const;
    int getPages() const;

    friend std::ostream& operator<<(std::ostream& os, const Livre& livre);
};
