#include "Sortable.hpp"

class SelectionSort:public Sortable{

    public:
    void Sort(int arr[], int size){
        int min = arr[0];
        int temp;

        for(int i = 0; i < size; i++){  
            min = i;
            for(int j = i; j < size; j++){
                if(arr[min] > arr[i]){
                    arr[min] = arr[i];
                }
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }


    }
};