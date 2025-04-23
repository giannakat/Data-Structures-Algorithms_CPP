struct Node{
    int val;
    Node* parent;
    Node* left;
    Node* right
    
    int height(){
        int leftHeight = (left != nullptr) ? left->height() : -1;
        int rightHeight = (right != nullptr) ? right->height() : -1;
        return 1 + max(leftHeight, rightHeight);
    }

}

Node* zigLeft(Node* z){
    Node* y = z->right;
    z->right = y->left;
    if(y->left){
        y->left->parent = z;
    }
    y->left = z;

    y->parent = z->parent;
    z->parent = y;
}

Node* zigRight(Node* z){
    Node* y = z->left;
    z->left = y->right;
    if(y->right){
        y->right->parent = z;
    }
    y->right = z;

    y->parent = z->parent;
    z->parent = y;
}

Node* restructure(Node* grand){
    //the parent will be the child with greater height
    Node* parent = (grand->left->height() > grand->right->height()) ? grand->left : grand->right; 
    Node* child;


      0
    0
    //find child with greater height
    if(parent == grand->left){
        child = (parent->left && (!parent->right || parent->left->height() >= parent->right->height())) ? parent->left : parent->right;
    }else{
        child = (parent->right && (!parent->left || parent->right->height >= parent->left->height())) ? parent->right : parent->left;
    }

    if(parent == grand->left && child == parent->left){
        cout << "ZIGRIGHT";
        return zigRight(grand);
    }else if(parent == grand->right && child == parent->right){
        cout << "ZIGLEFT"
        return zigLeft(grand);
    }else if(parent == grand->left && child == parent->right){
        cout << "ZIGZAGRIGHT";
        zigLeft(parent);
        return zigRight(grand);
    }else if(parent == grand->right && child == parent->left){
        cout << "ZIGSAGLEFT"
        zigRight(parent);
        return zigLeft(grand);
    }

    return grand;
}

void rebalance(Node* node){
    while(node != nullptr){
        int balance = getBalanceFactor(node);
        if(abs(balance) > 1){
            restructure(node);
        }
        node->parent;
    }
}

int getBalanceFactor(Node* node){
    int leftHeight = (node->left != nullptr) ? node->left->height() : -1;
    int rightHeight = (node->right != nullptr) ? node->right->height() : -1;
    return leftHeight - rightHeight;
}