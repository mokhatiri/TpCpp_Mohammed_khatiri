// simulation de gestion de memoire avec unique_ptr
#include <iostream>
#include <memory>

using namespace std;

// the objective:
/*
- make a struct MemoryBlock to simulate memory allocation
- use unique_ptr to manage memory allocation
- impliment a function to fuse and liberate memory blocks

output:

Bloc de memoire alloue de 100 unites.
Bloc de memoire alloue de 200 unites.
Fusion de deux blocs de memoire : 300 unites.
Liberation de la memoire.

*/
struct MemoryBlock {
    size_t size;

    MemoryBlock(size_t s) : size(s) {
        cout << "Bloc de mémoire alloué de " << size << " unités." << endl;
    }
};

unique_ptr<MemoryBlock> merge(unique_ptr<MemoryBlock>& block1, unique_ptr<MemoryBlock>& block2) {
    size_t newSize = block1->size + block2->size; // set the new size to the sum
    cout << "Fusion des deux blocs : " << newSize << " unités." << endl; // display the new size
    return make_unique<MemoryBlock>(newSize); // make a new unique_ptr to a memory block with the new size
}

int main() {
    // first two blocks
    unique_ptr<MemoryBlock> block1 = make_unique<MemoryBlock>(100); // using make_unique 
    unique_ptr<MemoryBlock> block2 = make_unique<MemoryBlock>(200); 

    // fuse them
    unique_ptr<MemoryBlock> mergedBlock = merge(block1, block2);

    // free memory using .reset()
    cout << "Libération de la mémoire." << endl;
    block1.reset();
    block2.reset();
    mergedBlock.reset();
    // we could also not do this, and after the program exists it frees memory on it's own

    return 0;
}