#include <iostream>
#include <vector>
#include <functional>

void filtrer(const std::vector<int>& vec, std::function<bool(int)> pred) {
    for (const auto& el : vec) {
        if (pred(el)) {
            std::cout << el << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {10, 15, 20, 25, 30, 50, 75};

    // Predicate: x > 20
    std::cout << "Prédicat : 'x > 20'\n";
    filtrer(vec, [](int x) { return x > 20; });

    // Predicate: x % 2 == 0
    std::cout << "Prédicat : 'x % 2 == 0'\n";
    filtrer(vec, [](int x) { return x % 2 == 0; });

    return 0;
}
