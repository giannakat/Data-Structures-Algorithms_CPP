#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}

    int Height()
};

// Function to get the height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor
int getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Update height of a node
void updateHeight(Node* node) {
    if (node)
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right Rotate (LL Rotation)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x; // New root
}

// Left Rotate (RR Rotation)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y; // New root
}

// Insert a node into AVL Tree
Node* insert(Node* root, int key) {
    // Perform normal BST insertion
    if (!root) return new Node(key);
    
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys not allowed

    // Update height of the node
    updateHeight(root);

    // Get the balance factor
    int balance = getBalanceFactor(root);

    // Perform rotations if unbalanced

    // Case 1: Left-Left (LL Rotation)
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Case 2: Right-Right (RR Rotation)
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Case 3: Left-Right (LR Rotation)
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right-Left (RL Rotation)
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal (sorted order)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver Code
int main() {
    Node* root = nullptr;

    // Insert elements into AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder Traversal (Sorted Order): ";
    inorder(root);
    cout << endl;

    return 0;
}
