#include "Movies.hpp"

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const auto& movie : collection) {
        if (movie.get_name() == name) {
            return false;
        }
    }
    collection.push_back(Movie(name, rating, watched));
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (auto& movie : collection) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (collection.empty()) {
        std::cout << std::endl << "Désolé, aucun film à afficher" << std::endl << std::endl;
        return;
    }
    std::cout<< std::endl <<"==================================="<< std::endl;

    for (const auto& movie : collection) {
        movie.display();
    }
    std::cout<<"==================================="<<std::endl << std::endl;

}
