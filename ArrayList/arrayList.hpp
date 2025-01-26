#include<iostream>
#include<cstdlib>
#include<math.h>
#include "list.hpp"
using namespace std;

class ArrayList : public List{
    int* array;
    int size;
    int capacity;

    //T(n) = 7
    void expand_size(){
        capacity = ceil(capacity * 1.5); //3
        int* newArr = (int*) realloc (array, sizeof(int)*capacity); //3
        array = newArr; //1
    }

    //T(n) = 7
    void deduce_size(){
        capacity = ceil(capacity*0.75); //3
        int* newArr = (int*)realloc(array,capacity*sizeof(int)); //3
        array = newArr; //1
    }


    public:

    //T(n) = 4
    ArrayList(){
        capacity = 5;
        array = (int*)malloc(capacity*sizeof(int));
        size = 0;
    }

    // T(n) = 10
    void add(int num){
        if(size >= capacity){ //1
            expand_size(); //7
        }

        array[size++] = num; //2
    }

    //T(n) = 2
    int get(int pos){
        if(pos > size || pos < 1){ //1
            throw logic_error("Invalid position");
        }

        return array[pos-1]; //2
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
        for(i = 0; i < size; i++){ // 1, s+1, s
            cout << array[i] << " "; //s
        }
        for(; i < capacity; i++){  // c - s + 1 , c - s
            cout << "? ";
        }

        cout << endl;
    }

        //T(n) = 4(s - pos) + 16
        void addAt(int num, int pos) {
        // Ensure position is valid (can add at size + 1 to append at the end)
        if (pos < 1 || pos > size + 1) { //3
            throw logic_error("Invalid position");
        }

        // Expand size if capacity is reached
        if (size >= capacity) { //8
            expand_size();
        }

        // Shift elements to the right starting from the last element
        //4(s - pos) + 2
        for (int i = size; i >= pos; i--) { // 1, s+1 - pos, s-pos
            array[i] = array[i - 1]; // s - pos, s - pos
        }

        // Insert the new element
        array[pos - 1] = num; //2

        // Increment size
        size++; //1
    }

    //T(n) = 2s - 2pos + 17
    int removeAt(int pos){

        if(pos > size || pos <= 0){ // 3
            throw logic_error("Invalid position");
        }

        int temp = array[pos-1]; //2

        //pos - 1 will be the starting array position we just overwrite
        //we set the limit to i < size-1 or essentially until size - 2
        //to avoid out of bounds when we get array[i+1] which is still within the array bounds
        for(int i = pos-1; i < size-1; i++){ // 1, s-pos + 1, s-pos
            array[i] = array[i+1];   //s - pos, s - pos
        }
        size--; //1

        if(size < capacity *0.75){ //1
            deduce_size(); //7
        }
        
        return temp;
    }

    

};