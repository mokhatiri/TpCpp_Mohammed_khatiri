#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 12, 15, 17};

    // Add 5 to each element using std::transform and lambda
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int &n) { return n + 5; });

    // Display the modified vector
    for (const auto &n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
