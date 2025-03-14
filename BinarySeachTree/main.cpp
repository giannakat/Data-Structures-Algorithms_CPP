#include <iostream>
#include"BST.hpp"
using namespace std;

int main(){

    binarysearch* tree = new BST();
    char op = ' ';
    int num;

    while(op!='x'){
        cout << "Enter op: ";
        cin >> op;

        switch(op){
            case 'a':
                cin >> num;
                tree->add(num);
                break;
            case 'd':
                cin >> num;
                tree->remove(num);
                break;
            case 's':
                cin >> num;
                cout << tree->search(num);
                break;
            case 'p':
                tree->print();
                break;
            case 'x':
                cout << "exiting...";
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }
    }
    return 0;
}