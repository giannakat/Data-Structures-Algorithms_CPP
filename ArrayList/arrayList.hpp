#include<iostream>
#include<cstdlib>
#include<math.h>
#include "list.hpp"
using namespace std;

class ArrayList : public List{
    int* array;
    int size;
    int capacity;


    void expand_size(){
        capacity = ceil(capacity * 1.5);
        int* newArr = (int*) realloc (array, sizeof(int)*capacity);
        array = newArr;
    }

    void deduce_size(){
        capacity = ceil(capacity*0.75);
        int* newArr = (int*)realloc(array,capacity*sizeof(int));
        array = newArr;
    }


    public:

    ArrayList(){
        capacity = 5;
        array = (int*)malloc(capacity*sizeof(int));
        size = 0;
    }

    
    void add(int num){
        if(size >= capacity){
            expand_size();
        }

        array[size++] = num;
    }

    int get(int pos){
        if(pos > size || pos < 1){
            throw logic_error("Invalid position");
        }

        return array[pos-1];
    }

    int remove(int num){
    
        for(int i = 0; i < size ; i++){
            if(array[i] == num){
                int temp = num;
                for(int j = i; j < size-1; j++){
                    array[j] = array[j+1];
                }
                size--;
                if(size > capacity*0.75){
                    deduce_size();
                }
                return temp;
            }
        }
        return -1;
    }

    int size_(){
        return size;
    }


    void print(){
        int i;
        for(i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        for(; i < capacity; i++){
            cout << "? ";
        }
    }

    // void addAt(int num, int pos){
    //     if(pos > size+1 || pos <= 0){
    //         throw logic_error("Invalid position");
    //     }
        
    //     for(int i = size; i >= pos; i--){
    //         array[i] = array[i-1];
    //     }
    //     array[pos-1] = num;
    //     size++;
    //     if(size == capacity){
    //         expand_size();
    //     }
        
    // }

        void addAt(int num, int pos) {
        // Ensure position is valid (can add at size + 1 to append at the end)
        if (pos < 1 || pos > size + 1) {
            throw logic_error("Invalid position");
        }

        // Expand size if capacity is reached
        if (size >= capacity) {
            expand_size();
        }

        // Shift elements to the right starting from the last element
        for (int i = size; i >= pos; i--) {
            array[i] = array[i - 1];
        }

        // Insert the new element
        array[pos - 1] = num;

        // Increment size
        size++;
    }


    int removeAt(int pos){
        
        if(pos > size || pos <= 0){
            throw logic_error("Invalid position");
        }

        int temp = array[pos-1];

        for(int i = pos-1; i < size-1; i++){
            array[i] = array[i+1];
        }
        size--;

        if(size < capacity *0.75){
            deduce_size();
        }
        
        return temp;
    }

    

};