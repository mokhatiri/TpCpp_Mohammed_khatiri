#include <iostream>
#include "Stack.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

int main() {
    try {
        Stack stack(2);
        stack.push(1);
        stack.push(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        func_a(stack);
    }
    catch (const StackFullException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    try {
        Stack stack(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        stack.pop();
    }
    catch (const StackEmptyException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    std::cout << "Program completed" << std::endl;
    return 0;
}