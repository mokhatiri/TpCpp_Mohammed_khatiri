#pragma once
#include <string>

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

template <>
std::string maximum<std::string>(std::string a, std::string b) {
    return (a.compare(b) > 0) ? a : b; // this compares lexicographically
}