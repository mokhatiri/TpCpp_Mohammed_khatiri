#include "Stack.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

Stack::Stack(std::size_t cap) : capacity(cap) {}

void Stack::push(int value) {
    if (elements.size() >= capacity)
        throw StackFullException();
    elements.push_back(value);
}

void Stack::pop() {
    if (elements.empty())
        throw StackEmptyException();
    elements.pop_back();
}

std::size_t Stack::size() const {
    return elements.size();
}

void func_c(Stack& s) {
    s.push(99);
}

void func_b(Stack& s) {
    func_c(s);
}

void func_a(Stack& s) {
    func_b(s);
}