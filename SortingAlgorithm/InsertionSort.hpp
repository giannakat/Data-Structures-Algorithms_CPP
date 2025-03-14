#include"Sortable.hpp"
#include<iostream>
using namespace std;

class InsertionSort:public Sortable{

    public:
    void sort(int arr[], int size){

        //3 2 1
        //
        for(int i = 1; i < size; i++){
            int temp = arr[i];
            int j = i-1;

            while(temp<arr[j] && j>=0){
                arr[j+1] = arr[j];      
                j--;
            }

            arr[j + 1] = temp;
        }

        
    }
};