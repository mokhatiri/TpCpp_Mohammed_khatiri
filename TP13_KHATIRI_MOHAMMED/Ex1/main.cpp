#include <iostream>
#include <vector>
#include <algorithm>
#include "Additionneur.hpp"

int main() {
    std::vector<int> vec = {10, 11, 12, 13, 14};

    // Use the functor
    std::for_each(vec.begin(), vec.end(), Additionneur(1)); // Add 1 to each element
    std::cout << std::endl;

    return 0;
}