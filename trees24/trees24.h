#include "Node.h"

class Tree24 {
    Node* root;
    int size;
public:
    Tree24();
    Node* search(int num);
    Node* insert(int num);
    void print();
};