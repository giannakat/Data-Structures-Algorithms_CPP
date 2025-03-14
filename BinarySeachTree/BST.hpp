#include<iostream>
#include"binarysearch.hpp"
using namespace std;

class BST : public binarysearch{

    private:

    struct Node
    {
        /* data */
        int data;
        Node* left;
        Node* right;      
        Node(int value): data(value), left(nullptr), right(nullptr){} 
    };


    Node* root=nullptr;

    Node* addNode(Node* node, int value){
        if(node == nullptr){
            return new Node(value);
        }

        if(value < node->data){
            node->left = addNode(node->left, value);
        }else if(value > node->data){
            node->right = addNode(node->right, value);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* removeNode(Node* node, int value, bool& removed){
        if(node == nullptr) return nullptr;

        if(value < node->data){
            node->left = removeNode(node->left, value, removed);
        }else if(value > node->data){
            node->right = removeNode(node->right, value, removed);
        }else{
            removed = true;
            if(node->left == nullptr){
                Node* temp = node->right;
                delete node;
                return temp;
            }else if(node->right == nullptr){
                Node* temp = node->left;
                delete node;
                return temp;
            }   
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data, removed);
        }
        return node;
    }

    Node* searchNode(Node* node, int value){
        if(node == nullptr || node->data == value){
            return node;
        }
        if(value < node->data){
            return searchNode(node->left, value);
        }
        return searchNode(node->right, value);
    }

    void printInOrder(Node* node) {
        if (node == nullptr) return;
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }

    public:
    BST() : root(nullptr) {}

    void add(int value) {
        root = addNode(root, value);
    }

    int remove(int value){
        bool removed = false;
        root = removeNode(root, value, removed);
        return removed ? value : -1; // Return -1 if value not found
    }

    int search(int value){
        return searchNode(root, value) ? value : -1;
    }

    void print()  {
        printInOrder(root);
        cout << endl;
    }

    ~BST() {
        while (root != nullptr) {
            remove(root->data);
        }
    }

};