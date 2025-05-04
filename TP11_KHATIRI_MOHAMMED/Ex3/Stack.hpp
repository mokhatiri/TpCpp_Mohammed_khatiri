#pragma once
#include <vector>

class Stack {
private:
    std::vector<int> elements;
    std::size_t capacity;
public:
    Stack(std::size_t cap);
    void push(int value);
    void pop();
    std::size_t size() const;
};

void func_a(Stack& s);
void func_b(Stack& s);
void func_c(Stack& s);