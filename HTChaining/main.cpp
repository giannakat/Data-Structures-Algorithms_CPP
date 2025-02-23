#include<iostream>
#include "htchaining.hpp"
using namespace std;

int main(){
    
    int size;
    char op;
    string key;
    HashTable *ht = new HTChaining(5);

    do{
        try
        {
            cout << "Operation: ";
            cin >> op;

            switch(op){
                case 'i':
                    cin >> key;
                    cout << ht->insert(key);
                    break;
                case 's':
                    cin >> key;
                    cout << ht->search(key);
                    break;
                case 'r':
                    cin >> key;
                    cout << ht->remove(key);
                    break;
                case 'p':
                
                    ht->print();
                    break;
                case 'x':
                    cout << "exiting...";
                    break;
                default:
                    cout << "Invalid operation!";
            }
           
        }catch(exception& e){
            cout << e.what() << '\n';
        }
        
    }while(op != 'x');

    return 0;
}