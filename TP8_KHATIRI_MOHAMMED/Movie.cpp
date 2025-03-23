#include "Movie.hpp"

Movie::Movie(std::string name, std::string rating, int watched) 
    : name(name), rating(rating), watched(watched) {}

void Movie::increment_watched() {
    watched++;
}

void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}
