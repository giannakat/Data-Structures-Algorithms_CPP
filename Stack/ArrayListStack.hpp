#include "Stack.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class ArrayListStack : public Stack{
    int _size;
    int capacity;
    int* array;

    void increaseCap(){
        if(_size == capacity){
            capacity = ceil(capacity*2.0/3);
            int* newArr = (int*)realloc(array, capacity*sizeof(int));
            array = newArr;
        }
    }

    void decreaseCap(){
        if(_size < capacity*.75){
            capacity = floor(capacity*2.0/3);
            int* newArr = (int*)realloc(array, capacity*sizeof(int));
            array = newArr;
        }
    }

    public:

    ArrayListStack(){
        _size = 0;
        capacity = 5;
        array = (int*)malloc(capacity*sizeof(int));
    }

    void push(int n){

        if(_size == capacity){
            increaseCap();
        }

        array[_size++] = n;
    }

    int pop(){
        if(_size == 0){
            throw logic_error("Cannot remove from empty stack");
        }
        int temp = array[_size-1];
        _size--;
        decreaseCap();

        return temp;
    }

    int top(){
        if(_size == 0){
            throw logic_error("Cannot retrieve from empty stack");
        }
        return array[_size-1];
    }

    int size(){
        return _size;
    }

    bool isEmpty(){
        return _size == 0;
    }
};