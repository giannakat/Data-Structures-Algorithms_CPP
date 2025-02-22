#include<stdio.h>
#include"htlinear.hpp"
using namespace std;


int main(){
    int N = 5;
    HashTable<int> *ht = new HTLinear<int>(N);

    char op;
    int key;

    do{
        try
        {
            cout << "Operation: ";
            cin >> op;

            switch(op){
                case 'i':
                    cin >> key;
                    cout << ht->insert(key) << endl;
                    break;

                case 's':
                    cin >> key;
                    cout << ht->search(key) << endl;
                    break;

                case 'r':
                    cin >> key;
                    cout << ht->remove(key) << endl;
                    break;
                    
                case 'p':
                    ht->print();
                    break;

                case 'x':
                    cout << "exiting...";
                    break;
                default:
                    cout << "Invalid operation" << endl;
                
            }

        }catch(exception& e){
           cout << e.what() << '\n';
        }
        
    }while(op != 'x');

}