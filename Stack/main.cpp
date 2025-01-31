#include<iostream>
#include<stdexcept>
#include"ArrayListStack.hpp"

using namespace std;


int main(){

    ArrayListStack* stack = new ArrayListStack();
    char op;
    int num;

    while(true){
        cout << "Op: ";
        cin >> op;

        try{
        switch(op){
            case 'p':
                cin >> num;
                stack->push(num);
                break;
            case 'o':
                cout << "Popped " << stack->pop() << " from the stack." << endl;
                break;
            case 't':
                cout << "Top: " << stack->top() << endl;
                break;
            case 's':
                cout << "Size: " << stack->size() <<endl;
                break;
            case 'i':
                if(stack->isEmpty()){
                    cout << "The stack is empty";
                }else cout << "The stack is not empty";
                break;
            case 'x':
                cout << "exiting";
            default:
                cout << "nothing";

        }
        }catch(exception& e){
            cout << e.what() << endl;
        }

   }



    return 0;
}