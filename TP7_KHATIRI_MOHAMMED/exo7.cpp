// implimenting the class SharedPtr 
#include <iostream>

using namespace std;

template <typename T> // to not have to determine the type of the variable

class SharedPtr {
private:
    T* ptr;
    int* ref_count;

public:

    // after looking up the std::shared_ptr;
    // we found that the constructor can take a pointer or an reference to an object
    // if it's a pointer it's a pointer to an object we start the count from 1
    // if it's a reference we start the count from the ref_count of the object
    // we can also initialize the pointer using the = operator
    // that works basically the same as by reference

    // Constructeur par défaut
    SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {
        // in case we don't have a pointer we initialize it to nullptr
        // in case we have a pointer we initialize it to the pointer
        // we also initialize the ref_count to 1
        if (ptr) {
            cout << "Création d'un SharedPtr vers " << *ptr << "\n";
        }
    }

    // Constructeur par reference (copy)
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        if (ptr) {
            // since this is a copy we increment the ref_count
            // the ref point is now pointing to the same memory address
            // so any change in the memory will be reflected in both pointers
            (*ref_count)++;
            cout << "Création d'une copie\n";
        }
    }

    // in case the person is calling using = operator
    // first reset the current pointer for no memory leak
    // then we copy the pointer and the ref_count
    // the = operator is called over the reference of the object
    SharedPtr& operator=(const SharedPtr& other) {
        // we don't want to free the very thing we want to build
        if (this != &other) {
            reset(); // 1st reset

            ptr = other.ptr; // appoint the pointer to the other pointer
            ref_count = other.ref_count; // same for the ref_count
            
            // incase the pointer is null no incrementation is possible
            if (ptr) {
                (*ref_count)++; // if not we increment the ref_count
                cout << "Création d'une copie" << endl;
            }
        }
        return *this; // return the reference to the object
    }

    // Réinitialisation du pointeur
    void reset() {
        // if it's not null
        if (ptr) {
            (*ref_count)--; // deecrement the ref_count before deleting
            cout << "Destruction d'un SharedPtr\n";
            if (*ref_count == 0) {
                // if the ref_count is 0
                // this is the last copy of the object
                // we delete the pointer and the ref_count
                delete ptr;
                delete ref_count;
                cout << "Objet supprimé\n";
            }
        }
        ptr = nullptr; // reset the pointer to nullptr
        ref_count = nullptr; // reset the ref_count to nullptr
    }

    // Destructeur
    ~SharedPtr() {
        reset(); // use the reset function
    }

    // Obtenir le nombre de références
    int getRefCount(){
        return (ref_count) ? *ref_count : 0;
    }
};

int main() {
    {
        SharedPtr<int> sp1(new int(10));
        cout << "Nombre de références : " << sp1.getRefCount() << "\n";

        SharedPtr<int> sp2 = sp1;
        cout << "Nombre de références : " << sp2.getRefCount() << "\n";

        sp1.reset();
        cout << "Nombre de références : " << sp2.getRefCount() << "\n"; // this can also be sp1, as it's now a nullptr
        // both sp1 and sp2 will be deleted next
    }
    return 0;
}
