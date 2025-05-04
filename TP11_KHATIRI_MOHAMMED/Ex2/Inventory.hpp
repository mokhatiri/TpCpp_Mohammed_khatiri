#pragma once

class Inventory {
private:
    int stock;
public:
    Inventory(int initial_stock = 0);
    void add_items(int quantity);
    void remove_items(int quantity);
    int get_stock() const;
};