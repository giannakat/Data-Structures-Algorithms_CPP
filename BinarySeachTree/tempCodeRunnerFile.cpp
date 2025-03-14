#include <iostream>
#include"BST.hpp"
#include "binarysearch.hpp"
using namespace std;

int main(){

    binarysearch* tree = new BST();
    char op;

    while(op!='x'){
        cout << "Enter op: ";
        cin >> op;

        switch(op){
            case 'a':
                break;
            case 'd':
                break;
            case 's':
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