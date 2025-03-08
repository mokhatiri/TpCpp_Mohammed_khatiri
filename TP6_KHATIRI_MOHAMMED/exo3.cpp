// gestion d'un arbre binaire de recherche
/*
warning: this is not a self balancing BST;
for example in the case of adding the nodes 1, 2, 3, ... ,9
this will cause a highly unbalanced BST, with lookup similar to a simple linked list.
1 -> 2 -> ... -> 9 (very bad)
*/

#include <iostream>


using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

struct BST{
    Node* root;

    BST(){
        root = nullptr;
    }

    // implimenting insertion, reseach, deletion
    
    // first insertion: it's done by checking the value comparing it to the root value
    // then the left (if smaller) or right child (if bigger) is checked the same way
    // repeat until the value is found or a nullptr is found
    // then the new node is inserted
    void insert(int val){
        Node* newNode = new Node;
        newNode->val = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if(root == nullptr){
            root = newNode;
        }

        else{
            Node* current = root;
            while(true){
                if(val < current->val){
                    if(current->left == nullptr){
                        current->left = newNode; // put it to the left
                        break;
                    }
                    else{
                        current = current->left;
                    }
                }
                else{
                    if(current->right == nullptr){
                        current->right = newNode; // put it to the right
                        break;
                    }
                    else{
                        current = current->right;
                    }
                }
            }
        }
    }

    // next is research: it's done by checking the value comparing it to the root value
    // then the left (if smaller) or right child (if bigger) is checked the same way
    // repeat until the value is found or a nullptr is found
    void search(int val){
        Node* current = root;

        while(current != nullptr){
            if(val == current->val){
                cout << "Trouvé" << endl;
                return;
            }
            else if(val < current->val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        cout << "Non trouvé" << endl;
    }

    // deletion: it's done by checking the value comparing it to the root value
    // then the left (if smaller) or right child (if bigger) is checked the same way
    // repeat until the value is found or a nullptr is found
    // then the node is deleted wich is done by saving the parent
    void deleteNode(int val){
        Node* current = root;
        Node* parent = nullptr;

        while(current != nullptr){

            if(val == current->val){
                cout << "Suppression de " << current->val << endl;
                if(current->left == nullptr && current->right == nullptr){
                    // the case where the node has no children
                    if(parent->left == current) parent->left = nullptr;
                    else parent->right = nullptr;
                    delete current; // free the memory
                }
                else if(current->left == nullptr){
                    // the case where the node has only a right child
                    if(parent->left == current) parent->left = current->right;
                    else parent->right = current->right;
                    delete current; // free the memory once found
                }
                else if(current->right == nullptr){
                    // the case where the node has only a left child
                    if(parent->left == current) parent->left = current->left;
                    else parent->right = current->left;
                    delete current; // again
                }
                else{
                    // the case where he has both
                    Node* temp = current->right;
                    Node* tempParent = current; 

                    while(temp->left != nullptr){
                        tempParent = temp;
                        temp = temp->left;
                    } // keep going untill the next value is nullptr, and add the whole left tree to that node
                    
                    if(temp->right != nullptr){
                        // in case the node has a right child, point it to the left of the parent; the structure is kept
                        tempParent->left = temp->right;
                        tempParent = nullptr; // free this ptr as it has no further use;
                    }
                    // next put the temp at the place of the node of interest.
                    temp->right = current->right;
                    temp->left = current->left;
                    if(parent->left == current) parent->left = temp;
                    else parent->right = temp;
                    delete current;
                }
                current = nullptr;
                return;
            }
            else if(val < current->val){
                parent = current;
                current = current->left;
            }
            else{
                parent = current;
                current = current->right;
            }
        }
        cerr << "Value not found" << endl;
    };


    void inOrderTraversal(){
        _inOrderTraversal(root);
        cout << endl;
    }

    void _inOrderTraversal(Node* node){
        if(node == nullptr) return;
        _inOrderTraversal(node->left);
        cout << node->val << " ";
        _inOrderTraversal(node->right);
    }

    void _deleteTree(Node* node){
        if(node == nullptr) return;
        _deleteTree(node->left);
        _deleteTree(node->right);
        delete node;
    }

    ~BST(){
    // delete the tree
    _deleteTree(root);
    }
};

int main(){

    BST tree;

    cout << "Insertion des éléments : ";
    // let's fill with 5, 3, 7, 2, 4, 6, 8
    tree.insert(5);
    cout << "5 ";
    tree.insert(3);
    cout << "3 ";
    tree.insert(7);
    cout << "7 ";
    tree.insert(2);
    cout << "2 ";
    tree.insert(4);
    cout << "4 ";
    tree.insert(6);
    cout << "6 ";
    tree.insert(8);
    cout << "8 " << endl << endl;

    // parcours infixe
    cout << "Parcours infixe : " << endl;
    tree.inOrderTraversal();
    cout << endl;

    //recherche de 4:
    cout << "Recherche de 4 : ";
    tree.search(4);

    // suppression de 4
    tree.deleteNode(4);

    // parcours infixe
    cout << "Parcours infixe après suppression: ";
    tree.inOrderTraversal();
}