#include<iostream>
#include "arrayList.hpp"
using namespace std;

int main(){
    List* myArray = new ArrayList();
    int num, pos, res;
    char op;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch(op){
            case 'a':
                cin >> num;
                myArray->add(num);
                break;
            case 'A':
                cin >> num >> pos;
                myArray->addAt(num, pos);
                break;
            case 'r':
                cin >> num;
                res = myArray->remove(num);
                if(res == 0){
                    cout << "Number not found!" << endl;
                }
                break;
            case 'R':
                cin >> num >> pos;
                cout << "Removed " << myArray->removeAt(pos) << "from the list" << endl;
                break;
            case 'p':
                myArray->print();
                break;
            case 's':
                cout << "size: " << myArray->size_() << endl;
                break;
            case 'x':
                cout << "Exiting";
                break;
                
            default:
                cout << "Invalid operation! " << endl;
        }
    }while(op != 'x');


    return 0;
}