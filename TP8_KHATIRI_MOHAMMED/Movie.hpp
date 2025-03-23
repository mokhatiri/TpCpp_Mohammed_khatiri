#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int watched;

public:
    Movie(std::string name, std::string rating, int watched);

    void increment_watched();
    void display() const;

    std::string get_name() const { return name; }
    std::string get_rating() const { return rating; }
    int get_watched() const { return watched; }
};

#endif // MOVIE_H
