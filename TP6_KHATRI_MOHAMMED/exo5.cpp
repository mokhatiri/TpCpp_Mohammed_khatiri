// Implimenting a LRU cache with shared_ptr and weak_ptr
#include <iostream>
#include <memory>
#include <unordered_map>

using namespace std;

// the objective:
/*
- impliment a LRU cache using shared_ptr to manage ressources
- use weak_ptr to avoid cycles
- put in place a politique of evicting the least recently used item

output:

Acces aux cles : 1 2 3 1 4
Cache actuel :
4 1 3 2

Acces a la cle 5 -> eviction de la cle 2
Cache actuel :
5 4 1 3
*/

// implimenting using a double linked list

struct Node {
    int key, value;
    shared_ptr<Node> next; // using a shared ptr to be able to point to the same node even in the Unordered map. 
    weak_ptr<Node> prev;  // i am using weak ptr to avoid cycles (so that no two shared ptrs point to the same node)

    Node(int k, int v) : key(k), value(v), next(nullptr) {} // constructor
};

struct LRUCache {
    size_t capacity; // max capacity defined at construction
    unordered_map<int, shared_ptr<Node>> cache; // using an unordered map to store the key, pointer pair to the node
    shared_ptr<Node> head, tail;

    LRUCache(size_t cap) : capacity(cap), head(nullptr), tail(nullptr) {} // constructor

    void moveToHead(shared_ptr<Node> node) {
        /*
            the point of this function is to move the node to the head of the list
            -> gonna be called when a node is accessed
        */

        if (node == head) return;

        if (auto prevNode = node->prev.lock()) {
            // use .lock() because we are using a weak ptr
            prevNode->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        if (node == tail) {
            tail = node->prev.lock();
        }

        node->prev.reset(); // reset the weak ptr
        node->next = head; // set the next node to the head
        if (head) head->prev = node; // set the prev node to the node
        head = node; // set the head to the node

        if (!tail) tail = head; // if the tail is null, set the tail to the head
    }

    void evict() {
        /*
            function to evict the least recently used item
            -> gonna be called when the cache is full
        */
        
        if (!tail) return;

        cache.erase(tail->key);
        if (auto prevTail = tail->prev.lock()) {
            tail = prevTail; // set the tail to the previous node
            tail->next = nullptr; // set the next node to null
        } else {
            head = tail = nullptr; // if the tail is null, set the head and tail to null
        }
    }

    void access(int key, int value) {
        /*
            function to access a key
        */

        if (cache.find(key) != cache.end()) {
            // if the key is in the cache, move the node to the head
            shared_ptr<Node> node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // if the key is not in the cache, add the key to the cache (the new head)

            shared_ptr<Node> newNode = make_shared<Node>(key, value);
            if (cache.size() >= capacity) { 
            // if the cache is full, evict the least recently used item
                evict();
            }

            // add the key to the cache and move the node to the head
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;

            // if the tail is null, set the tail to the head
            if (!tail) tail = head;

            // add the key to the cache unordered map
            cache[key] = newNode;
        }
    }

    void printCache() {
        /*
            function to print the cache
        */

        shared_ptr<Node> current = head;
        cout << "Cache actuel : " << endl;
        while (current) {
            cout << current->key << " ";
            current = current->next; // move to the next node
        }
        cout << endl;
    }
};

int main() {

    // make an LRUcache with a capacity of 4 called lru
    LRUCache lru (4);

    cout << "Accets aux cles : 1 2 3 1 4" << endl;
    lru.access(1, 10);
    lru.access(2, 20);
    lru.access(3, 30);
    lru.access(1, 10);
    lru.access(4, 40);
    lru.printCache();
    cout << endl;

    cout << "Acces a la cle 5 -> eviction de la cle 2" << endl;
    lru.access(5, 50);
    lru.printCache();

    return 0;
}
